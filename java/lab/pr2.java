package cycle2;
import java.util.Scanner;
import java.lang.Math;

class AreaCalculator{
  public double  calculate(double r){

    return 3.14*r*r;
  }
  public double  calculate(double l,double b){
    return l*b;
  }

  public double calculate(double a, double b,double c){
    double s = (a+b+c)/2;
    return Math.sqrt(s*(s-a)*(s-b)*(s-c));
  }
}
public class pr2 {
  public static void main(String[] args) {
    System.out.println("calculate area of : ");
    System.out.println("1-circle");
    System.out.println("2-Rectangle");
    System.out.println("3-Traingle");

    Scanner sc = new Scanner(System.in);
    int choice = sc.nextInt();

    AreaCalculator mycalculator = new AreaCalculator();
    switch (choice) {
      case 1:
       System.out.println("Enter radius"); 
        int r = sc.nextInt();
      System.out.println(mycalculator.calculate(r)); 
        break;

      case 2:
       System.out.println("Enter length and breadth"); 
        int l = sc.nextInt();
        int b = sc.nextInt();
      System.out.println(mycalculator.calculate(l,b)); 
        break;
      case 3:
       System.out.println("Enter length of sides"); 
        int a = sc.nextInt();
        b = sc.nextInt();
        int c = sc.nextInt();
      System.out.println(mycalculator.calculate(a,b,c)); 
        break;
      default:
        break;
    }
  }
}
