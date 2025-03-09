#include "GameCharacter.h"

using namespace std;

GameCharacter::GameCharacter() : name("Miner"), tool(new string[SIZE]) { // using the new concept of initalizer list
    tool[0] = "pickaxe"; // default constructor with hardcoded parameters, initializing the miner and tools
    tool[1] = "shovel";
    tool[2] = "bow";

    cout << "The default constructor is called" << endl;
}

GameCharacter::GameCharacter(string& n, string* t) : name(n), tool(new string[SIZE]) { // parameterized constructor
    for (int i = 0; i < SIZE; ++i) { // for all inputted tools, add them to the tool attribute
        tool[i] = t[i];
    }

    cout << "The parameterized constructor is called" << endl;
}

GameCharacter::GameCharacter(GameCharacter& rhs) : name(rhs.name), tool(new string[SIZE]) { // copy constructor
    name = rhs.name; // the new objects name is the name of the old one
    
    for (int i = 0; i < SIZE; ++i) {
        tool[i] = rhs.tool[i]; // each tool of the new object now the tool of the existing one
    }

    cout << "The copy constructor is called" << endl;
}

GameCharacter& GameCharacter::operator=(GameCharacter& rhs) { // assignment operator
    if (this != &rhs) {
        name = rhs.name; // the name on the left now is = name on the right

        delete[] tool;           // free the existing tool
        tool = new string[SIZE]; // make a new tool

        for (int i = 0; i < SIZE; ++i) {
            tool[i] = rhs.tool[i];  // the left tool now = the right tool
        }    
    }

    cout << "The assignment constructor is called" << endl;
    return *this;
}

GameCharacter foo1(GameCharacter p) {
    return p; // calls the copy constructor to both create a new object which is a copy of the object passed into foo
}             // then to return a copy of the object passed

GameCharacter& foo2(GameCharacter& p) {
    return p; // doesnt used the copy constructor because the new object is an alias of the passed object 
}             // then the passed objects alias can be returned instead of a copy

GameCharacter foo3(GameCharacter& p) {
    return p; // called the copy constructor to create the new object, copying the object passed
}             // then the passed objects alias can be returned (not a copy)

GameCharacter& foo4(GameCharacter p) {
    return p; // doesnt call the copy constructer to make the new object because its an alias
}             // then calls the copy constructor to return a copy of the passed object

GameCharacter& foo5(const GameCharacter& p) {
    GameCharacter gc; // doesnt call the copy constructer because its completely aliases
    return gc;        // but it creates a default object "gc" then returns it
}
