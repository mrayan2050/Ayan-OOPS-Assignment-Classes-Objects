class Room {

    double width;
    double breadth;

    Room(double w, double b) {
        width = w;
        breadth = b;
    }

    double floorArea() {
        return width * breadth;
    }
}

public class House {

    public static void main(String[] args) {

        Room bedroom1 = new Room(12, 10);
        Room bedroom2 = new Room(11, 10);
        Room drawingRoom = new Room(15, 12);
        Room kitchen = new Room(10, 8);

        double totalArea = bedroom1.floorArea()
                         + bedroom2.floorArea()
                         + drawingRoom.floorArea()
                         + kitchen.floorArea();

        System.out.println("Total floor area of house = " + totalArea);
    }
}