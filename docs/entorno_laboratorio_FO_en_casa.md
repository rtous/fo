# Realizar las prácticas de FO en casa

Las prácticas de FO consisten básicamente en editar, compilar y ejecutar programas escritos en lenguaje C. Hay muchas maneras de hacer esto en casa pero os recomendamos configurar un entorno que sea parecido al que utilizaremos en las sesiones de laboratorio y, lo más importante, en el el examen de laboratorio. No obstante, tened en cuenta que el entorno de laboratorio admite variantes (editor de código fuente, depurador, etc.) y cada profesor de laboratorio de FO tiene sus preferencias. A continuación se describe la configuración de un entorno básico, que más adelante podéis cambiar en función de vuestras preferencias o de lo que os diga vuestro profesor.

## Si tenéis Windows o Mac

Hay múltiples opciones para poder programar en C en Windows o Mac. Para los que empezáis a programar lo mejor será que os instaléis una máquina virtual como se describe en este enlace:

- [OPCIÓN 1: Máquina virtual](virtualmachine.md)

Los que tengáis un nivel más avanzado podéis probar Visual Studio Code (u otro IDE como NetBeans):

- [OPCIÓN 2: Visual Studio Code](visual_studio_code.md) 

Si todo lo anterior os da problemas podéis probar alguna solución alternativa:

- [OPCIÓN 3: Programar C en Ubuntu mediante Windows Subsystem for Linux (WSL) en Windows 10 ](wsl.md)
- [OPCIÓN 3: Programar C en Mac de manera simple  ](mac.md)


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
