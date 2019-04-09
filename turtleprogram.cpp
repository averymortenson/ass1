/**
 * TurtleProgram cpp file.
 *
 * @author Ryan Tran, Jakob Wilter, Avery Mortenson
 * @date 4/5/19
 */

#include "turtleprogram.h"

/**
Default Constructor
-------------------
Initializes the instructions array.

Parameters
----------
None.
**/
TurtleProgram::TurtleProgram()
{
	instructions = new string[1];
	numInstructions = 0;
}

/**
Constructor with One Parameter
------------------------------
Initializes the instructions array with one string.

Parameters
----------
str: a string.
**/
TurtleProgram::TurtleProgram(string str)
{
	instructions = new string[1] {str};
	numInstructions = 1;
}

/**
Constructor with Two Parameters
-------------------------------
Initializes the instructions array with two strings.

Parameters
----------
str1: the first string.
str2: the second string.
**/
TurtleProgram::TurtleProgram(string str1, string str2)
{
	instructions = new string[2] {str1, str2};
	numInstructions = 2;
}

/**
Copy Constructor
----------------
Copies the specified TurtleProgram.

Parameters
----------
o: TurtleProgram to copy.
**/
TurtleProgram::TurtleProgram(TurtleProgram& o)
{
	instructions = new string[o.getLength()];
	numInstructions = o.getLength();
	for (int i = 0; i < numInstructions; i++)
	{
		instructions[i] = o.getIndex(i);
	}
}

/**
Destructor
----------
Deallocates the instructions array.
**/
TurtleProgram::~TurtleProgram()
{
	delete[] instructions;
}

