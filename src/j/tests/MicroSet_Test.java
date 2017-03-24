package j.tests;


import j.implementation.TestObject;
import j.implementation.microSet.MicroSet;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;


public class MicroSet_Test {

    MicroSet<TestObject> microSet;
    TestObject testObject = new TestObject(1);

    @BeforeEach
    void setUp() {
        microSet = new MicroSet<>();
        microSet.add(testObject);
    }

    @Test
    void test_addElement_Already_in() {
        boolean res = microSet.add(testObject);
        assertFalse(res);
    }

    @Test
    void test_addElement(){
        boolean res2 = microSet.add(new TestObject(2));
        assertTrue(res2);
    }

    @Test
    void test_removeElement_Not_in_Microset() {
        boolean res = microSet.remove(new TestObject(1));
        assertFalse(res);
    }

    @Test
    void test_removeElement(){
        boolean res2 = microSet.remove(testObject);
        assertTrue(res2);
    }

    @Test
    void test_contains_wrongElem() {
        boolean res = microSet.contains(new TestObject(1));
        assertFalse(res);
    }

    @Test
    void test_contains_goodElem(){
        boolean res2 = microSet.contains(testObject);
        assertTrue(res2);
    }

    @Test
    void clear() {
        microSet.clear();
        assertFalse(microSet.contains(testObject));
    }

    @Test
    void isEmpty(){
        assertFalse(microSet.isEmpty());
    }

    @Test
    void size(){
        assertEquals(microSet.size(),1);
    }

    @Test
    void addAllElements() {

        MicroSet<TestObject> microSetAdd = new MicroSet<>();
        TestObject testObject2 = new TestObject(2);
        TestObject testObject3 = new TestObject(3);
        microSetAdd.add(testObject2);
        microSetAdd.add(testObject3);

        assertEquals(microSet.size(),1);
        microSet.addAll(microSetAdd);
        assertEquals(microSet.size(),3);

    }

    @Test
    void removeAllElements() {

        TestObject testObject2 = new TestObject(2);
        TestObject testObject3 = new TestObject(3);
        //MicroSetRemove contains [testObject2 , testObject]
        MicroSet<TestObject> microSetRemove = new MicroSet<>();
        microSetRemove.add(testObject2);
        microSetRemove.add(testObject);

        //MicroSet contains [testObject, testObject2, testObject3]
        microSet.add(testObject2);
        microSet.add(testObject3);

        assertEquals(microSet.size(),3);
        microSet.removeAll(microSetRemove);
        assertEquals(microSet.size(),1);

        //MicroSet contains [testObject3]

    }

    @Test
    void retainAllElements() {

        TestObject testObject2 = new TestObject(2);
        TestObject testObject3 = new TestObject(3);

        //MicroSetRetain contains [testObject2 , testObject]
        MicroSet<TestObject> microSetRetain = new MicroSet<>();
        microSetRetain.add(testObject2);
        microSetRetain.add(testObject);

        //MicroSet contains [testObject, testObject3]
        microSet.add(testObject3);

        assertEquals(microSet.size(),2);
        microSet.retainAll(microSetRetain);
        assertEquals(microSet.size(),1);

        //MicroSet contains [testObject]

    }

    @Test
    void containsAllElements() {

        TestObject testObject2 = new TestObject(2);
        TestObject testObject3 = new TestObject(3);

        //MicroSetRetain contains [testObject2 , testObject]
        MicroSet<TestObject> microSetContains = new MicroSet<>();
        microSetContains.add(testObject2);
        microSetContains.add(testObject);

        //MicroSet contains [testObject, testObject2, testObject3]
        microSet.add(testObject2);
        microSet.add(testObject3);

        assertTrue(microSet.containsAll(microSetContains));
    }
    void toArray(){
        //Todo
    }

}
