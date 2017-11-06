# Debugging C code with NetBeans and GDB on OSX

## Step 1: Create a code signing certificate

Perform the following steps:

	- Using the search box of the Launchpad search and open the Keychain Access app ("Acceso a Llaveros").
	- In the main menu (KeyChainAccess) select Certificate Assistant/Create a Certificate...
	- name = gdb-cert, identity type = self signed root, type = code signing, let me override defaults = true
	- Validity period = 3650
	- Accept the default option for the rest of questions
	- Specify a Location For The Certificate =  Keychain to System
	- In keychains select “System” and search your new certificate ("gdb-cert"). Use the context menu for the certificate, select “Get Info”, open the “Trust” item, and set “Code Signing” to “Always Trust”.
	- It's recommended to reboot your mac at this point (alternatively you can try closing the Keychain Access app and typing "sudo pkill taskgated" in the terminal).

## Step 2: Install and configure GDB

In order to install GDB you'll need to have Homebrew installed. If you don't, just do:

	/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

Let's install GDB:

	brew install gdb

Sign GDB this way:

	codesign -s gdb-cert /usr/local/bin/gdb

Create a .gdbinit file in your home directory (/Users/YOUR_USER) with the following content:

	set startup-with-shell off

## Step 3: Install and configure NetBeans

	- Download and install NetBeans for Mac (https://netbeans.org/downloads/). Be sure to select the C/C++ version.	
	- Create a new project (C++ Application) and try to debug it.
	- NetBeans will ask for a debugger command. Type this one: /usr/local/bin/gdb




