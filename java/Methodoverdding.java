
class Animal {
    Animal getAnimal() {
        return new Animal();
    }
}

class Dog extends Animal {
    @Override
    Dog getAnimal() {  // Covariant return type
        return new Dog();
    }
}
