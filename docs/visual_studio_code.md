# Configurar Visual Studio Code per depurar codi C/C++ 

## A les aules de l'ETSETB

A les aules de l'ETSETB ja teniu instal·lat el Visual Studio Code per Ubuntu. No obstant, us cal configurar la depuració de codi C/C++ de la següent manera:

### Instal·lar les extensions necessàries:

- Fer click a la icona d'extensions que apareix a l'esquerra (la darrera)
- Instal·lar l'extensió C/C++ de Microsoft
- Instal·lar l'extensió Code Runner
- (recomanable) Instal·lar l'extensió C++ Intellisense 

### Modificar les preferències 

- Menú Preferences/Settings 
- Fer clic als punts suspensius i seleccionar "open settings.json"
- A la finestra de la dreta (USER SETTINGS) sobreescriure el que hi hagi amb el següent contingut:

		{
		    "launch": {
		        "version": "0.2.0",
		        "configurations": [
		            {
		                "name": "C++ Launch",
		                "type": "cppdbg",
		                "request": "launch",
		                "program": "${fileDirname}/${fileBasenameNoExtension}",
		                "args": [],
		                "stopAtEntry": false,
		                "cwd": "${fileDirname}",
		                "environment": [],
		                "externalConsole": true,
		                "MIMode": "gdb"
		            }
		        ]
		    }
		} 

## A casa si treballeu amb Mac

Us cal fer el mateix que l'explicat a la secció anterior amb les següents consideracions:

- Si no teniu el gcc instal·lat, la manera més ràpida de fer-ho és instal·lant XCode. En realitat el gcc que ve amb XCode apunta al compilador llvm/clang, que no és el gcc "oficial" però per les pràctiques d'FO serà més que suficient. Si pel que sigui voleu el gcc oficial ho podeu fer mitjançant homebrew.
- El fitxer de settings cal que sigui així:

		{
		    "launch": {
		        "version": "0.2.0",
		        "configurations": [
		            {
		                "name": "C++ Launch",
		                "type": "cppdbg",
		                "request": "launch",
		                "program": "${fileDirname}/${fileBasenameNoExtension}",
		                "args": [],
		                "stopAtEntry": false,
		                "cwd": "${fileDirname}",
		                "environment": [],
		                "externalConsole": true,
		                "MIMode": "lldb"
		            }
		        ]
		    }
		} 

## Com depurar?

- Compilar amb l'opció -g ("gcc -g programa.c ...")
- Al Visual Studio Code seleccionar el programa que volem depurar.
- Clicar l'icona de depuració. 
- Posar algun breakpoint (o s'executarà tot el programa). 
- Clicar l'icona verda de play que apareix a dalt a l'esquerra.
- Haurien d'aparèixer les icones de depuració.
- A classe se us explicarà com fer-les servir.

