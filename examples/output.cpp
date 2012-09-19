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

	
	// if you want more complex outputs, it's best to use sprintf
	char out[64];
	sprintf(out, "Random number 1: %i, #2: %i", randomInt(0, 10), randomInt(20, 30));
	print(out);

	return 0;
}
