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

    public static void main(String[] args) {
        Random random = new Random();
        ArrayList<MicroSet> arrayList = new ArrayList<>();

        for (int i = 0; i < POOL_SIZE; i++) {
            int numberOfObject;
            MicroSet m = new MicroSet();

            if (i < POOL_SIZE * 0.8) {
                numberOfObject = random.nextInt(8);
                for (int j = 0; j < numberOfObject; j++) {
                    m.add(new TestObject(random.nextInt()));
                }

                arrayList.add(m);
            }

            if (i >= POOL_SIZE * 0.8) {
                numberOfObject = random.nextInt(1000);
                for (int j = 0; j < numberOfObject; j++) {
                    m.add(new TestObject(random.nextInt()));
                }

                arrayList.add(m);
            }
        }

        long startTime = System.currentTimeMillis();


        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;

        // Get the Java runtime
        Runtime runtime = Runtime.getRuntime();
        // Run the garbage collector
        // runtime.gc();
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Elapsed Time is: " + elapsedTime);
        System.out.println("Used memory is bytes: " + memory);
        System.out.println("Used memory is megabytes: "
                + bytesToMegabytes(memory));
    }
}
