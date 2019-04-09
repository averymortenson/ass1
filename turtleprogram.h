/**
 * TurtleProgram header file.
 *
 * @author Ryan Tran
 * @date 4/5/19
 */

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <iostream>
#include <string>

using namespace std;

class TurtleProgram {
	friend ostream& operator<<(ostream& output, TurtleProgram& tp);
	
	public:
		// constructors & destructor
		TurtleProgram();
		TurtleProgram(string str);
		TurtleProgram(string str1, string str2);
		TurtleProgram(TurtleProgram& o);
		~TurtleProgram();
		
		// operation functions
		bool operator==(TurtleProgram& o);
		bool operator!=(TurtleProgram& o);
		TurtleProgram& operator=(TurtleProgram* o);
		TurtleProgram* operator+(TurtleProgram& o);
		TurtleProgram& operator+=(TurtleProgram& o);
		TurtleProgram* operator*(int factor);
		TurtleProgram& operator*=(int factor);
		
		// getters & setters
		int getLength();
		string getIndex(int index);
		void setIndex(int index, string str);
		
	private:
		string* instructions;		// array of strings.
		int numInstructions;	// size of the instructions array.
};

#endif // TURTLEPROGRAM_H

