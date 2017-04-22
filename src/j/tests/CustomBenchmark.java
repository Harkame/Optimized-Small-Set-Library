package j.tests;

import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/**
 * Created by fly on 13/04/17.
 */
public class CustomBenchmark
{
    private static final long MEGABYTE = 1024L * 1024L;
    private static final int POOL_SIZE = 20;
    private static final int STOCK_SIZE = 1000;
    private static final int LISTE_CROISSANTE_SIZE = 10;
    private static final int NOMBRE_TIRAGE = 1000;
    private static Random random = new Random(1);

    public static long bytesToMegabytes(long bytes) {
        return bytes / MEGABYTE;
    }

    public static int randomBetween(int low, int max) {
        return random.nextInt(max-low) + low;
    }

    public static void oneRun(MicroSet.Use use) {
        MicroSet.use = use;
        random = new Random(1);

        ArrayList<TestObject> testObjects = new ArrayList<>();
        for (int i =  0; i< POOL_SIZE; i++) {
            testObjects.add(new TestObject(random.nextInt()));
        }

        int[] randomIndiceListeCroissante = new int[NOMBRE_TIRAGE];
        for (int i =  0; i< NOMBRE_TIRAGE; i++) {
            randomIndiceListeCroissante[i] = randomBetween(0, LISTE_CROISSANTE_SIZE);
        }

        int[] randomIndiceStock = new int[NOMBRE_TIRAGE];
        for (int i =  0; i< NOMBRE_TIRAGE; i++) {
            randomIndiceStock[i] = randomBetween(0, STOCK_SIZE);
        }

        int[] numberOfObject = new int[STOCK_SIZE];
        for (int i =  0; i< STOCK_SIZE; i++) {
            numberOfObject[i] = randomBetween(1,4);
        }

        // Remplie le stock
        ArrayList<MicroSet<TestObject>> stock = new ArrayList<>();
        for (int i = 0; i < STOCK_SIZE; i++) {
            MicroSet<TestObject> microSet = new MicroSet<>();
            for (int j = 0; j < numberOfObject[i]; j++) {
                microSet.add(testObjects.get(randomBetween(0,POOL_SIZE)));
            }
            stock.add(microSet);
        }
        System.out.println(random.nextInt());

        ArrayList<MicroSet<TestObject>> listeCroissante = new ArrayList<>();
        for (int i = 0; i < LISTE_CROISSANTE_SIZE; i++) {
            listeCroissante.add(new MicroSet<>());
        }
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();// Run the garbage collector
        long startTime = System.nanoTime();

        // START TEST
        for (int i=0; i< NOMBRE_TIRAGE; i++) {
            int indice = randomIndiceListeCroissante[i];
            MicroSet<TestObject> increment = stock.get(randomIndiceStock[i]);
            for (int j = indice; j < LISTE_CROISSANTE_SIZE && !increment.isEmpty(); j++) {
                increment = listeCroissante.get(j).addAllAndPropagate(increment);
            }
        }
        // END TEST

        long stopTime = System.nanoTime();
        long elapsedTime = stopTime - startTime;
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Elapsed Time is: " + elapsedTime + "ns (" + elapsedTime / 1000L + " ms)");
        System.out.println("Used memory is: " + memory + "bytes (" + bytesToMegabytes(memory) + " Mbytes)");

        File file = new File(use.toString() + "test.txt");
        try {
            FileWriter writer = new FileWriter(file);
            StringBuilder s = new StringBuilder();
            for (int i =0; i<LISTE_CROISSANTE_SIZE; i++)
                s.append(listeCroissante.get(i).size() + "\n");
            writer.write(s.toString());
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        System.out.println("====== INNER_SET ======");
        oneRun(MicroSet.Use.INNER_SET);
        System.out.println("====== ARRAY_SET ======");
        oneRun(MicroSet.Use.ARRAY_SET);
        System.out.println("====== HASH_SET ======");
        oneRun(MicroSet.Use.HASH_SET);
    }
}
