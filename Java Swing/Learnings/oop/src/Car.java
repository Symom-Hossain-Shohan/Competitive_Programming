public class Car {
    private int wheel;
    private int model;
    private String color;
    public Car()
    {
        System.out.println("This is an empty constructor\n");
    }

    public Car(int wheel, int model, String color) {
        this.wheel = wheel;
        this.model = model;
        this.color = color;
    }
}
