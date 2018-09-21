# scanf

## About the UNIX terminal 

By default, a UNIX-like terminal will collect input from the user until he presses Enter/Return. Then the whole line is pushed to your program (to its standard input stream, stdin). By default, stdin is buffered, i.e. the data is collected in a memory area called a "buffer".

## scanf

When the scanf function is called, it tries to read the necessary data from the stdin buffer. If the buffer does not have enough data, the program will await. This will give the user the oportunity to type a new line into the terminal, feeding the buffer and letting scanf finish. 

If a previous scanf call did not empty the buffer, another scanf call may not await for any input from the terminal, it may just consume the remaining data.

WARNING: The \n character of the end of line is also stored within the buffer. If a scanf call does not consume it it will remain there.


	char c;
	scanf("%c", &c); 
	scanf("%c", &c);
	
	>a

The first scanf tries to read from an empty buffer so it makes the program to await. Once the user presses RETURN, the buffer receives the 'a' and the '\n' characters. Then scanf consumes the 'a' character but the '\n' remains there. The second call to scanf finds a character ('\n') so the program does not need to await and finishes.

 