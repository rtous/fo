# Frequently Asked Questions 

## I have too many compilation errors, I don't know where to start :-(

Start from first error (the one at the top) and go one by one. It's important that you see the line numbers in your editor, otherwise configure it accordingly. 

You can also comment (with /* ... */) parts of your code to locate where the error is. 

## I change the code but gcc seems not to notice.

Ensure that the file that you are editing is the same that you are compiling. Typing "cat program.c" will show you the code that you are compiling.

## The program never ends, how can I stop it?

Press 'Ctrl' and 'C' at the same time. 

## scanf seems to be ignored or it gets the wrong input.

Probably something remains in the buffer from a previous scanf. Did you discard the end-of-line character ('%*c')? 

## error: warning: format specifies type 'int' but the argument has type 'int *'

Did you used '&' within a printf statement?

## error: non-ASCII characters are not allowed outside of literals and identifiers

Did you copy-pasted code from a .pdf? Re-type the quotes " and ' within the code, avoid accents. 

## gcc complains about the '*' symbol that I use within a multiplication expression.

The symbol is ok, probably there's a previous error. Did you you put a ';' at the end of a #define?

