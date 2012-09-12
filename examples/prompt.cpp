#include <iostream>
#include "../tomtools.h"
#include <string>

using namespace std;

int main()
{
	string name = promptString("What's your name?");
	cout << "Hello, " + name + ".\n";
	char initial = promptChar("What's your last initial?");
	int age = promptInt("How old are you?");
	double gpa = promptDouble("What's your GPA?");
	
	cout << "Your name is " + name + " " + initial + ". and you are " << age << " years old, with a GPA of " << gpa << endl;
	if (promptYN("Is that correct?"))
		cout << "Yay!" << endl;
	else
		cout << "Aw. Are you sure?" << endl;
}
