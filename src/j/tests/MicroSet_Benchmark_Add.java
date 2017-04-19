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

    public static final int NUMBER_OF_TEST_OBJECT = 30;

    MicroSet<TestObject> microInnerSet = new MicroSet<>(MicroSet.Use.INNER_SET);
    MicroSet<TestObject> microArraySet = new MicroSet<>(MicroSet.Use.ARRAY_SET);
    MicroSet<TestObject> microHashSet = new MicroSet<>(MicroSet.Use.HASH_SET);
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
    public void testAdd_MicroHashSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microHashSet.add(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testAdd_MicroArraySet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microArraySet.add(testObjects[randomInt[j]]);
            }
        }
    }
    @Benchmark
    public void testAdd_MicroInnerSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microInnerSet.add(testObjects[randomInt[j]]);
            }
        }
    }

    public static void main(String[] args) {
        args = new String[]{ "-i", "runtime", "-r", "ADD scale=" + NUMBER_OF_TEST_OBJECT + ", object_number=" + NUMBER_OF_TEST_OBJECT};
        CaliperMain.main(MicroSet_Benchmark_Add.class, args);
    }
}
