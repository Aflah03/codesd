
class Animal{

}
class Monkey extends Animal{

}
class Test2{
    public void m1(Animal a){
        System.out.println("Animal version");
    }
    public void m2(Monkey m){
        System.out.println("Monkey version");
    }

    public static void main(String[] args) {
        Test t = new Test();
        Animal a = new Animal();
        Monkey m = new  Monkey();

        t.m1(a);
        t.m1(m);
    }
}
