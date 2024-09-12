# Realizar las prácticas de FO en casa

Las prácticas de FO consisten básicamente en editar, compilar y ejecutar programas escritos en lenguaje C. Hay muchas maneras de hacer esto en casa pero os recomendamos configurar un entorno que sea parecido al que utilizaremos en las sesiones de laboratorio y, lo más importante, en el el examen de laboratorio. No obstante, tened en cuenta que el entorno de laboratorio admite variantes (editor de código fuente, depurador, etc.) y cada profesor de laboratorio de FO tiene sus preferencias. A continuación se describe la configuración de un entorno básico, que más adelante podéis cambiar en función de vuestras preferencias o de lo que os diga vuestro profesor.

## Trabajar con IDE o sin IDE?

Un entorno integrado de desarrollo (IDE) es una aplicación (como NetBeans o Visual Studio Code) todo en uno (editor código, compilación, depuración, terminal, etc.). Hay profesores de FO que lo utilizan (normalmente NetBeans ya que está en el laboratorio) y hay profesores que no y prefieren que uséis por separado el editor (gedit en el laboratorio), los comandos de compilación en el terminal, el depurador (nemiver en el laboratorio). Sois libres de hacerlo de una forma u otra pero si estáis empezando a programar mejor haced lo mismo que vuestro profesor. 

Las instrucciones siguientes están pensadas principalmente para que podáis trabajar sin IDE en casa. En caso que optéis por trabajar con IDE (por ejemplo NetBeans) lo lógico sería que instalaseis NetBeans de forma nativa en vuestra máquina. Aunque si os da problemas o queréis un entorno idéntico al del laboratorio también podéis optar por las opciones de escritorio virtual o máquina virtual.
     

## Si tenéis Windows

Hay múltiples opciones para poder programar en C en Windows. Para los que empezáis a programar una opción simple y práctica es trabajar nativamente en Windows:

- OPCIÓN 1: [Programar C en Windows con MinGW y Notepad++ ](mingw.md)

Una alternativa más parecida a lo que tendréis en el laboratorio es instalar Ubuntu dentro de Windows mediante Windows Subsystem for Linux (WSL). 

- OPCIÓN 2: [Programar C en Ubuntu mediante Windows Subsystem for Linux (WSL) en Windows 10 ](wsl.md)

Si WSL os ha dado problemas una alternativa será utilizar un escritorio virtual de la ETSETB:

- OPCIÓN 3: [Ravada VDI ](https://rvd6.upc.edu/) / [(MI MANUAL)](ravada.md) / [(MANUAL ETSETB)](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/2022-ServeiEscriptoriVirtual.pdf)

Si el escritorio virtual os da problemas una alternativa será que os instaléis una máquina virtual como se describe en alguno de los siguientes enlaces:

- OPCIÓN 4: [Máquina virtual con VirtualBox](virtualmachine.md) / [Máquina virtual con VMware](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/Instalar%20M%C3%A1quina%20Virtual%20con%20Ubuntu%2020.04.pdf)

Una alternativa es usar un entorno de desarrollo integrado (IDE). Una ventaja es que funciona igual sobre cualquier plataforma. En el caso de NetBeans además lo tenéis instalado en el laboratorio:

- OPCIÓN 5: [NetBeans](https://atenea.upc.edu/pluginfile.php/6164257/mod_resource/content/10/NetbeansApache_Guia_Basica_FO_21_22_v1.pdf) / [Visual Studio Code](visual_studio_code.md) 

NOTA: Para NetBeans se recomienda instalar [la versión ya integrada con Java](https://www.codelerity.com/netbeans/)

Si todo lo anterior falla siempre podéis usar:

- OPCIÓN 6: [replit.com](https://replit.com/) 


## Si tenéis Mac

Hay múltiples opciones para poder programar en C en Mac. Para los que empezáis a programar lo más práctico es usar directamente las herramientas de Mac:

- OPCIÓN 1: [Programar C en Mac de manera simple  ](mac.md)

Si alternativa será utilizar un escritorio virtual de la ETSETB:

- OPCIÓN 2: [Ravada VDI ](https://rvd6.upc.edu/) / [(MI MANUAL)](ravada.md) / [(MANUAL ETSETB)](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/2022-ServeiEscriptoriVirtual.pdf)

Una alternativa será que os instaléis una máquina virtual como se describe en alguno de los siguientes enlaces:

- OPCIÓN 3: [Máquina virtual con VirtualBox](virtualmachine.md) / [Máquina virtual con VMware](https://atenea.upc.edu/pluginfile.php/6164251/mod_label/intro/Instalar%20M%C3%A1quina%20Virtual%20con%20Ubuntu%2020.04.pdf)

Una alternativa es usar un entorno de desarrollo integrado (IDE). Una ventaja es que funciona igual sobre cualquier plataforma. En el caso de NetBeans además lo tenéis instalado en el laboratorio:

- OPCIÓN 4: [NetBeans](https://atenea.upc.edu/pluginfile.php/6164257/mod_resource/content/10/NetbeansApache_Guia_Basica_FO_21_22_v1.pdf) / [Visual Studio Code](visual_studio_code.md) 

Si todo lo anterior falla siempre podéis usar:

- OPCIÓN 5: [replit.com](https://replit.com/) 

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

*NOTA: Las opciones 2, 3 y 4 de los apartados de Mac y Windows también están disponibles para Linux. Las opciones 2 y 3 no tienen mucho sentido pero la 4 (instalar IDE NetBeans) sí lo tiene si queréis trabajar de esa manera.* 