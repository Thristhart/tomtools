#include "../tomtools.h"

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
	
	// if you want more complex outputs, it's best to use sprintf
	char out[64];

	// this will always be the same output, every time it's run, because the seed hasn't been set
	sprintf(out, "Random number #1: %i, #2: %i", randomInt(0, 10), randomInt(20, 30));
	
	print(out);

	seedRandom();

	// this should be different almost every time
	sprintf(out, "Random number #1: %i, #2: %i", randomInt(0, 10), randomInt(20, 30));
	
	print(out);

	return 0;
}
