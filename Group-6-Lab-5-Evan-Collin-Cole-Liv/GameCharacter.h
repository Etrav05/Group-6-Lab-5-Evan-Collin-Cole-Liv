#pragma
#include <iostream>

#define SIZE 3

using namespace std;

class GameCharacter {
    string name;
    string* tool;

public:

    GameCharacter();

    GameCharacter(string& n, string* t);

    GameCharacter(GameCharacter& rhs);

    GameCharacter& operator=(GameCharacter& rhs);
};

GameCharacter foo1(GameCharacter p);

GameCharacter& foo2(GameCharacter& p);

GameCharacter foo3(GameCharacter& p);

GameCharacter& foo4(GameCharacter p);

GameCharacter& foo5(const GameCharacter& p);
