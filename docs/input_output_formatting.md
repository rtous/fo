# Formatting input/output in C

## Format specifiers

A format specifier is a subsequence beginning with % and having the following prototype (optional parts between brackets):

'%' [FLAG] + [WIDTH] + [.PRECISION] + [LENGTH] + SPECIFIER 

### SPECIFIER

	%c char single character
	%d (%i) int signed integer
	%e (%E) float or double exponential format
	%f float or double signed decimal
	%g (%G) float or double use %f or %e as required
	%o int unsigned octal value
	%p pointer address stored in pointer
	%s array of char sequence of characters
	%u int unsigned decimal
	%x (%X) int unsigned hex value

Examples with only the SPECIFIER:

	printf("%d", 2); ->2

You can also add a LENGTH (e.g. 'l' to indicate a long form and 'h' to indicate a short form). For instance %ld indicates a long int and %hd indicate a short int.

### WIDTH

Will display a minimum of WIDTH characters in total (including the decimal part and also the sign if there is one). By default right justified and using white spaces instead of zeros at the left. By default no sign if positive.

### PRECISION

* For integer specifiers (d, i, o, u, x, X) specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.

* For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).

* For g and G specifiers: This is the maximum number of significant digits to be printed.

* For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.
If the period is specified without an explicit value for precision, 0 is assumed.


* Will display PRECISION digits after the decimal point (even the zeros at the right). 

### FLAG

	-		left justify
	+		always display sign spaces	display space if there is no sign
	0		Left-pads the number with zeroes (0) instead of spaces 
	#		use alternate form of specifier

### Typical examples

	printf("%0.2f", 3.1412);
	3.14

	printf("%04d", 21);
	0021

	long int l = 2147483648;
	printf("%ld", l);
	2147483648

## Control codes

	\b backspace
	\f formfeed
	\n new line
	\r carriage return
	\t horizontal tab
	\' single quote
	\0 null