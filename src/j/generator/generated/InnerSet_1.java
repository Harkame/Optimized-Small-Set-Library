package j.implementation.microSet;

public class InnerSet_1 <T> implements InnerSet<T>
{
        protected T element_1;
        
    public InnerSet_1(T p_element_1)
    {
                element_1 = p_element_1;
            }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element))
            return this;
        else
            return new InnerSet_2(element_1 , p_element);
    }

    @Override
    @SuppressWarnings({ "rawtypes", "unchecked" })
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return new InnerSet_0();
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element);
    }


    public T getElement(int index)
    {
                if (index == 1 )
            return element_1;
                        else
            return null;
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 1;
    }

}
