package j.tests;


import j.implementation.TestObject;
import j.implementation.microSet.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;


/**
 * Created by fly on 2/16/17.
 */
class InnerSet_Test {

    InnerSet<TestObject> innerSet;

    @BeforeEach
    void setUp() {
        innerSet = new InnerSet_1(new TestObject(0));
    }

    @Test
    void addElement() {
        InnerSet<TestObject> i = innerSet.addElement(new TestObject(1));
        assertNotEquals(i, innerSet);
    }

    @Test
    void removeElement() {

    }

    @Test
    void containsElement() {

    }

    @Test
    void getElement() {

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

    @Test
    void testToString() {

    }

    @Test
    void getSize() {

    }

}