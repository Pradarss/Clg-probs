abstract class MyArea {
    abstract void area();
}

class SQArea extends MyArea {
    double s;

    void area() {
        double areasq;
        s = 10.0;
        areasq = s * s;
        System.out.println("Area of Square " + areasq);
    }
}

class RECTArea extends MyArea {
    double l, b;

    void area() {
        double arearect;
        l = 10.0;
        b = 2.0;
        arearect = l * b;
        System.out.println("Area of Rectangle " + arearect);
    }
}

class Execute10 {
    public static void main(String a[]) {
        // MyArea ma= new MyArea();
        // ma.area();
        MyArea sa = new SQArea();
        sa.area();
        MyArea ra = new RECTArea();
        ra.area();
    }
}
