# Realizar las prácticas de FO en casa

Las prácticas de FO consisten básicamente en editar, compilar y ejecutar programas escritos en lenguaje C. Hay muchas maneras de hacer esto en casa pero os recomendamos configurar un entorno que sea parecido al que utilizaremos en las sesiones de laboratorio y, lo más importante, en el el examen de laboratorio. No obstante, tened en cuenta que el entorno de laboratorio admite variantes (editor de código fuente, depurador, etc.) y cada profesor de laboratorio de FO tiene sus preferencias. A continuación se describe la configuración de un entorno básico, que más adelante podéis cambiar en función de vuestras preferencias o de lo que os diga vuestro profesor.

## Si tenéis Windows

Hay múltiples opciones para poder programar en C en Windows. Para los que empezáis a programar una opción práctica y que os da un entorno parecido al del laboratorio es instalar Ubuntu dentro de Windows mediante Windows Subsystem for Linux (WSL). 

- OPCIÓN 1: [Programar C en Ubuntu mediante Windows Subsystem for Linux (WSL) en Windows 10 ](wsl.md)

Si WSL os ha dado problemas una alternativa será utilizar un escritorio virtual:

- OPCIÓN 2: [Ravada VDI ](https://rvd6.upc.edu/)[(MANUAL)](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/2022-ServeiEscriptoriVirtual.pdf)

Si el escritorio virtual os da problemas una alternativa será que os instaléis una máquina virtual como se describe en alguno de los siguientes enlaces:

- OPCIÓN 3: [Máquina virtual con VirtualBox](virtualmachine.md) / [Máquina virtual con : Máquina virtual con VMware](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/Instalar%20M%C3%A1quina%20Virtual%20con%20Ubuntu%2020.04.pdf)

Los que tengáis un nivel más avanzado podéis probar Visual Studio Code (u otro IDE como NetBeans):

- OPCIÓN 4: [Visual Studio Code](visual_studio_code.md) 

Si todo lo anterior falla siempre podéis usar:

- OPCIÓN 5: [replit.com](https://replit.com/) 


## Si tenéis Mac

Hay múltiples opciones para poder programar en C en Mac. Para los que empezáis a programar lo más práctico es usar directamente las herramientas de Mac:

- OPCIÓN 1: [Programar C en Mac de manera simple  ](mac.md)

Una alternativa será que os instaléis una máquina virtual como se describe en alguno de los siguientes enlaces:

- OPCIÓN 2: [Máquina virtual con VirtualBox](virtualmachine.md)[Máquina virtual con : Máquina virtual con VMware](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/Instalar%20M%C3%A1quina%20Virtual%20con%20Ubuntu%2020.04.pdf)

En teoría una alternativa más práctica que la máquina virtual sería utilizar un escritorio virtual pero suele dar problemas en Mac. No obstante os dejo el enlace por si lo queréis probar:

- OPCIÓN 3: [Ravada VDI ](https://rvd6.upc.edu/)[MANUAL: Ravada VDI ](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/2022-ServeiEscriptoriVirtual.pdf)

Los que tengáis un nivel más avanzado podéis probar Visual Studio Code (u otro IDE como NetBeans):

- OPCIÓN 4: [Visual Studio Code](visual_studio_code.md) 

Si todo lo anterior falla siempre podéis usar:

- [OPCIÓN 5: replit.com](https://replit.com/) 

## Si tenéis Linux 

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
