/**
 * TurtleProgram test driver.
 * 
 * @author Ryan Tran, Avery Mortenson, Jakob Wilter
 * @date 4/5/19
 */

#include "turtleprogram.h"
#include <iostream>

using namespace std;

int main()
{
	// testing constructors
	TurtleProgram tp1;
	cout << "tp1: " << tp1 << endl;
	
	TurtleProgram tp2("R", "90");
	cout << "tp2: " << tp2 << endl;
	
	TurtleProgram tp3("F");
	cout << "tp3: " << tp3 << endl;
	TurtleProgram tp4("10");
	cout << "tp4: " << tp4 << endl;
	
	TurtleProgram tp5(tp2);
	cout << "tp5 is a copy of tp2: " << tp5 << endl;
	
	// testing equivalency
	cout << boolalpha;
	cout << "tp5 == tp2: " << (tp5 == tp2) << endl;
	
	cout << "tp3 != tp4: " << (tp3 != tp4) << endl;
	
	// testing operations
	tp1 = tp3 + tp4;
	cout << "tp1 = tp3 + tp4: " << tp1 << endl;
	
	cout << "tp3 should print F: tp3 is " << tp3 << endl;
	
	tp1 += tp2;
	cout << "tp1 += tp2: " << tp1 << endl;
	
	TurtleProgram tp6;
	cout << "tp6: " << tp6 << endl;
	tp6 += tp1;
	cout << "tp6 += tp1: " << tp6 << endl;
	
	tp1 = tp2 * 3;
	cout << "tp1 = tp2 * 3: " << tp1 << endl;
	
	tp2 *= 3;
	cout << "tp2 *= 3: " << tp2 << endl;
	
	TurtleProgram tp7;
	cout << "tp7: " << tp7 << endl;
	tp7 *= 3;
	cout << "tp7 *= 3 (should be empty): " << tp7 << endl;
	
	//testing getters & setters
	cout << "tp5 before calling setIndex: " << tp5 << endl;
	
	cout << "index 0 of tp5: " << tp5.getIndex(0) << endl;
	
	tp5.setIndex(0, "F");
	tp5.setIndex(1, "10");
	cout << "setting index 0 to 'F' & index 1 to '10'." << endl;
	cout << "tp5 after 2 calls to setIndex: " << tp5 << endl;
	
	cout << "Done." << endl; 
	return 0; 
}
