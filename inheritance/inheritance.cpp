#include <iostream>
#include <exception>

#include "Dog"
#include "Cat"
#include "GermanShepard"
#include "StupidPoodle"

void LetPetsSpeak(Pet& p) {
    std::cout << p.speak() << std::endl;
}

int main (int argc, char** argv) {
    // Pet p("pet"); does not work, Pet is pure virtual.

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
