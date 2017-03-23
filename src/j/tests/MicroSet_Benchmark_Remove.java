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
public class MicroSet_Benchmark_Remove {

    private static int NUMBER_OF_TEST_OBJECT = 30;

    MicroSet<TestObject> microInnerSet = new MicroSet<>(MicroSet.Use.INNER_SET, NUMBER_OF_TEST_OBJECT);
    MicroSet<TestObject> microArraySet = new MicroSet<>(MicroSet.Use.ARRAY_SET, NUMBER_OF_TEST_OBJECT);
    MicroSet<TestObject> microHashSet = new MicroSet<>(MicroSet.Use.HASH_SET, NUMBER_OF_TEST_OBJECT);
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
    public void testRemove_HashSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT/4; j++) {
                hashSet.remove(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testRemove_TreeSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT/4; j++) {
                treeSet.remove(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testRemove_MicroArraySet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microArraySet.remove(testObjects[randomInt[j]]);
            }
        }
    }

    @Benchmark
    public void testRemove_MicroHashSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microHashSet.remove(testObjects[randomInt[j]]);
            }
        }
    }
    @Benchmark
    public void testRemove_MicroInnerSet(int reps) {
        for (int i = 0; i < reps; i++) {
            for (int j = 0; j < NUMBER_OF_TEST_OBJECT; j++) {
                microInnerSet.remove(testObjects[randomInt[j]]);
            }
        }
    }

    public static void main(String[] args) {
        args = new String[]{ "-i", "runtime", "-r", "REMOVE scale=" + NUMBER_OF_TEST_OBJECT + ", object_number=" + NUMBER_OF_TEST_OBJECT};
        CaliperMain.main(MicroSet_Benchmark_Remove.class, args);
    }
}
