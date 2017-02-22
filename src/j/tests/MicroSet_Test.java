package j.tests;


import j.implementation.TestObject;
import j.implementation.microSet.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;


class MicroSet_Test {

    MicroSet<TestObject> microSet;
    TestObject testObject = new TestObject(1);

    @BeforeEach
    void setUp() {
        microSet = new MicroSet<>();
        microSet.add(testObject);
    }

    @Test
    void addElement() {
        boolean res = microSet.add(testObject);
        assertFalse(res);
        boolean res2 = microSet.add(new TestObject(2));
        assertTrue(res2);
    }

    @Test
    void removeElement() {
        boolean res = microSet.remove(new TestObject(1));
        assertFalse(res);
        boolean res2 = microSet.remove(testObject);
        assertTrue(res2);
    }

    @Test
    void containsElement() {
        boolean res = microSet.contains(new TestObject(1));
        assertFalse(res);
        boolean res2 = microSet.contains(testObject);
        assertTrue(res2);
    }

    @Test
    void clear() {
        microSet.clear();
        assertFalse(microSet.contains(testObject));
    }

    @Test
    void addAllElements() {

    }

    @Test
    void removeAllElements() {

    }

    @Test
    void retainAllElements() {

    }

    @Test
    void containsAllElements() {

    }

}