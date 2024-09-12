# Programar C en Ubuntu mediante Windows Subsystem for Linux (WSL) en Windows 10

Aquí se describen algunas opciones alternativas a las máquinas virtuales y los entornos integrados (IDE) para trabajar con Windows. 

## Instalar Windows Subsystem for Linux (WSL) en Windows 10

En la actualidad hay una alternativa productiva, siempre y cuando tengáis una versión de Windows 10 actualizada. Se trata de trabajar mediante Windows Subsystem for Linux (WSL). A continuación se explica como hacerlo.

*NOTA: Si os encontráis con problemas, hay un tutorial más completo [aquí](https://wiki.ubuntu.com/WSL).*

### Activar la característica Windows Subsystem for Linux en Windows 10

En la barra de búsqueda de Windows 10 (abajo a la izquierda) introducid "características de windows" y seleccionad "Activar o desactivar las características de Windows" (si el sistema está en inglés buscar "windows features"). Si no está marcada marcad la casilla de "Subsistema de Windows para Linux" y reiniciar el ordenador. 

### Instalar Ubuntu 18.04

En el Microsoft Store buscad "Ubuntu 18" e instalad la aplicación Ubuntu 18.04.LTS. 

### Configurar Ubuntu 18.04

Lanzad la aplicación Ubuntu 18.04 y configurad un nombre de usuario y password fáciles de recordar. A continuación, ya dentro de Ubuntu, ejectutad el siguiente comando:

	sudo apt-get update

Y lo siguiente para instalar GCC (y el depurador GDB):

	sudo apt-get install build-essential gdb

Probad que ha funcionado ejecutando:

	gcc --version

Cread una carpeta para las prácticas de fo:

	mkdir fo

Entrad en ella:

	cd fo

Listad su contenido, que será vacío:

	ls fo

Ahora, sin cerrar la ventana de Ubuntu, seguid el tutorial.

## 2.2 Instalar Notepad++ para poder editar el código C

*NOTA: Notepad++ es un editor sencillo como el gedit que usaremos en el laboratorio y es lo recomendable para los que empezáis. Una alternativa más "profesional" sería hacerlo mediante Visual Studio Code. Una ventaja de Visual Studio Code es que incorpora un depurador. Si queréis probarlo tenéis un tutorial [aquí](programar_gcc_en_windows_con_WSL_y_vscode.md).*

Ya podéis compilar programas en C y ejecutarlos, pero para poderlos editar cómodamente será necesario utilizar algún editor con entorno gráfico. La forma más práctica de hacerlo es instalando Notepad++ en Windows. Notepad++ es muy parecido a gedit (que usaréis en el lab) y es gratuita. Para instalar Notpad++ y usarlo con WSL haced lo siguiente:

1. Descargad la versión más nueva de Notepad++ de [aquí](https://notepad-plus-plus.org/downloads/). Descargad el instalador para la versión de 64 bits y ejecutadlo con todas las opciones por defecto y el idioma que queráis.

2. Es conveniente (aunque no estrictamente necesario) poder ejecutar Notepad++ desde el terminal de Ubuntu. Para ello hace falta hacer lo siguiente: Entrad Configuración/Sistema/Información/Configuración avanzada/Variables de entorno (o simplemente buscad "variables de entorno" en el buscador Windows). Seleccionad la variable Path y editadla. Añadir (Nuevo) la siguiente ruta:

	C:\Program Files (x86)\Notepad++;

Ahora si entráis de nuevo en Ubuntu, abrís un terminal y ejecutáis:

	Notepad++.exe test.c 

Os abrirá (o creará) el fichero y lo podréis editar fácilmente.

3. Una alternativa es crear un fichero en Notepad++ y guardarlo en Ubuntu. Ejecutad Notepad++ y editad el siguiente programa de ejemplo:

```c
#include <stdio.h>
int main() {
   printf("Hello, World!");
}
```

En el menú "fichero" seleccionad "guardar como" y en la barra de arriba, en la que sale la ubicación, introducid lo siguiente:

	\\\\wsl$

Ésa es la ruta de WSL para las aplicaciones Windows. Os aparecerà una carpeta llamada "Ubuntu", entrad. Después entrad en la carpeta "home". Allí tendríais que ver una carpeta con el nombre de usuario que habéis especificado al instalar Ubuntu. Entrad en esa carpeta. Allí grabad el fichero con nombre "helloworld.c".

Ahora volved a la ventana Ubuntu y volved a listar el contenido de la carpeta "fo". Os debería aparecer el nuevo fichero.

Por cierto, podéis ver también el fichero en el explorador de carpetas de Windows.

*NOTA: tal vez os preguntéis por qué no usamos gedit en Ubuntu (en vez de una aplicación Windows) como en el laboratorio. El motivo es que actualmente es muy complicado usar aplicaciones Ubuntu con entorno gráfico en WSL. Microsoft está a punto de sacar una actualización para que sea fácil, pero todavía no está lista. Ahora hace falta instalar un X Server para Windows (como x410) y realizar una configuración bastante complicada.*
