#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal{
public:
    Animal(){}
    virtual void makeSound(){}
    virtual ~Animal(){}
};

class Dog: public Animal{
public:
    Dog(){}
    void makeSound(){
        cout<<"Dog: grrrrrrrr!"<<endl;
    }
};

class Cat: public Animal{
public:
    Cat(){}
    void makeSound(){
        cout<<"Cat: miyaooo~"<<endl;
    }
};

class Cow: public Animal{
public:
    Cow(){}
    void makeSound(){
        cout<<"Cow: moo~~"<<endl;
    }
};

void print(Animal *animal){
    animal->makeSound();
}

class Zoo{
private:
    Animal *animals[10];
    int animalCount=0;
public:
    void addAnimal(Animal* animal){
        animals[animalCount]=animal;
        animalCount+=1;
    }
    void performActions(){
        for(int i=0;i<animalCount;i++){
            print(animals[i]);
        }
    }
    ~Zoo(){
        for(int i=0;i<animalCount;i++){
           delete animals[i];
        }
    }
};

Animal* createRandomAnimal(){
    Animal* animal;
    int randomNum=rand()%3; //create 0~2 number

    if(randomNum==0){
        animal=new Dog();
    }else if(randomNum==1){
        animal=new Cat();
    }else{
        animal=new Cow();
    }
    return animal;
}

int main(){
    srand(time(0)); //reset current time
    Zoo zoo;
    for(int i=0;i<10;i++){
        zoo.addAnimal(createRandomAnimal());
    }
    zoo.performActions();
    return 0;
}