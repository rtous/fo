Open a terminal:

1) Install Homebrew if you don't have it already:
	```
	/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
	```
2) Install Java JDK 11 (NOTA: El plugin de C/C++ no funciona en versions posteriors)
	```
	brew install openjdk@11
	```
3) Install Netbeans:
	```
	wget https://archive.apache.org/dist/netbeans/netbeans/21/netbeans-21-bin.zip
	```
	```
	unzip netbeans-21-bin.zip
	```
4) Run Netbeans:
	```
	./netbeans/bin/netbeans --jdkhome /opt/homebrew/opt/openjdk@11
	```
4) El Plugin de C/C++ que hi ha no és el apropiat, cal agafar l'àntic així:

	Tools/Plugins/Settings

		activar enable Netbeans 8.2 Plugin Portal 

	Tools/Plugins/Updates 

		check for updates

	Tools/Plugins/Available Plugins 

		instalar C/C++ (el primer que surt)

