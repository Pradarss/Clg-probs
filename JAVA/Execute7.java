import java.util.*;

class P_Check {
    void check(String data) {
        String rdata = "";
        int i, len;
        len = data.length();
        for (i = len - 1; i >= 0; i--)
            rdata = rdata + data.charAt(i);
        if (data.equals(rdata))
            System.out.println("Entered string is a palindrome.");
        else
            System.out.println("Entered string is not a palindrome.");
    }
}

class Execute7 {
    public static void main(String a[]) {
        System.out.println("Adarsh");               
        String name;
        P_Check pc = new P_Check();
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a string");
        name = in.nextLine();
        pc.check(name);
    }
}
