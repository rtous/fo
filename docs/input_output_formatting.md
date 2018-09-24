# Formatting input/output in C

## Format specifiers

A format specifier is a subsequence beginning with % and having the following prototype (optional parts between brackets):

'%' [FLAG] + [WIDTH] + [.PRECISION] + [LENGTH] + SPECIFIER 

### SPECIFIER

	c char single character
	d (also i) int signed integer
	u int unsigned decimal
	f float or double signed decimal
	s array of char sequence of characters
	x (X for uppercase) int unsigned hex value
	e (E for uppercase) float or double exponential format
	g (G for uppercase) se the shortest representation (%e or %f)
	o unsigned octal value
	p pointer address stored in pointer


Examples with only the SPECIFIER:

	printf("%d", 2);
	$2

You can also add a LENGTH (e.g. 'l' to indicate a long form and 'h' to indicate a short form). For instance %ld indicates a long int and %hd indicate a short int.

Examples:

	long int l = 2147483648;
	printf("%ld", l);
	$2147483648 

### WIDTH

Minimum number of CHARACTERS to be shown in total (including the decimal part, the sign if there is one and white spaces). By default right justified and using white spaces instead of zeros at the left. By default no sign if positive.

Examples:

	printf("%4d", 21);
	$  21

With floating point numbers by default printf shows 6 decimal positions so specifying a small WIDTH does not have any effect (as WIDTH specifies the minimum, not the maximum): 

	printf("%4f", 3.14); 
	$3.140000

	printf("%4f", 3.14159265359);
	$3.141593

But:

	printf("%9f", 3.14159265359);
	$ 3.141593


### PRECISION

While the WIDTH is about the number of CHARACTERS to be shown, the PRECISION is about the DIGITS to be shown:

* For integer specifiers (e.g. %d) minimum number of digits to be written (padded with leading zeros if necessary).

Example:

	printf("%.4d", 21);
	$0021

	printf("%5.4d", 21);
	$ 0021

* For other number specifiers (e.g. %f) digits to be printed after the decimal point (by default, this is 6).

Example:

	printf("%.2f", 3.14159265359);
	$3.14

	printf("%4.2f", 3.14159265359);
	$ 3.14

* For s: Maximum number of characters to be printed. 

### FLAG

	0		Left-pads the number with zeroes (0) instead of spaces
	-		left justify
	+		always display sign
	space   positive numbers will include a leading space 
	#		use alternate form of specifier (advanced)

Examples

	printf("%04d", 21);
	$0021

	 printf("%05.2f\n", 3.14159265359);
	 $03.14

## Control codes

	\b backspace
	\f formfeed
	\n new line
	\r carriage return
	\t horizontal tab
	\' single quote
	\0 null