class Employee {

    private String name;
    private int id;
    private String address;
    private double salary;

    Employee(String name, int id, String address, double salary) {
        this.name = name;
        this.id = id;
        this.address = address;
        this.salary = salary;
    }

    String getName() {
        return name;
    }

    int getId() {
        return id;
    }

    String getAddress() {
        return address;
    }

    double getSalary() {
        return salary;
    }

    void setName(String name) {
        this.name = name;
    }

    void setId(int id) {
        this.id = id;
    }

    void setAddress(String address) {
        this.address = address;
    }

    void setSalary(double salary) {
        this.salary = salary;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Address: " + address);
        System.out.println("Monthly Salary: " + salary);
        System.out.println();
    }
}

class Dept {

    private String deptName;
    private String location;
    private int year;
    Employee employees[] = new Employee[20];
    int count = 0;

    Dept(String deptName, String location, int year) {
        this.deptName = deptName;
        this.location = location;
        this.year = year;
    }

    void add(Employee e) {
        employees[count] = e;
        count++;
    }

    void remove(int id) {

        for (int i = 0; i < count; i++) {

            if (employees[i].getId() == id) {

                for (int j = i; j < count - 1; j++) {
                    employees[j] = employees[j + 1];
                }

                count--;
                System.out.println("Employee Removed");
                return;
            }
        }
    }

    double annualSalary() {

        double total = 0;

        for (int i = 0; i < count; i++) {
            total += employees[i].getSalary() * 12;
        }

        return total;
    }

    void displayEmployees() {

        for (int i = 0; i < count; i++) {
            employees[i].display();
        }
    }
}

public class DeptDemo {

    public static void main(String[] args) {

        Dept itDept = new Dept(
                "Information Technology",
                "Kolkata",
                2005);

        itDept.add(new Employee(
                "Ayan", 101,
                "Kolkata", 50000));

        itDept.add(new Employee(
                "Rahul", 102,
                "Delhi", 45000));

        itDept.add(new Employee(
                "Priya", 103,
                "Mumbai", 55000));

        itDept.add(new Employee(
                "Sneha", 104,
                "Chennai", 48000));

        itDept.add(new Employee(
                "Arjun", 105,
                "Bangalore", 60000));

        System.out.println("Employees of IT Department:\n");

        itDept.displayEmployees();

        System.out.println(
                "Annual Salary to be Paid = "
                + itDept.annualSalary());
    }
}