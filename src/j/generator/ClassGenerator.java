package j.generator;

import java.io.File;
import java.io.FileWriter;

public final class ClassGenerator
{
	private int set_size;
	
	public ClassGenerator(int p_set_size)
	{
		set_size = p_set_size;
	}
	
	/*
	 * TODO Constructor according to attributs, addElement and revoveElement
	 */
	public void generate()
	{
		try
		{
			for(int index = 0; index < set_size; index++)
			{
				File f = new File("./InnerSet_" + index + ".java");
				f.createNewFile();
				FileWriter fw = new FileWriter(f);
				fw.write("package java;" + System.getProperty("line.separator"));
				fw.write("public final class InnerSet_" + index + System.getProperty("line.separator"));
				fw.write("{" + System.getProperty("line.separator"));
				
				for(int j = 0; j < index; j++)
					fw.write("\telement_" + (j) + ";" + System.getProperty("line.separator"));
				
				fw.write(System.getProperty("line.separator"));
				
				/*
				 * TODO, Constructor here
				 */
				
				/*
				fw.write("public void addElement(T p_element" + System.getProperty("line.separator"));
				fw.write("{" + System.getProperty("line.separator"));
				fw.write("}" + System.getProperty("line.separator"));
				
				fw.write("public void removeElement(T p_element" + System.getProperty("line.separator"));
				fw.write("{" + System.getProperty("line.separator"));
				*/
				
				fw.write("}" + System.getProperty("line.separator"));
				
				fw.write(System.getProperty("line.separator"));
				
				fw.write("}");
				
				fw.close();
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] Args)
	{
		ClassGenerator class_generator = new ClassGenerator(10);
		class_generator.generate();
	}
}
