import java.util.*;

class IntData {
    int arr[];
    int i, sum;

    IntData(int size) {
        arr = new int[size];
        sum = 0;
    }

    void input() {
        Scanner sc = new Scanner(System.in);
        for (i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
    }

    void display() {
        for (i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

    void sumCal() {
        for (i = 0; i < arr.length; i++) {
            sum = sum + arr[i];
        }
        System.out.println("SUM IS " + sum);
    }
}

class Execute8 {
    public static void main(String a[]) {
        System.out.println("Adarsh");                    
        IntData obj = new IntData(5);
        obj.input();
        obj.display();
        obj.sumCal();
    }
}