/**
Function
--------
Compares the instructions arrays of this TurtleProgram and the specified TurtleProgram for equivalence.

Parameters
----------
o: the TurtleProgram to compare with.

Return
------
bool; true if this TurtleProgram's instructions array contains all of the same strings as the specified TurtleProgram's instructions array, false
otherwise.
**/
bool TurtleProgram::operator==(TurtleProgram& o)
{
	if (numInstructions == o.getLength())
	{
		for (int i = 0; i < numInstructions; i++)
		{
			if (instructions[i] != o.getIndex(i))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

/**
Function
--------
Compares the instructions arrays of this TurtleProgram and the specified TurtleProgram for unequivalence.

Parameters
----------
o: the TurtleProgram to compare with.

Return
------
bool; true if this TurtleProgram's instructions array DOES NOT contain all of the same strings as the specified TurtleProgram's instructions array, false
otherwise.
**/
bool TurtleProgram::operator!=(TurtleProgram& o)
{
	if (numInstructions == o.getLength())
	{
		for (int i = 0; i < numInstructions; i++)
		{
			if (instructions[i] != o.getIndex(i))
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

/**
Function
--------
Sets this TurtleProgram's instructions array as the specified instructions array.

Parameters
----------
o: the specified instructions array.

Return
------
this; this TurtleProgram, but with a new instructions array that is a equal to the specified instructions array.
**/
TurtleProgram& TurtleProgram::operator=(TurtleProgram* o)
{
	string* prevInstructions = instructions;	// old instructions array.
	
	instructions = new string[o->getLength()];	// new instructions array.
	numInstructions = o->getLength();
	
	for (int i = 0; i < numInstructions; i++)
	{
		instructions[i] = o->getIndex(i);
	}
	
	delete o;
	delete[] prevInstructions;
	return *this;
}

/**
Function
--------
Concatenates (combines) this TurtleProgram's instructions array and the specified TurtleProgram's instructions array.

Parameters
----------
o: the TurtleProgram to combine with.

Return
------
TurtleProgram*; pointer to a new TurtleProgram with an instructions array that is a combination of this TurtleProgram's instructions array and the specified
TurtleProgram's instructions array.  
**/
TurtleProgram* TurtleProgram::operator+(TurtleProgram& o)
{	
	TurtleProgram* tp = new TurtleProgram();	// creates a TurtleProgram with an empty instructions array.
	
	int currIndex = 0;	// index of the new instructions array.
	for (int i = 0; i < numInstructions; i++)
	{
		tp->setIndex(currIndex, instructions[i]);	// setIndex resizes the array whenever the current index equals the size limit (numInstructions).
		currIndex++;
	}
	
	for (int i = 0; i < o.getLength(); i++)
	{
		tp->setIndex(currIndex, o.getIndex(i));
		currIndex++;
	}
	
	return tp;
}

/**
Function
--------
Concatenates (combines) this TurtleProgram's instructions array and the specified TurtleProgram's instructions array.

Parameters
----------
o: the TurtleProgram to combine with.

Return
------
this; this TurtleProgram, but with a new instructions array that is a combination of the old instructions array and the specified TurtleProgram's instructions
array.
**/
TurtleProgram& TurtleProgram::operator+=(TurtleProgram& o)
{
	string* prevInstructions = instructions;	// old instructions array.
	int numPrevInstructions = numInstructions;
	
	instructions = new string[numPrevInstructions + o.getLength()];	// new instructions array.
	numInstructions = numPrevInstructions + o.getLength();
	
	int currIndex = 0;	// index of the new instructions array.
	for (int i = 0; i < numPrevInstructions; i++)
	{
		instructions[currIndex] = prevInstructions[i];
		currIndex++;
	}
	
	for (int i = 0; i < o.getLength(); i++)
	{
		instructions[currIndex] = o.getIndex(i);
		currIndex++;
	}
	
	delete[] prevInstructions;
	return *this;
}

/**
Function
--------
Multiplies this TurtleProgram's instructions array by the specified factor. Repeats the strings in the instructions array a number of times equal to the
specified factor.

Parameters
----------
factor: the integer factor to multiply by.

Return
------
TurtleProgram*; pointer to a new TurtleProgram with an instructions array equal to this TurtleProgram's instructions array multiplied by the specified factor. 
**/
TurtleProgram* TurtleProgram::operator*(int factor)
{
	TurtleProgram* tp = new TurtleProgram(); // creates a TurtleProgram with an empty instructions array.
	
	int currIndex = 0;		// index of the new instructions array.
	int thisIndex = 0;		// index of this TurtleProgram's instructions array.
	int repetitions = 0;	// number of times the instructions array has been repeated.
	while (repetitions != factor)
	{
		tp->setIndex(currIndex, instructions[thisIndex]);	// setIndex resizes the array whenever the current index equals the size limit (numInstructions).
		
		currIndex++;
		thisIndex++;
		
		if (thisIndex == numInstructions)	// resets thisIndex when the size limit is reached to repeat the instructions, increments the repetition count.
		{
			thisIndex = 0;
			repetitions++;
		}
	}
	
	return tp;
}

/**
Function
--------
Multiplies this TurtleProgram's instructions array by the specified factor. Repeats the strings in the instructions array a number of times equal to the
specified factor.

Parameters
----------
factor: the integer factor to multiply by.

Return
------
this; this TurtleProgram, but with a new instructions array equal to the old instructions array multiplied by the specified factor.
**/
TurtleProgram& TurtleProgram::operator*=(int factor)
{
	if (numInstructions == 0)	// if the instructions array is empty, skip the operation.
	{
		return *this;
	}
	
	string* prevInstructions = instructions;	// old instructions array.
	int numPrevInstructions = numInstructions;
	
	instructions = new string[numPrevInstructions * factor];	// new instructions array.
	numInstructions = numPrevInstructions * factor;
	
	int currIndex = 0;		// index of the new instructions array.
	int prevIndex = 0;		// index of this TurtleProgram's instructions array.
	int repetitions = 0;	// number of times the instructions array has been repeated.
	while (repetitions != factor)
	{
		instructions[currIndex] = prevInstructions[prevIndex];
		
		currIndex++;
		prevIndex++;
		
		if (prevIndex == numPrevInstructions)	// resets thisIndex when the size limit is reached to repeat the instructions, increments the repetition count. 
		{
			prevIndex = 0;
			repetitions++;
		}
	}
	
	delete[] prevInstructions;
	return *this;
}

/**
Function
--------
Obtains the size of the instructions array.

Parameters
----------
None.

Return
------
int; the size of the instructions array. 
**/
int TurtleProgram::getLength()
{
	return numInstructions;
}

/**
Function
--------
Obtains the string at the specified index of the instructions array.

Parameters
----------
index:	the index to return.

Return
------
string; the string at the specified index.
**/
string TurtleProgram::getIndex(int index)
{
	return instructions[index];
}

/**
Function
--------
Sets the string at the specified index of the instructions array to a new string.

Parameters
----------
index:	the index to alter.
str:	the new string.

Return
------
None.
**/
void TurtleProgram::setIndex(int index, string str)
{
	if (index == numInstructions)	// updates the size of the instructions array if the specified index is equal to the size of the array (numInstructions).
	{
		string* newInstructions = new string[numInstructions + 1];	// the new instructions array is 1 index larger than the old array.
		
		for (int i = 0; i < numInstructions; i++)	// copy the elements of the old instructions array into to the new one.
		{
			newInstructions[i] = instructions[i];
		}
		delete[] instructions;
		instructions = newInstructions;
		numInstructions++;
	}
	instructions[index] = str;	// the specified string is inserted into the last index of the new instructions array.
}

/**
Function
--------
Prints out the instructions array of a TurtleProgram when the ostream outputs a TurtleProgram, e.g. cout << (some TurtleProgram) << endl;
Example of how the output is formatted: [F 10]

Parameters
----------
output: reference to the output stream.
tp: 	reference to the TurtleProgram with the instructions to print.

Return
------
reference to the output stream, i.e. an output string.
**/
ostream& operator<<(ostream& output, TurtleProgram& tp)
{
	output << "[";
	for (int i = 0; i < tp.getLength(); i++)
	{
		if (i == 0)
		{
			output << tp.getIndex(i);
		}
		else
		{
			output << " " << tp.getIndex(i);
		}
	}
	output << "]";
	
	return output;
}
