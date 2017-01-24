package implementation;

import java.util.Iterator;

public class ConnexionArrayIterator implements Iterator<Number>
{
	private int index = 0;
	private ConnexionArray connexion_array;
	
	public ConnexionArrayIterator(ConnexionArray p_connexion_array)
	{
		connexion_array = p_connexion_array;
	}

	@Override
	public boolean hasNext()
	{
		return index != connexion_array.getValues().length;
	}

	@Override
	public Number next()
	{
		Number res = null;
		
		while(res == null)
		{
			index++;
			if(connexion_array.getPositions()[index] != null &&
					connexion_array.getValues()[connexion_array.getPositions()[index].intValue()].intValue() == index)
				res = connexion_array.getValues()[connexion_array.getPositions()[index].intValue()];
		}
		
		return res;
	}
}
