package p1;

public class Employee {
    private String name;
    private int id;

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public void displayDetails() {
        System.out.println("p1.Employee Details: Name = " + name + ", ID = " + id);
    }
}
