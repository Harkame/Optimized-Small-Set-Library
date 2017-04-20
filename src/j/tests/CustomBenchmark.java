package j.tests;

import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by fly on 13/04/17.
 */
public class CustomBenchmark
{
    private static final long MEGABYTE = 1024L * 1024L;
    private static final int POOL_SIZE = 10000;

    public static long bytesToMegabytes(long bytes) {
        return bytes / MEGABYTE;
    }

    public static int randomBetween(int low, int max) {
        Random random = new Random();
        return random.nextInt(max-low) + low;
    }

    public static void main(String[] args) {
        ArrayList<MicroSet> arrayList = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < POOL_SIZE; i++) {
            int numberOfObject;
            MicroSet m = new MicroSet();

            if (i < POOL_SIZE * 0.8) {
                numberOfObject = randomBetween(1,8);
                for (int j = 0; j < numberOfObject; j++) {
                    m.add(new TestObject(random.nextInt()));
                }
                arrayList.add(m);
            } else if (i < POOL_SIZE * 0.9) {
                numberOfObject = randomBetween(10, 100);
                for (int j = 0; j < numberOfObject; j++) {
                    m.add(new TestObject(random.nextInt()));
                }
                arrayList.add(m);
            } else {
                numberOfObject = randomBetween(100, 1000);
                for (int j = 0; j < numberOfObject; j++) {
                    m.add(new TestObject(random.nextInt()));
                }
                arrayList.add(m);
            }
        }

        Runtime runtime = Runtime.getRuntime();
        runtime.gc();// Run the garbage collector
        long startTime = System.currentTimeMillis();

        // START TEST
        for (int i=0; i< POOL_SIZE -1; i++) {
            arrayList.set(i+1, arrayList.get(i).addAllAndPropagate(arrayList.get(i+1)));
        }
        // END TEST

        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Elapsed Time is: " + elapsedTime);
        System.out.println("Used memory is bytes: " + memory);
        System.out.println("Used memory is megabytes: "
                + bytesToMegabytes(memory));
    }
}
