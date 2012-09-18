/* Name: Tom's Tools
 * Author: Tom Shea
 * Behavior: Various helpful functions, mostly for interacting with the
 * user via command line.
 */
#include <string>
using std::string;

// include guard
#ifndef TOMTOOLS_INCLUDED
#define TOMTOOLS_INCLUDED

// Did the last prompt fail? (is cin.fail() valid?)
// if so, resets the input stream
bool didPromptFail();

// various prompting types
// output the prompt, and input the specific type
// when passed no arguments, simply gets input with no prompting (allows for custom prompts)
char promptChar(string prompt);
char promptChar();
int promptInt(string prompt);
int promptInt();
double promptDouble(string prompt);
double promptDouble();
float promptFloat(string prompt);
float promptFloat();
string promptString(string prompt);
string promptString();
// yes/no questions
bool promptYN(string prompt);

// various outputs

// Print the given string to cout followed by endl
void print(string text);
void print(int value);
void print(char value);
void print(float value);
void print(double value);
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
#endif
