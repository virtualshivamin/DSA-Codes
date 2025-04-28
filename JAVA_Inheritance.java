/*
A simple program for understanding the JAVA inheritance concept.

Create a program to model different types of vehicles in a transportation system. There are three types of vehicles: Cars, Bicycles, and Trains. All vehicles have common properties such as brand and speed, and common behaviors such as start() and stop(). Each type of vehicle has its own specific behavior:
Cars honk
Bicycles ringBell
Trains whistle

*/


// Vehicle class jisme saare common functions aur properties rahenge 
class Vehicle {
    // brand, speed commpon properties 
    String brand; 
    int speed;
    
    // Vehicle constructor function jo brand aur speed input lega 
    Vehicle(String brand, int speed)
    {
        this.brand = brand;
        this.speed = speed; 
    }
    
    // common start function 
    void start()
    {
        System.out.println(brand+" is starting.");
    }
    // common stop function 
    void stop()
    {
        System.out.println(brand+" is stopping.");
    }
}

// dusra class Car jisme Vehicle ki inherited properties as well as car ki khud ki proper hai 
class Car extends Vehicle {
    // Inherited property, brand speed input 
    // Constructor jo input lega brand aur speed 
    Car(String brand,int speed){
        super(brand,speed); // input leke super class me jayega mtlb ki Vehicle me 
    }
    void honk(){
        System.out.println(brand+" is honking.");
    }
}

// class Bicycle jisme Vehicle ki inherited properties as well as car ki khud ki proper hai 
class Bicycle extends Vehicle {
    Bicycle(String brand, int speed) {
        super(brand, speed);
    }

    void ringBell() {
        System.out.println(brand + " is ringing bell!");
    }
}

// class Train jisme Vehicle ki inherited properties as well as car ki khud ki proper hai 
class Train extends Vehicle {
    Train(String brand, int speed) {
        super(brand, speed);
    }

    void whistle() {
        System.out.println(brand + " is whistling!");
    }
}

public class JAVA_Inheritance {
    public static void main(String args[]){
        // Car class ka object car jo ki input dega "Honda" aur "100" 
        Car car = new Car("Honda", 100);
        // Bicycle class ka object bicycle 
        Bicycle bicycle = new Bicycle("Atlas", 20);
        // Train class ka object train 
        Train train = new Train("Indian Railways", 300);
        
        // car ke object se fuctions ko call kiya gaya hai 
        car.start();
        car.honk();
        car.stop();
        
        // bicycle ke object se fuctions ko call kiya gaya hai 
        bicycle.start();
        bicycle.ringBell();
        bicycle.stop();

        // train ke object se fuctions ko call kiya gaya hai
        train.start();
        train.whistle();
        train.stop();
    }
}

/*
Output : 

Honda is starting.
Honda is honking.
Honda is stopping.
Atlas is starting.
Atlas is ringing bell!
Atlas is stopping.
Indian Railways is starting.
Indian Railways is whistling!
Indian Railways is stopping.

=== Code Execution Successful ===
*/