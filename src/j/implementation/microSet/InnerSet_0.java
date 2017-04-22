package j.implementation.microSet;


import javax.swing.*;
import java.util.Collection;
import java.util.Iterator;

public class InnerSet_0 <T> extends AbstractInnerSet<T>
{
	public static InnerSet_0<Object> singleton = new InnerSet_0<>();
	
	@Override
	public InnerSet<T> addElement(T p_element)
	{
		return new InnerSet_1<T>(p_element);
	}

	@Override
	public InnerSet<T> addUnChecked(T p_element) {
		return addElement(p_element);
	}

	public InnerSet<T> addAllElements(InnerSet<T> innerSet) { return innerSet; }

	@Override
	public InnerSet<T> removeElement(Object p_element)
	{
		return this;
	}

	@Override
	public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
		return this;
	}

	@Override
	public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
		return this;
	}

	@Override
	public InnerSet<T> addAndPropagate(T p_element, MicroSet<T> microSetPropagate) {
		microSetPropagate.add(p_element);
		return new InnerSet_1<>(p_element);
	}

	@Override
	public InnerSet<T> addAllAndPropagate(InnerSet<T> innerSetToAdd, MicroSet<T> microSetPropagate) {
		microSetPropagate.innerSet.addAllElements(innerSetToAdd);
		return innerSetToAdd;
	}

	public T getElement(int index)
	{
		return null;
	}
	
	@Override
	public String toString()
	{
		return "{}";
	}
	
	@Override
	public int getSize()
	{
		return 0;
	}

	@Override
	public Iterator<T> iterator() {
		return new InnerSetIterator<>(this);
	}

	@Override
	public InnerSet<T> copy() {
		return (InnerSet<T>) InnerSet_0.singleton;
	}

	@Override
	public InnerSet<T> clear(boolean unused) {
		return this;
	}

	@Override
	public boolean containsElement(Object p_element)
	{
		return false;
	}

	@Override
	public boolean containsAllElements(InnerSet<T> innerSet) {
		return false;
	}
}
