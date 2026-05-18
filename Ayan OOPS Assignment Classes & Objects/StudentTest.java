class Student {

    private String name;
    private int roll;
    private double marks;

    Student(String n, int r, double m) {
        name = n;
        roll = r;
        marks = m;
    }

    String getName() {
        return name;
    }

    int getRoll() {
        return roll;
    }

    double getMarks() {
        return marks;
    }

    void setName(String n) {
        name = n;
    }

    void setRoll(int r) {
        roll = r;
    }

    void setMarks(double m) {
        marks = m;
    }
}

public class StudentTest {

    public static void main(String[] args) {

        Student s1 = new Student("Ayan", 101, 88.5);
        Student s2 = new Student("Rahul", 102, 91.0);

        System.out.println("Student 1 Details:");
        System.out.println("Name: " + s1.getName());
        System.out.println("Roll: " + s1.getRoll());
        System.out.println("Marks: " + s1.getMarks());

        System.out.println();

        System.out.println("Student 2 Details:");
        System.out.println("Name: " + s2.getName());
        System.out.println("Roll: " + s2.getRoll());
        System.out.println("Marks: " + s2.getMarks());
    }
}