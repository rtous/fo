# First steps

## Linux

Si tenéis Linux es probable que ya tengáis instalado GCC (el GNU Compiler Collection). Probad esto:

	gcc --version

En caso de que no esté instalado, haced lo siguiente (para Ubuntu):

Actualizamos:

	sudo apt-get update

Instalamos gcc y gdb:

	sudo apt-get install build-essential gdb

Probamos de nuevo:

	gcc --version


## Windows

Tradicionalmente recomendábamos la instalación de una máquina virtual con Ubuntu mediante VirtualBox o similares. No obstante, hoy día hay una opción mucho más cómoda, el Windows Subsystem for Linux (WSL):

### Instalar Windows Subsystem for Linux en Windows 10

1. Asegurarse de que el sistema está actualizado

2. Activar Windows Subsystem for Linux en Windows 10:

En la barra de búsqueda de Windows 10 (abajo a la izquierda) introducir "características de windows" y seleccionar "Activar o desactivar las características de Windows" (si el sistema está en inglés buscar "windows features"). Marcar la casilla de "Subsistema de Windows para Linux" y reiniciar el ordenador. 

ALTERNATIVA: Hay una forma alternativa de hacer esto mediante PowerShell. Buscamos "PowerShell", seleccionarlo y entrad el comando "dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart".


3. En el Microsoft Store buscad "Ubuntu 20" e instalad Ubuntu 20.04.LTS. 

4. Iniciamos y configuramos con el nombre de usuario y password que queramos.

### Instalar las herramientoas

Una vez dentro de Ubuntu:

Actualizamos:

	sudo apt-get update

Instalamos gcc y gdb:

	sudo apt-get install build-essential gdb

Probamos que funcione:

	gcc --version

Cerramos la ventana de Ubuntu (no la mantengáis abierta o fallará uno de los pasos siguientes)

### Instalar Visual Studio Code

1. Descargar e instalar de https://code.visualstudio.com/

2. Instalar la extensión "Remote - WSL": se nos propone al principio si detecta WSL. Si abrimos Extensions (Ctrl+Shift+X) y la buscamos allí.

3. Instalad la extensión C/C++. Buscad "C/C++". Instalad la de Microsoft (normalmente la primera que sale)

4. Cerrad y volver a abrir Visual Studio (o clicad en reload después de haber instalado la extensión)


### Editar desde WSL mediante Visual Studio Code 

Volver a abrir la aplicación Ubuntu
	
	mkdir projects
	cd projects
	mkdir helloworld
	cd helloworld
	code .



## Mac

