# Xcode for debugging command line C applications in macOS 

## Installation

### Try installing the latest version from the App Store first 

Xcode is available via the Mac App Store free of charge for macOS Catalina users (version 10.15.4 or higher). Try installing it from there, the App Store will check if you have the proper version.

### Installing an older version (if the previous step failed)  

First check the version of your macOS (click the Apple's icon in the top-left corner and select "About this Mac"). Then check which is the latest version of Xcode that your system supports [here](https://xcodereleases.com/) and download it. If you have problems with the download you can also find the proper Xcode version [here](https://developer.apple.com/download/more/?=xcode).

## Usage

In order to be able to debug a command line C program, it is necessary to do the following:

1) Menu File/New/Project
2) Switch to "macOS" tab
3) Select "Command Line Tool"
4) Set the properties:
	- Product Name = XcodeFO
	- Organization = UPC
	- Organization Identifier = UPC
	- Language = C

5) Select a directory to save the project. It will create a sub-directory named "XcodeFO".
6) Open main.c
7) Add a breakpoint in the first instruction of the main() function. You can do it just clicking at the beginning of the line (before the line number).
8) Ensure that the menu option Debug/Debug Workflow/Always Show Disassembly is disabled. 
9) Click the "build and run" button (the "play" icon).
10) Press FN+F6 to step over a line of code (or select the corresponding option within the Debug menu). 
11) At the bottom of the window you should see a panel with the variables and a panel with the Terminal.

Doing this for every FO exercise would be inefficient. The recommendation is to do it just once and copy-paste the code of your exercise within "main.c".