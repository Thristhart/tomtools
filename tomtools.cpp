#include "tomtools.h"
#include <iostream>

// platform-specific stuff needed for termWidth()
#ifdef __linux__
	#include <sys/ioctl.h>
	#include <unistd.h>
#elif defined _WIN32 || _WIN64
	#include <windows.h>
#endif

using std::cout;
using std::cin;
using std::endl;

using std::string;

char promptChar(string prompt)
{
	cout << prompt + " ";
	return promptChar();
}
char promptChar() 
{
	char input = 0;
	cin >> input;
	// clear the input buffer to fix issues with combining >> and cin
	cin.ignore();
	return input;
}

int promptInt(string prompt)
{
	cout << prompt + " ";
	return promptInt();
}
int promptInt() 
{
	int input = 0;
	cin >> input;
	cin.ignore();
	return input;
}
double promptDouble(string prompt)
{ 
	cout << prompt + " ";
	return promptDouble();
}
double promptDouble() 
{
	double input = 0;
	cin >> input;	
	cin.ignore();
	return input;
}
float promptFloat(string prompt)
{
	cout << prompt + " ";
	return promptFloat();
}
float promptFloat()
{
	float input = 0;
	cin >> input;
	cin.ignore();
	return input;
}
string promptString(string prompt)
{
	cout << prompt + " ";
	return promptString();
}
string promptString()
{
	string input;
	getline(cin, input);
	return input;
}
bool promptYN(string prompt)
{
	while(true) {
		string textIn = promptString(prompt +  " [yes/no]");
		if(textIn == "y" || textIn == "yes" || textIn == "1")
			return true;
		if(textIn == "n" || textIn == "no" || textIn == "0")
			return false;
		cout << "Invalid input. Valid inputs include: yes, no, y, n, 1, 0." << endl;
	}
}

void print(string text) {
	cout << text << endl;
}
void print(int value)
{
	cout << value << endl;
}
void print(char value)
{
	cout << value << endl;
}
void print(float value)
{
	cout << value << endl;
}
void print(double value)
{
	cout << value << endl;
}
void print(bool value)
{
	cout << value << endl;
}

void boxBanner(string text, char decoration) 
{
	fillLine(decoration);
	banner(text, decoration);
	fillLine(decoration);
}

void banner(string text, char decoration) 
{
	int width = termWidth();
	int bufferSize = width / 2 - 1 - text.length() / 2;

	cout << decoration;
	space(bufferSize);
	cout << text;
	space(bufferSize);
	cout << decoration;
	cout << endl;
}
void center(string text) 
{
	int width = termWidth();
	int length = text.length();

	space(width / 2 - length / 2);

	cout << text << endl;
}
void space(int count) 
{
	repeatChar(' ', count);
}
void repeatChar(char fill, int size) 
{
	for(int i = 0; i < size; i++) {
		cout << fill;
	}
}
void fillLine(char fill) 
{
	repeatChar(fill, termWidth());
	cout << endl;
}
int termWidth() 
{
	#ifdef __linux__
		// http://www.delorie.com/djgpp/doc/libc/libc_495.html
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		return w.ws_col;
					
	#elif defined _WIN32 || _WIN64			
		// http://msdn.microsoft.com/en-us/library/windows/desktop/ms683171%28v=VS.85%29.aspx
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
			cerr << "Don't have permission to read the console screen buffer info." << endl;
		else
			return csbi.srWindow.Right-csbi.srWindow.Left;
	#else 
		// just in case we can't figure out what platform we're on, return a reasonable assumption
		return 80;
	#endif
}
