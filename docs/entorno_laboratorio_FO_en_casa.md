# Realizar las prácticas de FO en casa

Las prácticas de FO consisten básicamente en editar, compilar y ejecutar programas escritos en lenguaje C. Hay muchas maneras de hacer esto en casa pero os recomendamos configurar un entorno que sea parecido al que utilizaremos en las sesiones de laboratorio y, lo más importante, en el el examen de laboratorio. No obstante, tened en cuenta que el entorno de laboratorio admite variantes (editor de código fuente, depurador, etc.) y cada profesor de laboratorio de FO tiene sus preferencias. A continuación se describe la configuración de un entorno básico, que más adelante podéis cambiar en función de vuestras preferencias o de lo que os diga vuestro profesor.

## 1 Si tenéis Linux 

En el laboratorio de FO los ordenadores utilizan Linux como sistema operativo, concretamente Ubuntu 18.04.03 LTS. Si el sistema operativo de vuestro ordenador es Linux o si vuestro ordenador tiene una partición con Linux, podéis configurar un entorno parecido al del laboratorio simplemente ejecutando los comandos que se describen a continuación. Las instrucciones son para Ubuntu, tendréis que adaptarlas si tenéis una distribución Linux distinta.

En primer lugar debéis abrir una ventana de terminal. La forma más rápida es pulsar CTRL+ALT+T, pero también podéis buscar el terminal mediante la barra de búsqueda o en el tablero de Ubuntu. Una vez en el terminal ejecutad los siguientes comandos.

Primero actualizad la lista de paquetes mediante:

	sudo apt-get update

A continuación instalad GCC (y el depurador GDB):

	sudo apt-get install -y build-essential gdb

Probad que GCC se ha instalado correctamente ejecutando:

	gcc --version

Ahora ya podéis compilar programas en C y ejecutarlos, pero para poderlos editar cómodamente será necesario instalar algún editor. Uno sencillo y que utilizan muchos de los profesores es gedit. Podéis instalarlo simplemente mediante:

	sudo apt-get install -y gedit

Además de un editor también es recomendable utilizar un depurador. Uno sencillo es Nemiver y lo podéis instalar así:

	sudo apt-get install -y nemiver

## 2 Si tenéis Windows 10

Tradicionalmente recomendábamos a los usuarios de Windows trabajar mediante una máquina virtual. Es un método que permite tener un entorno idéntico al del laboratorio pero tiene como principal inconveniente el consumir muchos recursos del ordenador, haciendo a menudo que todo vaya muy lento. Siempre podéis recurrir a esa opción siguiendo las instrucciones que encontraréis en la Intranet de la Escula, en Serveis->Imatge VirtualBox per a docència.

En la actualidad hay una alternativa más productiva, siempre y cuando tengáis una versión de Windows 10 actualizada. Se trata de trabajar mediante Windows Subsystem for Linux (WSL). A continuación se explica como hacerlo.

NOTA: Si os encontráis con problemas, hay un tutorial más completo [aquí](https://wiki.ubuntu.com/WSL).

### 2.1 Instalar Windows Subsystem for Linux (WSL) en Windows 10

#### Activar la característica Windows Subsystem for Linux en Windows 10

En la barra de búsqueda de Windows 10 (abajo a la izquierda) introducid "características de windows" y seleccionad "Activar o desactivar las características de Windows" (si el sistema está en inglés buscar "windows features"). Marcad la casilla de "Subsistema de Windows para Linux" y reiniciar el ordenador. 

#### Instalar Ubuntu 18.04

En el Microsoft Store buscad "Ubuntu 18" e instalad la aplicación Ubuntu 18.04.LTS. 

#### Configurar Ubuntu 18.04

Lanzad la aplicación Ubuntu 18.04 y configurad un nombre de usuario y password fáciles de recordar. A continuación, ya dentro de Ubuntu, ejectutad el siguiente comando:

	sudo apt-get update

Y lo siguiente para instalar GCC (y el depurador GDB):

	sudo apt-get install build-essential gdb

Probad que ha funcionado ejecutando:

	gcc --version

Ya podéis compilar programas en C y ejecutarlos, pero para poderlos editar cómodamente será necesario utilizar algún editor con entorno gráfico. Hay dos opciones, usar un editor para para Windows como Notepad++, o uno para Linux como gedit (como en el laboratorio). Pero aquí nos encontramos con una pequeña dificultad. Si escogemos la primera opción, nos encontramos con la duda de como acceder a un fichero que está dentro de WSL desde una aplicación Windows. Si escogemos la segunda opción, nos encontramos que no podemos ejecutar directamente aplicaciones Linux con entorno gráfico desde WSL. 

La primera es muy simple de resolver, desde las aplicaciones Windows se puede acceder a los ficheros de WSL mediante la ruta "\\wsl$". Esto permite utilizar un editor como Notepad++, muy parecido al editor que usaréis en el laboratorio (si es que vuestro profesor utiliza gedit o similares). 

*NOTA: Una alternativa más "profesional" es Visual Studio Code, un entorno integrado de desarrollo (IDE) que incluye una extensión para WSL que permite que sea utilizado directamente desde dentro de WSL. No os recomendamos esta opción ya que difiere bastante del entorno que tendréis en el laboratorio, pero si queréis probarlo tenéis un tutorial [aquí](https://code.visualstudio.com/docs/remote/wsl)*

La segunda opción, utilizar un editor para Linux con entorno gráfico (como gedit), sería la que os permitiría tener el mismo entorno que en el laboratorio (si es que vuestro profesor os recomienda gedit allí). Microsoft está a punto de sacar una actualización de Windows 10 que hará esta opción tan directa como en un Linux nativo, pero a día de hoy no está disponible. 





#### Editar mediante un programa Windows

Si ya te\\wsl$

#### Editar mediante un programa Linux
Hay dos posibilidades, utilizar un editor de Ubuntu o uno de Windows. 

