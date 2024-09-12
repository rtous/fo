# Programar en GCC en Windows 10 mediante WSL y Notepad++

Una alternativa muy productiva para programar en C/C++ sobre Windows 10 es hacerlo mediante Windows Subsystem for Linux (WSL). Con WSL podréis instalar un Ubuntu parecido al que usamos en el laboratorio en vuestro Windows como si fuera una aplicación, de forma mucho más práctica que mediante una máquina virtual. 

En ese Ubuntu podréis ejecutar los mismos comandos que usamos en el laboratorio pero no las aplicaciones gráficas de Ubuntu (el editor gedit por ejemplo). Pero en vez de gedit podemos usar un editor de texto de Windows, como Notepad++, para editar ficheros. 

NOTA: Notepad++ es un editor sencillo como el gedit que usaremos en el laboratorio y es lo recomendable para los que empezáis. Una alternativa más "profesional" sería hacerlo mediante Visual Studio Code. Una ventaja de Visual Studio Code es que incorpora un depurador. Si queréis probarlo tenéis un tutorial [aquí](programar_gcc_en_windows_con_WSL_y_vscode.md).


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

## 1.4 Instalar y configurar Notepad++

1. Descargad e instalad de [aquí](https://notepad-plus-plus.org/)

2. Es conveniente (aunque no estrictamente necesario) poder ejecutar Notepad++ desde el terminal de Ubuntu. Para ello hace falta hacer lo siguiente: Entrad Configuración/Sistema/Información/Configuración avanzada/Variables de entorno (o simplemente buscad "variables de entorno" en el buscador Windows). Seleccionad la variable Path y editadla. Añadir (Nuevo) la siguiente ruta:

	C:\Program Files (x86)\Notepad++;

Ahora si entráis de nuevo en Ubuntu, abrís un terminal y ejecutáis:

	Notepad++.exe test.c 

Os abrirá (o creará) el fichero y lo podréis editar fácilmente.

También podéis acceder a los ficheros de Ubuntu desde el propio Notepad++ si hace falta. 






