public class Dog extends Animal{
    private int malik;

    public Dog(int body, int size, String name, int malik) {
        super(body, size, name);
        this.malik = malik;
    }

    @Override
    public void eat() {
        System.out.println("Doger function call hoise\n");
        super.eat();
    }
}
