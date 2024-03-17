class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

public class Overriding {
    public static void main(String[] args) {
        Animal animal = new Dog();
        animal.sound(); // Output: Dog barks

        System.out.println("\n Name - Adarsh \n Enrollment number - 50213203121 \n Class - IT_2(FSD)");
    }
}
