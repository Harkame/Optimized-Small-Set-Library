package j.tests;


import com.google.caliper.BeforeExperiment;
import com.google.caliper.Benchmark;
import com.google.caliper.api.VmOptions;
import com.google.caliper.model.ArbitraryMeasurement;
import com.google.caliper.model.Measurement;
import com.google.caliper.runner.CaliperMain;
import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;

import java.util.HashSet;
import java.util.Random;
import java.util.TreeSet;

@VmOptions("-XX:-TieredCompilation")
public class MicroSet_Benchmark_Contains {

    private static int NUMBER_OF_TEST_OBJECT = 30;

    MicroSet<TestObject> microInnerSet = new MicroSet<>(MicroSet.Use.INNER_SET);
    MicroSet<TestObject> microArraySet = new MicroSet<>(MicroSet.Use.ARRAY_SET);
    MicroSet<TestObject> microHashSet = new MicroSet<>(MicroSet.Use.HASH_SET);

    HashSet<TestObject> hashSet = new HashSet<>();
    TreeSet<TestObject> treeSet = new TreeSet<>();


    TestObject[] testObjects = new TestObject[NUMBER_OF_TEST_OBJECT];
    int[] randomInt = new int[NUMBER_OF_TEST_OBJECT];

    // Half of the testObject will not be contained
    @BeforeExperiment
    void setUp() {
        Random random = new Random();
        for (int i = 0; i < NUMBER_OF_TEST_OBJECT; i++) {
            testObjects[i] = new TestObject(random.nextInt());
        }

        for (int j = 0; j < NUMBER_OF_TEST_OBJECT /2; j++) {
            hashSet.add(testObjects[j]);
            microArraySet.add(testObjects[j]);
            microHashSet.add(testObjects[j]);
            microInnerSet.add(testObjects[j]);
            treeSet.add(testObjects[j]);
        }

        for (int i = 0; i < NUMBER_OF_TEST_OBJECT; i++) {
            randomInt[i] = random.nextInt(NUMBER_OF_TEST_OBJECT);
        }

    }

    @Benchmark
    public void testContains_TreeSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                treeSet.contains(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testContains_HashSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                hashSet.contains(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testContains_MicroArraySet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microArraySet.contains(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testContains_MicroHashSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microHashSet.contains(testObjects[randomInt[j]]);
            }
        }
    }
    @Benchmark
    public void testContains_MicroInnerSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microInnerSet.contains(testObjects[randomInt[j]]);
            }
        }
    }

    @ArbitraryMeasurement(units = ":1", description = "ratio of uncompressed to compressed")
    public void size() {

    }

    public static void main(String[] args) {
        args = new String[]{ "-i", "runtime", "-r", "CONTAINS scale=" + MicroSet_Benchmark_Add.NUMBER_OF_TEST_OBJECT + ", object_number=" + MicroSet_Benchmark_Add.NUMBER_OF_TEST_OBJECT};

        CaliperMain.main(MicroSet_Benchmark_Contains.class, args);
    }
}
