import static java.lang.Math.*;

class Quadratic {
    double a, b, c, r1, r2, d;

    void input_equation(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }

    void calculate_roots() {
        d = b * b - 4 * a * c;
        if (d > 0) {
            System.out.println("The roots of the equation are real and different. \n");
            r1 = -b + sqrt(abs(d)) / 2 * a;
            r2 = -b - sqrt(abs(d)) / 2 * a;
            System.out.println(" roots are : " + r1 + " " + r2);
        } else if (d == 0) {
            System.out.println("The roots of the equation are real and same. \n"); 
            r1 = -b / 2 * a;
            r2 = -b / 2 * a;
            System.out.println(" roots are : " + r1 + " " + r2);
        }
        else{
            System.out.println("The roots of the equation are complex and different. \n"); 
            r1 = -b / 2 * a;
            r2 = -b / 2 * a;
            System.out.println(r1 + " + i"+ d + "\n"+ r2+ " - i" + d); 
        }
    }
}

class Execute4{
    public static void main(String[] args) {
        System.out.println("Adarsh");                   
        Quadratic q = new Quadratic();
        q.input_equation(1.0,3.0,5.0);
        q.calculate_roots();
    }
}
