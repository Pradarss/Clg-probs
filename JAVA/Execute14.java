import java.util.*;

class SortNames {
    String name[] = new String[5];
    int i, n = 5;

    SortNames() {
        for (i = 0; i < n; i++) {
            name[i] = null;
        }
    }

    void inputNames() {
        name[0] = "Yogesh";
        name[1] = "Deepak";
        name[2] = "Aman";
        name[3] = "Srishti";
        name[4] = "Baljinder";
    }

    void bubbleSort() {
        int j;
        String temp;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1 - i; j++) {
                if (name[j].compareTo(name[j + 1]) > 0) {
                    temp = name[j];
                    name[j] = name[j + 1];
                    name[j + 1] = temp;
                }
            }
        }
    }

    void displayNames() {
        for (i = 0; i < n; i++) {
            System.out.println(name[i]);
        }
    }
}

class Execute14 {
    public static void main(String a[]) {
        System.out.println("Adarsh");                          
        SortNames sn = new SortNames();
        sn.inputNames();
        sn.bubbleSort();
        sn.displayNames();
    }
}