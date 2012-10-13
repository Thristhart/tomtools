#include <iostream>
#include "../tomtools.h"
#include <string>

using namespace std;

using tt::prompt;
using tt::promptYN;

int main()
{
	string name;
	char initial;
	int age;
	double gpa;


       	prompt(name, "What's your name?");
	cout << "Hello, " + name + ".\n";
	prompt(initial, "What's your last initial?");
	prompt(age, "How old are you?");
	prompt(gpa, "What's your GPA?");
	
	cout << "Your name is " + name + " " + initial + ". and you are " << age << " years old, with a GPA of " << gpa << endl;
	if (promptYN("Is that correct?"))
		cout << "Yay!" << endl;
	else
		cout << "Aw. Are you sure?" << endl;
	return 0;
}
