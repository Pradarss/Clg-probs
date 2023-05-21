class Largest {
    int num1, num2, num3, result;

    void input() {
        num1 = 8;
        num2 = 9;
        num3 = 10;
    }

    void largest() {
        if (num1 > num2 && num1 > num3) {
            System.out.println("Largest : " + result);
            result = num1;
        } else if (num2 > num1 && num2 > num3) {
            result = num2;
            System.out.println("Largest : " + result);
        } else {
            result = num3;
            System.out.println("Largest : " + result);
        }
    }
}

class Execute {
    public static void main(String[] args) {
        System.out.println("Adarsh");
        Largest l = new Largest();
        l.input();
        l.largest();
    }
}
