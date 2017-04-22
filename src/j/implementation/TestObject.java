package j.implementation;

public class TestObject implements Comparable<TestObject>
{
	private int id;

	public TestObject(int id)
	{
		this.id = id;
	}

	@Override
	public String toString() {
		return "{testObject: id=" + id + "}";
	}

	@Override
	public int compareTo(TestObject testObject) {
		int res = 0;
		if (this.id < testObject.id) res = -1;
		if (this.id > testObject.id) res = 1;
		return res;
	}
}