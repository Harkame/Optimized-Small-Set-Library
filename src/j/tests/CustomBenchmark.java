package j.tests;

import j.implementation.TestObject;
import j.implementation.microSet.AbstractInnerSet;
import j.implementation.microSet.InnerArraySet;
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

    private static int RANDOM_SEED = 1;
    private static int POOL_SIZE = 15;
    private static int STOCK_SIZE = 10;
    private static int LISTE_CROISSANTE_SIZE = 50;
    private static int NOMBRE_TIRAGE = 10;
    private static int ITERATION = 1000;
    private static Random random = new Random(RANDOM_SEED);

    public static long bytesToMegabytes(long bytes) {
        return bytes / MEGABYTE;
    }

    public static int randomBetween(int low, int max) {
        return random.nextInt(max-low) + low;
    }

    public static void oneRun(MicroSet.Use use) {
        MicroSet.use = use;
        random = new Random(RANDOM_SEED);
        MicroSet.appelPropagate = 0;
        ArrayList<TestObject> testObjects = new ArrayList<>();
        for (int i =  0; i< POOL_SIZE; i++) {
            testObjects.add(new TestObject(random.nextInt()));
        }

        int[][] randomIndiceListeCroissante = new int[ITERATION][NOMBRE_TIRAGE];
        int[][] randomIndiceStock = new int[ITERATION][NOMBRE_TIRAGE];

        for (int z = 0; z<ITERATION; z++) {

            for (int i = 0; i < NOMBRE_TIRAGE; i++) {
                randomIndiceListeCroissante[z][i] =randomBetween(0, LISTE_CROISSANTE_SIZE);
            }

            for (int i = 0; i < NOMBRE_TIRAGE; i++) {
                randomIndiceStock[z][i] =randomBetween(0, STOCK_SIZE);
            }
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

        ArrayList<MicroSet<TestObject>> listeCroissante = new ArrayList<>();
        Runtime runtime = Runtime.getRuntime();
        runtime.gc(); // Run the garbage collector
        long startTime = System.nanoTime();

        // START TEST
        for (int zz=0; zz<ITERATION; zz++) {
            listeCroissante = new ArrayList<>();
            for (int i = 0; i < LISTE_CROISSANTE_SIZE; i++) {
                listeCroissante.add(new MicroSet<>());
            }
            for (int i = 0; i < NOMBRE_TIRAGE; i++) {
                int indice = randomIndiceListeCroissante[zz][i];
                MicroSet<TestObject> increment = stock.get(randomIndiceStock[zz][i]);
                //System.out.println(indice + "|" + increment);
                //System.out.println("2: " + listeCroissante.get(2));
                for (int j = indice; j < LISTE_CROISSANTE_SIZE && !increment.isEmpty(); j++) {
                    increment = listeCroissante.get(j).addAllAndPropagate(increment);
                    //System.out.println("listeJ:" + listeCroissante.get(j));
                    //System.out.println("newIncrement:" + increment);
                }
                //for (int k =0; k<LISTE_CROISSANTE_SIZE; k++)
                //   System.out.println(listeCroissante.get(k).size());
                //System.out.println("fin tirage" + i + "\n");
            }
        }
        // END TEST

        long stopTime = System.nanoTime();
        long elapsedTime = stopTime - startTime;
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Elapsed Time is: " + elapsedTime + "ns (" + elapsedTime / 1000L + " micros)");
        System.out.println("Used memory is: " + memory + "bytes (" + bytesToMegabytes(memory) + " Mbytes)");
        System.out.println("Appel Propagate: " + MicroSet.appelPropagate);

        File file = new File(use.toString() + "test.txt");
        try {
            FileWriter writer = new FileWriter(file);
            StringBuilder s = new StringBuilder();
            for (int i = 0; i < LISTE_CROISSANTE_SIZE; i++)
                s.append(listeCroissante.get(i).size() + "\n");
            writer.write(s.toString());
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        if (args.length > 0) {
            RANDOM_SEED = Integer.parseInt(args[1]);
            POOL_SIZE = Integer.parseInt(args[2]);
            STOCK_SIZE = Integer.parseInt(args[3]);
            LISTE_CROISSANTE_SIZE = Integer.parseInt(args[4]);
            NOMBRE_TIRAGE = Integer.parseInt(args[5]);
            ITERATION = Integer.parseInt(args[6]);
            InnerArraySet.MAX_SIZE = Integer.parseInt(args[7]);
            AbstractInnerSet.MAX_SIZE = Integer.parseInt(args[8]);
            switch (args[0]) {
                case "ARRAY":
                    System.out.println("====== ARRAY_SET ======");
                    oneRun(MicroSet.Use.ARRAY_SET);
                    break;
                case "INNER":
                    System.out.println("====== INNER_SET ======");
                    oneRun(MicroSet.Use.INNER_SET);
                    break;
                case "HASH":
                    System.out.println("====== HASH_SET ======");
                    oneRun(MicroSet.Use.HASH_SET);
                    break;
            }
        } else {
            System.out.println("TYPE RANDOM_SEED POOL_SIZE STOCK_SIZE LISTE_CROISSANTE_SIZE NOMBRE_TIRAGE ITERATION ARRAY_MAX_SIZE INNER_MAX_SIZE");
        }
    }
}
