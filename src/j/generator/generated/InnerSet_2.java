package j.implementation.microSet;

public class InnerSet_2 <T> implements InnerSet<T>
{
        protected T element_1;
        protected T element_2;
        
    public InnerSet_2(T p_element_1, T p_element_2)
    {
                element_1 = p_element_1;
                element_2 = p_element_2;
            }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element))
            return this;
        else
            return new InnerSet_3(element_1, element_2 , p_element);
    }

    @Override
    @SuppressWarnings({ "rawtypes", "unchecked" })
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return new InnerSet_1(element_2);
         else                 if(element_2.equals(p_element))
            return new InnerSet_1(element_1);
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element);
    }


    public T getElement(int index)
    {
                if (index == 1 )
            return element_1;
         else                 if (index == 2 )
            return element_2;
                        else
            return null;
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + ", " + element_2 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 2;
    }

}
