# First steps

## 1. Initial setup 

Boot the computer and select the Ubuntu image.

## 2. Working with the Linux Terminal

## 2.1 The filesystem

Open a Terminal (CTRL+ALT+T). By default, you will appear within your "home directory", a directory from the Ubuntu filesystem, which is like a tree:

	-|---- ... 
	 |      |
	 |      |---- YOUR HOME DIRECTORY  
	 | 
	...    

You can always know yor position within the tree by typing:

	pwd

You can list the contents of the current folder with:

	ls

You can always return to your home directory by typing (it does nothing if you are already there):

	cd

Or:

	cd $HOME

You can enter a folder (for instance the Downloads folder with):

	cd Downloads

You can go back to the parent folder with:

	cd ..

## 2.2 Use your keyboard

The following keys and combination of keys are essential for a productive usage of the Linux Terminal:

- TAB: Automatic completion of file names. Never type an entire file or folder name anymore.
- CTRL-A: Go to the beginning of the line.
- CTRL-E: Go to the end of the line.
- CTRL-U: Delete the line.
- CTRL-Shift-C: Copy from the Terminal (Ubuntu).
- CTRL-Shift-V: Copy into the Terminal (Ubuntu). 

## 3. Setup folders and files for the session

Open the browser, go to http://atenea.upc.edu and enter the FO METACURS:
- Open the proper lab session description PDF.
- Click the required files link to download them (into the default location, the "Downloads" folder).

The session's required files have been downloaded into the "Downloads" folder:

	-|---- ... 
	 |      |
	 |      |---- YOUR HOME DIRECTORY  
	 |                    |
	...                   |---- Downloads 
	                               |
	                               |------ sesion1_ficheros_requeridos_20182019Q1.tar

We will first copy them to the root of your home directory with this command (executed from you home directory):

	cp Downloads/sesion1_ficheros_requeridos_20182019Q1.tar .

Then we will decompress the file with the following command:

	tar xvf sesion1_ficheros_requeridos_20182019Q1.tar

The previous command did decompress the required files into a folder with the same name as the compressed file. We will use this folder to put all the work done during the session. Let's change the name of the folder this way:

	mv sesion1_ficheros_requeridos_20182019Q1 sesion1

## 4. Generating and executable file

Let's enter the "sesion1" folder:

	cd sesion1

Let's see the required files:

	ls

You can perform a fast inspection of a file with the "cat" command:

	cat sesion1_ej1.c

You can already compile (and link) the file this way:

	gcc sesion1_ej1.c –o sesion1_ej1

And run the generated executable this way (the "." means the "current folder"):

	./sesion1_ej1

## 5. Editing the source code

The "cat" command does not let you edit the file. You can edit the file with, for instance, "gedit":

	gedit sesion1_ej1.c &

The "&" symbol enables that you continue using the terminal after the execution of "gedit", otherwise the terminal will await "gedit" to finish and you will need another terminal to run commands.

Let's perform a small change to the code, for instance le'ts change the following line:

	a = 10;

With:

	a = b;

Let's recompile and run the program again. You should see the following output:

	 a = b    b = 2

## 6. Compiling and linking

The "gcc" command from the previous steps did many things at the same time:
- It compiled the C source code into an object file containing machine code but still not executable.
- It linked the object file into an executable file. 

We can ask gcc to perform those steps one-by-one. In order to just compile use the "-c" option:

	gcc -c sesion1_ej1.c -o sesion1_ej1.o

In order to link the object file you use the plain gcc command:

	gcc sesion1_ej1.c -o sesion1_ej1

This two-step process make more sense when you think in programs that involve two or more source files. All the files are first compiled into separate object files and then they are all linked into a single executable file. 

Let's edit a new file, named sesion1_ej2.c, with the following contents:

		#include <stdio.h>
		#include "colours.h"

		main()
		{
			cambiar_color(GREEN);
			printf("\n Hola Mundo ! \n");
			cambiar_color(DEFAULT);
		}

This code depends on another source file, colours.c, which contains some useful functions. In order to be able to compile sesion1_ej2, you need first to download a header file (colours.h), a text file with some information about the functions contained within colours.c. You can download colours.h this way:

	wget 

	gcc -c sesion1_ej2.c -o sesion1_ej2.o


	gcc -c colours.c -o colours.o
	gcc colours.o sesion1_ej2.o -o sesion1_ej2



## 7. Preparing your files to deliver them through Atenea

In order to deliver your files through Atenea you first need to compress a folder containing all of them. Let's move to the parent directory of the working directory:

	cd ..

Now if you do an "ls" you should see the "sesion1" folder in the list. Now compress that folder with the following command:

	tar cvf sesion1.tar sesion1 

You can list the contents of the created tar (without decompressing it) with:

	tar -tvf sesion1.tar

## 8. Debugging the code with Nemiver

Using a debugger could seem not necessary at this point, as you can debug your first programs with print statements or by commenting parts of your code. However, debugging will be the task to which you will invest the most part of your time as a programmer, and it's important to do it efficiently. So, it's recommended to start using a debugger from the very beginning. 

Professional programmers usually edit and debug their code with an Integrated Development Environment such as NetBeans, Visual Studio Code, etc. However, here it will be more productive to make use of a more lightweight tool like Nemiver. 

In order to be able to debug a C program with Nemiver you need to add "-g" option when compiling:

	cd sesion1
	gcc sesion1_ej1.c –o sesion1_ej1 -g

To start debuggint the program you just need to execute:

	nemvier sesion1_ej1

Once you see the Nemiver window, make sure that you see the Context panel at the bottom (where you can see the value of the different variables). If not, let's click the Contex tab (at the botton) or select the proper option from the View menu. 

For now, it's enough if you run a few steps of the program (with F7) and check that the value of the variables change in the Context window. 

You can find a Nemiver tutorial in spanish [here](https://atenea.upc.edu/pluginfile.php/2931681/mod_resource/content/8/Nemiver.pdf).







