#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal{
public:
    Animal(){}
    virtual void makeSound(){}
    ~Animal(){}
};

class Dog: public Animal{
public:
    Dog(string s):Sound(s){}
    void makeSound(){
        cout<<"Dog: "<<Sound<<endl;
    }
private:
    string Sound;
};

class Cat: public Animal{
public:
    Cat(string s):Sound(s){}
    void makeSound(){
        cout<<"Cat: "<<Sound<<endl;
    }
private:
    string Sound;
};

class Cow: public Animal{
public:
    Cow(string s):Sound(s){}
    void makeSound(){
        cout<<"Cow: "<<Sound<<endl;
    }
private:
    string Sound;
};

void print(Animal *animal){
    animal->makeSound();
}

int main(){
    Animal * animal[3];

    Dog dog("grrrrrrr!");
    Cat cat("miyaoooooo~");
    Cow cow("moo~");

    animal[0]=&dog;
    animal[1]=&cat;
    animal[2]=&cow;

    for(int i=0;i<3;i++){
        print(animal[i]);
    }
    return 0;
}