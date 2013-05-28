#include <iostream>
#include <exception>

#include "Dog"
#include "Cat"

class GermanShepard : public Dog {
  public:
    GermanShepard(const std::string & n) : Dog(n) {}

    std::string speak() {
        return "Woof, mein Name ist " + getName() + ". Jawoll.";
    }
};

class StupidPoodle : public Dog {
  public:
    StupidPoodle(const std::string & n) : Dog(n) {}
};

void LetPetsSpeak(Pet& p) {
    std::cout << p.speak() << std::endl;
}

int main (int argc, char** argv) {
    //Pet p("pet");
    Cat c("Herbert");
    LetPetsSpeak(c);
    Dog d("Carlo");
    LetPetsSpeak(d);
    GermanShepard g("Fritz");
    LetPetsSpeak(g);
    StupidPoodle p("Woofy");
    LetPetsSpeak(p);
    return 0;
}
