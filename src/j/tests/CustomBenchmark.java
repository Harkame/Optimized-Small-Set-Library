package j.tests;

import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/**
 * Created by fly on 13/04/17.
 */
public class CustomBenchmark
{
    private static final long MEGABYTE = 1024L * 1024L;
    private static final int POOL_SIZE = 50000;

    public static long bytesToMegabytes(long bytes) {
        return bytes / MEGABYTE;
    }

    public static int randomBetween(int low, int max) {
        Random random = new Random();
        return random.nextInt(max-low) + low;
    }

    public static ArrayList<ArrayList<TestObject>> setup() {
        ArrayList<ArrayList<TestObject>> arrayList = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < POOL_SIZE; i++) {
            int numberOfObject;
            ArrayList<TestObject> a = new ArrayList<>();

            if (i < POOL_SIZE * 0.8) {
                numberOfObject = randomBetween(1,8);
                for (int j = 0; j < numberOfObject; j++) {
                    a.add(new TestObject(random.nextInt()));
                }
                arrayList.add(a);
            } else if (i < POOL_SIZE * 0.9) {
                numberOfObject = randomBetween(10, 100);
                for (int j = 0; j < numberOfObject; j++) {
                    a.add(new TestObject(random.nextInt()));
                }
                arrayList.add(a);
            } else {
                numberOfObject = randomBetween(100, 1000);
                for (int j = 0; j < numberOfObject; j++) {
                    a.add(new TestObject(random.nextInt()));
                }
                arrayList.add(a);
            }
        }
        //Collections.shuffle(arrayList);
        return arrayList;
    }

    public static void oneRun(MicroSet.Use use, ArrayList<ArrayList<TestObject>> arrayLists) {
        ArrayList<MicroSet<TestObject>> arrayList = new ArrayList<>();
        for (int i = 0; i < POOL_SIZE; i++) {
            MicroSet<TestObject> m = new MicroSet<>(use);
            ArrayList<TestObject> a = arrayLists.get(i);
            m.addAll(a);
            arrayList.add(m);
        }

        Runtime runtime = Runtime.getRuntime();
        runtime.gc();// Run the garbage collector
        long startTime = System.nanoTime();
        // START TEST
        for (int i=0; i< POOL_SIZE -1; i++) {
            arrayList.set(i + 1, arrayList.get(i).addAllAndPropagate(arrayList.get(i + 1)));
        }
        // END TEST

        long stopTime = System.nanoTime();
        long elapsedTime = stopTime - startTime;
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Elapsed Time is: " + elapsedTime + "ns (" + elapsedTime / 1000L + " ms)");
        System.out.println("Used memory is: " + memory + "bytes (" + bytesToMegabytes(memory) + " Mbytes)");
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<TestObject>> arrayLists = setup();
        System.out.println("====== INNER_SET ======");
        oneRun(MicroSet.Use.INNER_SET, arrayLists);
        System.out.println("====== ARRAY_SET ======");
        oneRun(MicroSet.Use.ARRAY_SET, arrayLists);
        System.out.println("====== HASH_SET ======");
        oneRun(MicroSet.Use.HASH_SET, arrayLists);
    }
}
