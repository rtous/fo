# scanf

## About the UNIX terminal 

By default, a UNIX-like terminal will collect input from the user until he presses Enter/Return. Then the whole line is pushed to your program (to its standard input stream, stdin). By default, stdin is buffered, i.e. the data is collected in a memory area called a "buffer". 

If you run the following program:

#include <stdio.h>

int main() {
	for (long long int i=0; i<5000000000; i++) {
		//do nothing
	}
}

The program does nothing, just takes some seconds to finish. During its execution you can type characters in the terminal. Each time you press Enter/Return the line is pushed to the stdin buffer (also the \n character). However, this program does nothing with the lines contained in the buffer. 

<!--

*NOTE: This default behavior (make data available to the program just when the user presses Enter/Return) is called canonical mode.*
--> 

## scanf

When the scanf function is called, it tries to read data from the stdin buffer. If the buffer does not have data, the program awaits. This gives the user the oportunity to type a new line into the terminal, feeding the buffer and letting scanf finish. For instance:

	int i;
	printf("Enter a number from 0 to 9 and press RETURN: ");
	scanf("%d", &i); 
	printf("You entered %d\n", i);

When scanf is called there's nothing in the buffer so the program awaits. Once the user types a number and presses RETURN the number and the \n character go into the buffer. Once scanf finds in the buffer the data it needs (one integer in this case) the program continues. In this example the \n character is not consumed by scanf and remains in the buffer till the end of the execution.

<!-- We can better understand the behavior of scanf with this program:

#include <stdio.h>

int main() {
	char c;
	for (long long int i=0; i<5000000000; i++) {
		//do nothing
	}
	while(1==1) {
		scanf("%c", &c);
		printf("%c", c);
	}
} 

Execute it an type two or three lines in the terminal while the first loop is looping. Then await and you will see how the second loop (infinite) will consume and display all the characters in the buffer (including the \n characters). 
-->
WARNING: If a previous scanf call did not empty the buffer, another scanf call may not await for any input from the terminal, it may just consume the remaining data.

WARNING: The \n character of the end of line is also stored within the buffer. If a scanf call does not consume it it will remain there.


	char c;
	scanf("%c", &c); 
	scanf("%c", &c);
	
	>a

The first scanf tries to read from an empty buffer so it makes the program to await. Once the user presses RETURN, the buffer receives the 'a' and the '\n' characters. Then scanf consumes the 'a' character but the '\n' remains there. The second call to scanf finds a character ('\n') so the program does not need to await and finishes.

# assignment suppression with '*'

The '*' modifier causes the corresponding input to be matched and converted, but not assigned. Example:

	scanf("%c%*c", &c1);

Will discard the end-of-line character at the end.

# whitespaces

 All specifiers with few exceptions (%c is one of them) skip the leading whitespaces (blanks and new-line characters) which might precede the value.

	 	int d1, d2;
		scanf("%d%d", &d1, &d2); 
		printf("%d%d", d1, d2);

		10      20
		1020

# strings %s

When used with the %s placeholder, scanf() only reads until the first white space character.
