package j.tests;


import com.google.caliper.BeforeExperiment;
import com.google.caliper.Benchmark;
import com.google.caliper.api.VmOptions;
import com.google.caliper.runner.CaliperMain;
import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;
import j.implementation.microSet.InnerArraySet;

import java.util.HashSet;
import java.util.Random;
import java.util.TreeSet;

@VmOptions("-XX:-TieredCompilation")
public class MicroSet_Benchmark_Add {

    public static final int NUMBER_OF_TEST_OBJECT = 10;

    MicroSet<TestObject> microSet = new MicroSet<>();
    HashSet<TestObject> hashSet = new HashSet<>();
    TreeSet<TestObject> treeSet = new TreeSet<>();

    TestObject[] testObjects = new TestObject[NUMBER_OF_TEST_OBJECT];
    int[] randomInt = new int[NUMBER_OF_TEST_OBJECT];

    @BeforeExperiment
    void setUp() {
        Random random = new Random();
        for (int i = 0; i < NUMBER_OF_TEST_OBJECT; i++) {
            testObjects[i] = new TestObject(random.nextInt());
        }
        for (int i = 0; i < NUMBER_OF_TEST_OBJECT; i++) {
            randomInt[i] = random.nextInt(NUMBER_OF_TEST_OBJECT);
        }
    }


    @Benchmark
    public void testAdd_TreeSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                treeSet.add(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testAdd_HashSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                hashSet.add(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testAdd_MicroSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microSet.add(testObjects[randomInt[j]]);
            }
        }
    }

    public static void main(String[] args) {
        args = new String[]{ "-i", "runtime" };
        CaliperMain.main(MicroSet_Benchmark_Add.class, args);
    }
}
