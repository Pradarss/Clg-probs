abstract class Shape {
    abstract int numberOfSides();
}

class Trapezoid extends Shape {
    private static int sides = 4;

    int numberOfSides() {
        return sides;
    }

    public String toString() {
        return "Trapezoid";
    }
}

class Triangle extends Shape {
    private static int sides = 3;

    int numberOfSides() {
        return sides;
    }

    public String toString() {
        return "Triangle";
    }
}

class Rectangle extends Shape {
    private static int sides = 4;

    int numberOfSides() {
        return sides;
    }

    public String toString() {
        return "Rectangle";
    }
}

class Hexagon extends Shape {
    private static int sides = 6;

    int numberOfSides() {
        return sides;
    }

    public String toString() {
        return "Hexagon";
    }
}

public class Execute10 {
    public static void main(String args[]) {
        System.out.println("Adarsh");
        Shape[] shapes = new Shape[5];
        Trapezoid tp = new Trapezoid();
        Triangle tr = new Triangle();
        Rectangle rt = new Rectangle();
        Hexagon hx = new Hexagon();
        shapes[0] = tp;
        shapes[1] = tr;
        shapes[2] = rt;
        shapes[3] = hx;
        for (int i = 0; i < 4; i++) {
            System.out.println(shapes[i].toString() + " sides:" + shapes[i].numberOfSides());

        }

    }
}
