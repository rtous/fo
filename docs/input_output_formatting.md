# Formatting input/output in C

## Format specifiers

A format specifier is a subsequence beginning with % and having the following prototype (optional parts between brackets):

'%' [FLAG] + [WIDTH] + [.PRECISION] + [LENGTH] + SPECIFIER 

### SPECIFIER

	c char single character
	d (%i) int signed integer
	e (%E) float or double exponential format
	f float or double signed decimal
	g (%G) float or double use %f or e as required
	o int unsigned octal value
	p pointer address stored in pointer
	s array of char sequence of characters
	u int unsigned decimal
	x (%X) int unsigned hex value

Examples with only the SPECIFIER:

	printf("%d", 2);
	$2

You can also add a LENGTH (e.g. 'l' to indicate a long form and 'h' to indicate a short form). For instance %ld indicates a long int and %hd indicate a short int.

Examples:

	long int l = 2147483648;
	printf("%ld", l);
	$2147483648 

### WIDTH

Will display a minimum of WIDTH characters in total (including the decimal part and also the sign if there is one). By default right justified and using white spaces instead of zeros at the left. By default no sign if positive.

Examples:

	printf("%4d", 21);
	$  21

With floating point numbers by default printf shows 6 decimal positions so specifying a small width does not have any effect: 

	printf("%4f", 3.14); 
	$3.140000

	printf("%4f", 3.14159265359);
	$3.141593

But:

	printf("%9f", 3.14159265359);
	$ 3.141593


### PRECISION

* For integer specifiers (e.g. %d) minimum number of digits to be written (padded with leading zeros if necessary).

Example:

	printf("%4.4d", 21);
	$0021

* For other number specifiers (e.g. %f) digits to be printed after the decimal point (by default, this is 6).

	Example:

	printf("%0.2f", 3.14159265359);
	$3.14

* For s: Maximum number of characters to be printed. 

### FLAG

	-		left justify
	+		always display sign
	space   positive numbers will include a leading space
	0		Left-pads the number with zeroes (0) instead of spaces 
	#		use alternate form of specifier (advanced)

Examples

	printf("%04d", 21);
	$0021

## Control codes

	\b backspace
	\f formfeed
	\n new line
	\r carriage return
	\t horizontal tab
	\' single quote
	\0 null