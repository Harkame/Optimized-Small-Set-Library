package j.implementation.microSet;


public abstract class AbstractInnerSet<T>  implements InnerSet<T> {
    public static int MAX_SIZE = 5;

    public boolean shouldArray() {
        return this.getSize() >= MAX_SIZE;
    }
}
