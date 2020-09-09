# Programar en GCC en Windows 10 mediante WSL y Visual Studio Code

Una alternativa muy productiva para programar en C/C++ sobre Windows 10 es hacerlo mediante Windows Subsystem for Linux (WSL). Un inconveniente es que editar los ficheros fuente (mediante un GUI Windows o Linux) no es trivial. Afortunadamente, existe una extensión que permite hacerlo mediante Visual Studio Code, el entorno de programación más utilizado según el Stack Overflow 2019 Developer Survey.

NOTA: Este tutorial es una versión "expresso" del que hay [aquí](https://code.visualstudio.com/docs/cpp/config-wsl). Echadle un vistazo si tenéis problemas o queréis más detalles.

## 1 Instalar Windows Subsystem for Linux (WSL) en Windows 10

## 1.1 Activar la característica Windows Subsystem for Linux en Windows 10

En la barra de búsqueda de Windows 10 (abajo a la izquierda) introducid "características de windows" y seleccionad "Activar o desactivar las características de Windows" (si el sistema está en inglés buscar "windows features"). Marcad la casilla de "Subsistema de Windows para Linux" y reiniciar el ordenador. 

## 1.2 Instalar Ubuntu 18.04

En el Microsoft Store buscad "Ubuntu 18" e instalad la aplicación Ubuntu 18.04.LTS. 

## 1.3 Configurar Ubuntu 18.04

Lanzad la aplicación Ubuntu 18.04 y configurad un nombre de usuario y password fáciles de recordar. A continuación, ya dentro de Ubuntu, ejectutad el siguiente comando:

	sudo apt-get update

Y lo siguiente para instalar GCC (y el depurador GDB):

	sudo apt-get install build-essential gdb

Probad que ha funcionado ejecutando:

	gcc --version

Ya podéis compilar programas en C y ejecutarlos, pero para poderlos editar cómodamente será necesario instalar y configurar Visual Studio Code.

Cerrad la ventana de Ubuntu (no la mantengáis abierta o fallará uno de los pasos siguientes).

### 2 Instalar Visual Studio Code 

1. Descargad e instalad de [aquí](https://code.visualstudio.com/)

2. Cuando arranque Visual Studio Code instalad la extensión "Remote - WSL". Veréis que Visual Studio Code os lo propone al arrancar y ver que tenéis instalado WSL. Si no fuera así, abrid Extensions (Ctrl+Shift+X) y la buscáis allí.

3. Instalad la extensión C/C++. Abrid Extensions (Ctrl+Shift+X) y buscad "C/C++". Instalad la de Microsoft (normalmente la primera que sale).

4. Cerrad Visual Studio Code.

## 4 Editar un fichero fuente desde WSL mediante Visual Studio Code 

Ejecutad de nuevo la aplicación de Ubuntu. Una vez dentro ejecutad los siguientes comandos:
	
	mkdir projects
	cd projects
	mkdir helloworld
	cd helloworld

Ejecutad el siguiente comando que abrirá Visual Studio Code desde el terminal:

	code .

Ahora ya podéis editar ficheros de WSL mediante Visual Studio Code. Con esto es suficiente ya que podemos compilar y ejecutar los programas en el terminal. Por ejemplo, en Visual Studio Code cread un nuevo fichero llamado "helloworld.c" y guardadlo en la carpeta "helloworld" de WSL. Dentro del fichero copiad un código sencillo:

	#include <stdio.h>
	int main() {
	   printf("Hello, World!");
	}

Grabad mediante CTRL+S. Ahora en el terminal comprobad que el fichero está mediante el comando:

	ls

Y que tiene el contenido correcto mediante el comando:

	cat helloworld.c

Compiladlo mediante:

	gcc helloworld.c -o helloworld

Y ejecutadlo haciendo simplemente:

	./helloworld

## (OPCIONAL) 5 Compilar y depurar mediante Visual Studio Code 

Aunque no sea estrictamente necesario sería una pena desaprovechar que Visual Studio Code no es solo un editor, es un entorno integrado de desarrollo (IDE). Eso siginfica que, entre otras mil cosas, nos permite compilar y depurar los programas directamente sobre el editor. 

### 5.1 Compilar mediante Visual Studio Code

Para compilar tenéis que ir a Terminal > Configure Default Build Task. Seleccionad allí "C/C++: gcc build active file". Esto creará un fichero tasks.json dentro de un directorio oculto .vscode y os lo mostrará en el editor. Podéis cerrarlo e ignorarlo. Para compilar id a Terminal > Tasks: Run Build Task.

El resultado de la compilación os aparecerá en el "Integrated Terminal", en la parte de abajo. 

A parte de servir para ver el resultado de la compilación, el "Integrated Terminal" os evitará tener que cambiar constantemente a la ventana de Ubuntu para realizar pruebas. Abrid un nuevo Integrated Terminal en Visual Studio Code mediante el icono "+" (abajo a la derecha). Dentro del terminal ejecutad el programa mediante el comando:
	
	./helloworld

### 5.2 Depurar mediante Visual Studio Code

Id a Run > Add Configuration... y seleccionad "C++ (GDB/LLDB)". Seleccionad "gcc build and debug active file". Esto también os creará y mostrará otro fichero .json. Podéis cerrarlo e ignorarlo. Apretando F5 o seleccionando en el menú Run > Start Debugging podéis depurar el programa. [Aquí](https://code.visualstudio.com/docs/cpp/config-wsl) encontraréis más información sobre como depurar con Visual Studio Code.






