class Fibonacci_with_recursion {
    int n1 = 0, n2 = 1, n3 = 0;

    void printFibonacci(int count) {
        if (count > 0) {
            // System.out.print(0);
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
            System.out.print(" " + n3);
            printFibonacci(count - 1);
        }
    }
}

class Fibonacci_without_recursion {
    int n1 = 0, n2 = 1, n3 = 0;

    void fibonaaci2(int count) {
        System.out.print(0);
        for (int i = 2; i < count; ++i)// loop starts from 2 because 0 and 1 are already printed
        {
            n3 = n1 + n2;
            System.out.print(" " + n3);
            n1 = n2;
            n2 = n3;
        }
    }

}

class Execute5 {
    public static void main(String[] args) {
        System.out.println("Adarsh");                      
        Fibonacci_with_recursion f = new Fibonacci_with_recursion();
        System.out.println("Fibonacci with recursion : ");
        f.printFibonacci(7);
        Fibonacci_without_recursion f2 = new Fibonacci_without_recursion();
        System.out.println("\n");
        System.out.println("Fibonacci without recursion : ");
        f2.fibonaaci2(7);
    }
}
