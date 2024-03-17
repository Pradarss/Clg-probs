public class Exception {
    public static void main(String[] args) {
        try {
            int result = divide(10, 0); // Potential division by zero
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero");
        } finally {
            System.out.println("End of program");
            System.out.println("\n Name - Adarsh \n Enrollment number - 50213203121 \n Class - IT_2(FSD)"); 
        }
    }

    static int divide(int a, int b) {
        return a / b;
    }
}
