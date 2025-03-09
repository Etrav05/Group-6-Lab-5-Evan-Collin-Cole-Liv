#include "GameCharacter.h" 

// Evan
// Liv
// Collin

using namespace std;

// Question 7. 
// The copy costructor will be called a total of 5 times, 4 of which are from the foo functions
// 
// A copy constructer is called when the function itself or the object passed through it are NOT references to an object
// Given this, we can see that foo1 will call the copy constructor 2 times ass its function and passed object are both new,
// foo2 will not call the copy constructor as it is the opposite, foo3 will call it once when creating the new object,
// foo4 will call it once aswell due to the object being returned having to be copied, and lastly foo5 wont call the copy 
// construtor for the same reason as foo2, BUT it will call the default constructor to create the new "gc" object

int main() {
	GameCharacter p1; // default constructer called
	GameCharacter p2 = p1; // copy constructer called

	p1 = p2; // assignement constructer called

	// Question 6. 
	foo1(p1); // copy constructer calls: 2
	foo2(p1); // copy constructer calls: 0
	foo3(p1); // copy constructer calls: 1
	foo4(p1); // copy constructer calls: 1
	foo5(p1); // copy constructer calls: 0
}