class Box {

    double height;
    double width;
    double breadth;

    Box() {
        height = 1;
        width = 1;
        breadth = 1;
    }

    Box(double h, double w, double b) {
        height = h;
        width = w;
        breadth = b;
    }

    double getVolume() {
        return height * width * breadth;
    }

    double getArea() {
        return 2 * (height * width + width * breadth + height * breadth);
    }
}

public class Main {

    public static void main(String[] args) {

        Box box1 = new Box(4, 5, 6);
        Box box2 = new Box(3, 7, 2);

        System.out.println("Box 1 Volume = " + box1.getVolume());
        System.out.println("Box 1 Surface Area = " + box1.getArea());

        System.out.println();

        System.out.println("Box 2 Volume = " + box2.getVolume());
        System.out.println("Box 2 Surface Area = " + box2.getArea());
    }
}
