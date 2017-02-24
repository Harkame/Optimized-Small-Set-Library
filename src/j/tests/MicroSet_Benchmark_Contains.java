package j.tests;


import com.google.caliper.BeforeExperiment;
import com.google.caliper.Benchmark;
import com.google.caliper.api.VmOptions;
import com.google.caliper.runner.CaliperMain;
import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;
import j.implementation.microSet.MicroSetFor;

import java.util.HashSet;
import java.util.Random;

@VmOptions("-XX:-TieredCompilation")
public class MicroSet_Benchmark_Contains {

    private int NUMBER_OF_TEST_OBJECT = 10;

    MicroSet<TestObject> microSet = new MicroSet<>();
    HashSet<TestObject> hashSet = new HashSet<>();
    MicroSetFor<TestObject> microSetFor = new MicroSetFor<>();

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
            microSet.add(testObjects[j]);
            microSetFor.add(testObjects[j]);
        }

        for (int i = 0; i < NUMBER_OF_TEST_OBJECT; i++) {
            randomInt[i] = random.nextInt(NUMBER_OF_TEST_OBJECT);
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
    public void testContains_MicroSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microSet.contains(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testContains_MicroSetFor(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microSetFor.contains(testObjects[randomInt[j]]);
            }
        }
    }

    public static void main(String[] args) {
        CaliperMain.main(MicroSet_Benchmark_Contains.class, args);
    }
}
