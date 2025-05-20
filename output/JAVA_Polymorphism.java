/*
Just a Simple program for memorizing JAVA Polymorphism. 
*/

class Buggu {
    
    // This add function is a good example of Polymorphism. 
    // add() has same name but different parameters 
    
    void add(){
        int a= 10;
        int b = 20;
        System.out.println(a+b);
    }
    
    int add(int a, int b){
        return(a+b);
    }
    
    int add(int a, int b, int c){
        return(a+b+c);
    }

    public static void main(String[] args) {
        // For making Object of class named "Buggu" and x is the object name
        Buggu x = new Buggu();
        Buggu mummy = new Buggu(); 
        
        // calling functions by object named x 
        x.add();
        // calling functions by object named mummy  
        mummy.add();
        
        System.out.println(x.add(10,15));
        System.out.println(mummy.add(10,15));
        System.out.println(x.add(10,15,10));
        System.out.println(mummy.add(10,15,10));
    }
}