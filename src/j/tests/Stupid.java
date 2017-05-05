package j.tests;

import j.implementation.microSet.MicroSet;

/**
 * Created by fly on 01/05/17.
 */
public class Stupid {

    public static void main(String[] args) {
        MicroSet<Integer> microSet = new MicroSet<>();
        microSet.add(2);
        microSet.add(3);
        microSet.contains(2);
        microSet.remove(2);
        microSet.contains(2);
    }
}
