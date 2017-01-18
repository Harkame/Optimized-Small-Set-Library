package skadi.net.communitation;

import java.math.BigDecimal;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

//TODO 
public final class ConnexionArray implements Set<Number>
{	
	private static final int SIZE = 999999;
	
	private int   card;
	private Number[] values;
	private Number[] positions;
	
	public SetImpl()
	{
		card      = 0;
		values    = new Number[999999];
		positions = new Number[999999];
	}
	
	@Override
	public boolean addAll(Collection<? extends Number> c)
	{
		c.forEach(n -> add(n));
		return true;
	}

	@Override
	public void clear()
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean contains(Object o)
	{
		Number t_value = (Number) o;
		return values[positions[t_value.intValue()].intValue()] == t_value;
	}

	@Override
	public boolean containsAll(Collection<?> c)
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean isEmpty()
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public Iterator<Number> iterator()
	{
		// TODO Auto-generated method stub
		return null;
	}
	
	@Override
	public boolean add(Number p_value)
	{
		Number position = positions[p_value.intValue()];

		if(position == null)
			positions[p_value.intValue()] = p_value;
		else
			return false;
		
		 position = positions[p_value.intValue()];
		
		BigDecimal b = new BigDecimal(card);
		positions[p_value.intValue()] = b;

		System.out.println("card : " + card + " - p_value : " + p_value);
		values[card]       = p_value;
		
		card++;
		return true;

	}
	
	@Override
	public boolean remove(Object p_value)
	{
		Number t_value = (Number) p_value;
		Number position = positions[t_value.intValue()];
		if(values[position.intValue()] != p_value)
		{
			values[card]       = card;
			card--;
			positions[t_value.intValue()] = card;
			return true;
		}
		else
			return false;
	}
	
	@Override
	public boolean removeAll(Collection<?> c)
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean retainAll(Collection<?> c)
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public int size()
	{
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public Object[] toArray()
	{
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <T> T[] toArray(T[] a)
	{
		// TODO Auto-generated method stub
		return null;
	}
	
	@Override
	public String toString()
	{
		StringBuilder string_builder = new StringBuilder();
		string_builder.append("{");
		
		for(int index = 0; index <= card; index++)
			if(index != card - 1)
				string_builder.append(values[index] + ", ");
			else
				string_builder.append(values[index]);
		
		string_builder.append("}");
		
		return string_builder.toString();
	}
	
	public static void main(String[] Args)
	{
		ConnexionArray connexion_array = new SetImpl();
		connexion_array.add(12);
		connexion_array.add(42);
		System.out.println(connexion_array.toString());
	}
}
