class Student {

    private String name;
    private int roll;
    private String subjects[];

    Student(String name, int roll, String subjects[]) {
        this.name = name;
        this.roll = roll;
        this.subjects = subjects;
    }

    String getName() {
        return name;
    }

    int getRoll() {
        return roll;
    }

    String[] getSubjects() {
        return subjects;
    }

    void setName(String name) {
        this.name = name;
    }

    void setRoll(int roll) {
        this.roll = roll;
    }

    void setSubjects(String subjects[]) {
        this.subjects = subjects;
    }
}

class TabulationSheet {

    String subjectName;
    int rolls[] = new int[10];
    int marks[] = new int[10];
    int count = 0;

    TabulationSheet(String subjectName) {
        this.subjectName = subjectName;
    }

    void addMarks(int roll, int mark) {
        rolls[count] = roll;
        marks[count] = mark;
        count++;
    }

    void display() {

        System.out.println("Subject: " + subjectName);

        for (int i = 0; i < count; i++) {
            System.out.println(
                    "Roll: " + rolls[i]
                    + " Marks: " + marks[i]);
        }

        System.out.println();
    }
}

class MarkSheet {

    String studentName;
    int roll;
    String subjects[];
    int marks[];

    MarkSheet(String studentName,
              int roll,
              String subjects[],
              int marks[]) {

        this.studentName = studentName;
        this.roll = roll;
        this.subjects = subjects;
        this.marks = marks;
    }

    void display() {

        System.out.println("Student Name: " + studentName);
        System.out.println("Roll No: " + roll);

        for (int i = 0; i < subjects.length; i++) {
            System.out.println(
                    subjects[i] + " : " + marks[i]);
        }

        System.out.println();
    }
}

public class SchoolDemo {

    public static void main(String[] args) {

        String subs[] = {
                "Math",
                "Physics",
                "Chemistry",
                "English",
                "Computer"
        };

        Student s1 = new Student("Ayan", 101, subs);
        Student s2 = new Student("Rahul", 102, subs);
        Student s3 = new Student("Priya", 103, subs);

        TabulationSheet t1 = new TabulationSheet("Math");
        TabulationSheet t2 = new TabulationSheet("Physics");
        TabulationSheet t3 = new TabulationSheet("Chemistry");
        TabulationSheet t4 = new TabulationSheet("English");
        TabulationSheet t5 = new TabulationSheet("Computer");

        t1.addMarks(101, 85);
        t1.addMarks(102, 78);
        t1.addMarks(103, 92);

        t2.addMarks(101, 88);
        t2.addMarks(102, 80);
        t2.addMarks(103, 90);

        t3.addMarks(101, 84);
        t3.addMarks(102, 76);
        t3.addMarks(103, 89);

        t4.addMarks(101, 79);
        t4.addMarks(102, 82);
        t4.addMarks(103, 91);

        t5.addMarks(101, 95);
        t5.addMarks(102, 85);
        t5.addMarks(103, 97);

        MarkSheet m1 = new MarkSheet(
                s1.getName(),
                s1.getRoll(),
                subs,
                new int[]{85, 88, 84, 79, 95});

        MarkSheet m2 = new MarkSheet(
                s2.getName(),
                s2.getRoll(),
                subs,
                new int[]{78, 80, 76, 82, 85});

        MarkSheet m3 = new MarkSheet(
                s3.getName(),
                s3.getRoll(),
                subs,
                new int[]{92, 90, 89, 91, 97});

        System.out.println("MARK SHEETS\n");

        m1.display();
        m2.display();
        m3.display();
    }
}