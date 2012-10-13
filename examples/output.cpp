#include "../tomtools.h"

using tt::print;
using tt::center;
using tt::banner;
using tt::boxBanner;
using tt::seedRandom;
using tt::randomInt;
using tt::toString;
// for the last example
#include <cstdio>

int main() {
	print("Hello World!");	
	print("");

	center("Hello World!");
	print("");

	banner("Hello World!", '#');
	print("");

	boxBanner("Hello World!", '#');
	print("");

	
	// random number stuff
	
	// these will always be the same every time because the seed hasn't been set
	int num1 = randomInt(0, 10);
	int num2 = randomInt(0, 10);

	print("Random number #1: " + toString(num1) + " , #2: " + toString(num2) );

	seedRandom();
	num1 = randomInt(0, 10);
	num2 = randomInt(0, 10);

	// this should be different almost every time
	print("Random number #1: " + toString(num1) + " , #2: " + toString(num2) );
	

	return 0;
}
