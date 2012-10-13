tomtools
========

Useful tools for simple C++ operations

Prompting
=========

Use these to get typed data from the user.

Simply get the user input without any prompt output.
> promptBlank(<type> input)

Outputs the given string, followed by a space,
then waits for the user to input data and returns it.
> prompt(<type> input, string prompt)

Outputs the string followed by " [yes/no]" and will only accept: yes, y, 1, no, n, 0

Returns as a bool
> promptYN(string prompt)

Random
======
Generates a pseudorandom number between the given ints. (inclusive)

> randomInt(int minInclusive, int maxInclusive)

Sets the random seed to the current time (which is random enough for most needs)

> seedRandom()

Output
======
See tomtools.h for visuals of what these outputs look like.

Simply output the given text to cout followed by endl (overloaded for outputting float, double, char, int as well)
> print(string text)

Centered text, surrounded by the decoration
> boxBanner(string text, char decoration)

Centered text, flanked by the decoration
> banner(string text, char decoration)

Centered text
> center(string text)

Platform-specific functions for determining the width in characters of the terminal.
Doesn't work on macs.
> termWidth()

Write out an amount of spaces equal to count
> space(int count)

Repeat the given char a number of times
> repeatChar(char fill, int size)

Write a line consisting entirely of the given char
> fillLine(char fill);
