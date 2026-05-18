class Student {

    String name;
    int roll;
    int marks1, marks2, marks3;

    Student(String n, int r, int m1, int m2, int m3) {
        name = n;
        roll = r;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }

    int total() {
        return marks1 + marks2 + marks3;
    }

    double average() {
        return total() / 3.0;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Roll No: " + roll);
        System.out.println("Marks: " + marks1 + ", " + marks2 + ", " + marks3);
        System.out.println("Total: " + total());
        System.out.println("Average: " + average());
        System.out.println();
    }
}

public class StudentDemo {

    public static void main(String[] args) {

        Student students[] = new Student[4];

        students[0] = new Student("Ayan", 1, 85, 90, 88);
        students[1] = new Student("Rahul", 2, 78, 82, 80);
        students[2] = new Student("Priya", 3, 92, 89, 95);
        students[3] = new Student("Sneha", 4, 75, 70, 72);

        for (int i = 0; i < students.length; i++) {
            students[i].display();
        }
    }
}