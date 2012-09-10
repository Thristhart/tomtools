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

// various prompting types
// output the prompt, and input the specific type
int promptInt(string prompt);
double promptDouble(string prompt);
float promptFloat(string prompt);
string promptString(string prompt);
// yes/no questions
bool promptYN(string prompt);

// various outputs

// Print the given string to cout followed by endl
void print(string text);
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
