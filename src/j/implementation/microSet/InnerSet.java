package j.implementation.microSet;

import java.util.Collection;
import java.util.Iterator;

public interface InnerSet<T> {

    InnerSet<T> addElement(T p_element);

    InnerSet<T> addUnChecked(T p_element);

    InnerSet<T> addAllElements(InnerSet<T> innerSet);

    boolean containsElement(Object p_element);

    boolean containsAllElements(InnerSet<T> innerSet);

    T getElement(int index);

    InnerSet<T> removeElement(Object p_element);

    InnerSet<T> removeAllElements(InnerSet<T> innerSet);

    InnerSet<T> retainAllElements(InnerSet<T> innerSet);

    InnerSet<T> addAndPropagate(T p_element, MicroSet<T> microSet);

    InnerSet<T> addAllAndPropagate(InnerSet<T> innerSet, MicroSet<T> microSet);

    InnerSet<T> addAllAndPropagateReverse(InnerSet<T> innerSet, MicroSet<T> microSet);

    int getSize();

    Iterator<T> iterator();

    InnerSet<T> copy();

    InnerSet<T> clear(boolean unused);

}
