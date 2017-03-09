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

    void addAllElements() {
        //ToDo
    }

    void removeAllElements() {
        //ToDo
    }

    void retainAllElements() {
        //Todo
    }

    void containsAllElements() {
        //Todo
    }

    void toArray(){
        //Todo
    }

}