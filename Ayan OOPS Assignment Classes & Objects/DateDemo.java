class Date {

    int day;
    int month;
    int year;

    Date() {
        day = 1;
        month = 1;
        year = 1970;
    }

    Date(int d) {
        day = d;
        month = 1;
        year = 1970;
    }

    Date(int d, int m) {
        day = d;
        month = m;
        year = 1970;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    int daysInMonth(int m, int y) {

        if (m == 1 || m == 3 || m == 5 || m == 7 ||
            m == 8 || m == 10 || m == 12)
            return 31;

        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;

        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            return 29;

        return 28;
    }

    void nextDate() {

        day++;

        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void previousDate() {

        day--;

        if (day < 1) {
            month--;

            if (month < 1) {
                month = 12;
                year--;
            }

            day = daysInMonth(month, year);
        }
    }

    void printDate() {
        System.out.println(day + "/" + month + "/" + year);
    }
}

public class DateDemo {

    public static void main(String[] args) {

        Date d1 = new Date();
        Date d2 = new Date(15);
        Date d3 = new Date(20, 8);
        Date d4 = new Date(31, 12, 2025);

        System.out.println("Original Dates:");
        d1.printDate();
        d2.printDate();
        d3.printDate();
        d4.printDate();

        System.out.println();

        System.out.println("Next Dates:");
        d1.nextDate();
        d1.printDate();

        d2.nextDate();
        d2.printDate();

        d3.nextDate();
        d3.printDate();

        d4.nextDate();
        d4.printDate();

        System.out.println();

        System.out.println("Previous Dates:");
        d1.previousDate();
        d1.printDate();

        d2.previousDate();
        d2.printDate();

        d3.previousDate();
        d3.printDate();

        d4.previousDate();
        d4.printDate();
    }
}