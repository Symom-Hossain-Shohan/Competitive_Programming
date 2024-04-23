public class Animal {
    private int body;
    private int size;
    private String name;

    public Animal(int body, int size, String name) {
        this.body = body;
        this.size = size;
        this.name = name;
    }

    public void eat()
    {
        System.out.println("Animal part was called\n");
    }

}
