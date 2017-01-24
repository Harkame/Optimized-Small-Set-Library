package implementation;

import java.math.BigDecimal;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

//TODO 
public final class ConnexionArray implements Set<Number>
{	
	private static final int SIZE = 100;
	
	private int   card;
	private Number[] values;
	private Number[] positions;
	
	public ConnexionArray()
	{
		card      = 0;
		values    = new Number[SIZE];
		positions = new Number[SIZE];
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
		for(int index = 0; index < values.length; index++)
		{
			values[index]    = null;
			positions[index] = null;
		}
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
		return card == 0;
	}

	@Override
	public Iterator<Number> iterator()
	{
		return new ConnexionArrayIterator(this);
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
		
		values[card] = p_value;
		
		card++;
		
		return true;
	}
	
	@Override
	public boolean remove(Object p_value)
	{
		Number t_value  = (Number) p_value;
		Number position = positions[t_value.intValue()];
		
		if((position == null) || (!values[position.intValue()].equals(p_value)))
			return false;
		
		card--;
		
		values[position.intValue()]   = card;
		
		positions[t_value.intValue()] = card;
		
		
		return true;
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
		return card;
	}

	@Override
	public Object[] toArray()
	{
		Number[] res = new Number[card];
		int cpt = 0;
		
		for(int index = 0; index < values.length; index++)
			if(positions[index] != null && values[positions[index].intValue()].intValue() == index)
			{
				res[cpt] = values[positions[index].intValue()];
				cpt++;
			}
		
		return res;
	}

	@Override
	public <T> T[] toArray(T[] a)
	{
		return null; //TODO
	}
	
	@Override
	public String toString()
	{
		int cpt = 0;
		StringBuilder string_builder = new StringBuilder();
		string_builder.append("{");
		
		for(int index = 0; index < positions.length; index++)
		{
			if(positions[index] != null && values[positions[index].intValue()].intValue() == index)
			{
				string_builder.append(values[positions[index].intValue()].intValue());
			
				if(cpt < card - 1)
					string_builder.append(", ");
				
			cpt++;
			}
		}
		string_builder.append("}");
		
		return string_builder.toString();
	}
	
	public Number[] getValues()
	{
		return values;
	}
	
	public Number[] getPositions()
	{
		return positions;
	}
	
	public static void main(String[] Args)
	{
		Set<Number> connexion_array = new ConnexionArray();
		
		System.out.println(connexion_array.add(12));
		System.out.println(	connexion_array.add(42));
		System.out.println(connexion_array.add(83));
		System.out.println(connexion_array.add(83));
		
		System.out.println(connexion_array.toString());
		
		System.out.println(connexion_array.remove(12));
		System.out.println(connexion_array.remove(12));
		System.out.println(connexion_array.remove(49));
		System.out.println(connexion_array.remove(42));
		
		System.out.println(connexion_array.toString());
		
		Iterator<Number> t = connexion_array.iterator();
		
		while(t.hasNext())
		{
			System.out.println(t.next().toString());
		}
	}
}
