package j.implementation.microSet;

public class InnerSet_3 <T> implements InnerSet<T>
{
    protected T element_1;
    protected T element_2;
    protected T element_3;
        
    public InnerSet_3(T p_element_1, T p_element_2, T p_element_3)
    {
        element_1 = p_element_1;
        element_2 = p_element_2;
        element_3 = p_element_3;
            }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element))
            return this;
        else
            return new InnerSet_4(element_1, element_2, element_3 , p_element);
    }

    @Override
    @SuppressWarnings({ "rawtypes", "unchecked" })
    public InnerSet<T> removeElement(Object p_element)
    {
        if(element_1.equals(p_element))
            return new InnerSet_2(element_2element_3);
        if(element_2.equals(p_element))
            return new InnerSet_2(element_1element_3);
        if(element_3.equals(p_element))
            return new InnerSet_2(element_1element_2);
        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element);
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + ", " + element_2 + ", " + element_3 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 3;
    }

}
