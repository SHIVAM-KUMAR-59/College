package Department;

public class Student {
    String name;
    int semester;
    String branch;
    int rollNo;
    double cgpa;

    // Constructor
    public Student(String name, int semester, String branch, int rollNo, double cgpa) {
        this.name = name;
        this.semester = semester;
        this.branch = branch;
        this.rollNo = rollNo;
        this.cgpa = cgpa;
    }

    // Method to display student details
    public void show() {
        System.out.println("Student Details:");
        System.out.println("Name: " + name);
        System.out.println("Semester: " + semester);
        System.out.println("Branch: " + branch);
        System.out.println("Roll No: " + rollNo);
        System.out.println("CGPA: " + cgpa);
    }
}
