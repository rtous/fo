# Configurar Visual Studio Code per depurar codi C/C++ 


## Instal·lar les extensions necessàries:

- Fer click a la icona d'extensions que apareix a l'esquerra (la darrera)
- Instal·lar l'extensió C/C++ de Microsoft
- Instal·lar l'extensió Code Runner
- (recomanable) Instal·lar l'extensió C++ Intellisense 

## Modificar les preferències (Windows)

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

## Modificar les preferències (Mac)


- NOTA: Si no teniu el gcc instal·lat, la manera més ràpida de fer-ho és instal·lant XCode. En realitat el gcc que ve amb XCode apunta al compilador llvm/clang, que no és el gcc "oficial" però per les pràctiques d'FO serà més que suficient. Si pel que sigui voleu el gcc oficial ho podeu fer mitjançant homebrew.
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

