/* Name: Tom's Tools
 * Author: Tom Shea
 * Behavior: Various helpful functions, mostly for interacting with the
 * user via command line.
 */
#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;

// include guard
#ifndef TOMTOOLS_INCLUDED
#define TOMTOOLS_INCLUDED


namespace tt
{
	// Did the last prompt fail? (is cin.fail() valid?)
	// if so, resets the input stream
	bool didPromptFail();

	// various prompting types
	
	
	
	// this is such a dirty hack, but
	// templates must be defined at the same time that they are
	// declared, because they are compiled on demand
	
	// gets input with no prompting (allows for custom prompts)
	template <typename T>
	void promptBlank(T &input)
	{	
		cin >> input;
	}

	// output the prompt, and input the specific type
	template <typename T>
	void prompt(T &input, string promptText)
	{
		T holder;
		do {
			cout << promptText + " ";
			promptBlank(holder);
		} while(didPromptFail());
		input = holder;
	}


	// yes/no questions
	bool promptYN(string prompt);

	// generate a random number between minInclusive and maxInclusive (inclusive, obviously)
	int randomInt(int minInclusive, int maxInclusive);
	// set the seed to the current time (effectively random enough)
	void seedRandom();

	// various outputs

	// convert anything to a string
	template <typename T>
	string toString(T value) 
	{
	        stringstream sstr;
	        sstr << value;
	        return sstr.str();
	}

	// Print the given string to cout followed by endl
	template <typename T>
	void print(T value)
	{
		cout << value << endl;
	}
	
	// Centered text surrounded by the decoration
	// text: "Hello World" decoration: '#' would look like
	// #####################################################
	// #                    Hello World                    #
	// #####################################################
	void boxBanner(string text, char decoration);
	// Centered text flanked by the decoration
	// #                    Hello World                    #
	void banner(string output, char decoration);
	// Centered text
	//                      Hello World                     
	void center(string text);
	// write <count> number of ' ' to cout
	void space(int count);
	// repeat the given char size times
	void repeatChar(char fill, int size);
	// write a line of the given char
	// ####################################################
	void fillLine(char fill);
	// the width in characters of the terminal, calculated using platform-specific calls
	// doesn't work on macs
	int termWidth();
}
#endif
