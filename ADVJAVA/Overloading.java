class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
}

public class Overloading {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        System.out.println(calc.add(5, 3)); // Output: 8
        System.out.println(calc.add(2.5, 3.5)); // Output: 6.0

        System.out.println("\n Name - Adarsh \n Enrollment number - 50213203121 \n Class - IT_2(FSD)");

    }
}
