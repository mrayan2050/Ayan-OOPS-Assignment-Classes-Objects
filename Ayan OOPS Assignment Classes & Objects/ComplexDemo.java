class Complex {

    int real;
    int imaginary;

    Complex() {
        real = 0;
        imaginary = 0;
    }

    Complex(int r) {
        real = r;
        imaginary = 0;
    }

    Complex(int r, int i) {
        real = r;
        imaginary = i;
    }

    Complex add(Complex c) {
        return new Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex multiply(Complex c) {
        int r = (real * c.real) - (imaginary * c.imaginary);
        int i = (real * c.imaginary) + (imaginary * c.real);
        return new Complex(r, i);
    }

    void display() {
        if (imaginary >= 0)
            System.out.println(real + "+" + imaginary + "i");
        else
            System.out.println(real + "" + imaginary + "i");
    }
}

public class ComplexDemo {

    public static void main(String[] args) {

        Complex c1 = new Complex(3, 2);
        Complex c2 = new Complex(4, -2);

        Complex sum = c1.add(c2);
        Complex product = c1.multiply(c2);

        System.out.print("First Complex Number: ");
        c1.display();

        System.out.print("Second Complex Number: ");
        c2.display();

        System.out.print("Sum: ");
        sum.display();

        System.out.print("Product: ");
        product.display();
    }
}