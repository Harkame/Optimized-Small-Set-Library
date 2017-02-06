package j.implementation.microSet;

import java.util.Collection;

public interface InnerSet<T> {
    InnerSet<T> addElement(T p_element);

    InnerSet<T> addAllElements(Collection<? extends T> p_newC);

    boolean containsElement(Object p_element);

    boolean containsAllElements(Collection<?> p_c);

    InnerSet<T> removeElement(Object p_element);

    InnerSet<T> removeAllElements(Collection<?> p_cToDelete);

    InnerSet<T> retainAllElements(Collection<?> p_cToKeep);

    int getSize();
}
