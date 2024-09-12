# Programar C en Windows con MinGW y Notepad++

## 1. Instalar MinGW

- Descargar MinGW de [aquí](https://winlibs.com/) La versión Win64 with POSIX threads (Zip archive). 

- Descomprimir el archivo zip. Mover la carpeta "mingw64" a la raiz de C: y renombrarla como "MinGW". Quedará la carpeta C:\MinGW

- Entrad Configuración/Sistema/Información/Configuración avanzada/Variables de entorno (o simplemente buscad "variables de entorno" en el buscador Windows). Seleccionad la variable Path y editadla. Añadir (Nuevo) la siguiente ruta:

	C:\MinGW\bin

- Abrid un terminal PowerShell y provad a ejecutar:

	gcc -v

*NOTA: Si MinGW os da problemas podéis provar con Cygwin*

## 2. Instalar Notepad++ para poder editar el código C

Ya podéis compilar programas en C y ejecutarlos, pero para poderlos editar cómodamente será necesario utilizar algún editor con entorno gráfico. La forma más práctica de hacerlo es instalando Notepad++ en Windows. Notepad++ es muy parecido a gedit (que usaréis en el lab) y es gratuita. Para instalar Notpad++ descargad la versión más nueva de [aquí](https://notepad-plus-plus.org/downloads/). Descargad el instalador para la versión de 64 bits y ejecutadlo con todas las opciones por defecto y el idioma que queráis.

### 2.1 Ejecutar Notepad++ desde el terminal

Es conveniente (aunque no estrictamente necesario) poder ejecutar Notepad++ desde el terminal de Windows (PowerShell). Para ello hace falta hacer lo siguiente: Entrad Configuración/Sistema/Información/Configuración avanzada/Variables de entorno (o simplemente buscad "variables de entorno" en el buscador Windows). Seleccionad la variable Path y editadla. Añadir (Nuevo) la siguiente ruta:

	C:\Program Files (x86)\Notepad++;

Ahora si entráis en el PowerShell de Windows y ejecutáis:

	Notepad++.exe test.c 

Os abrirá (o creará) el fichero y lo podréis editar fácilmente.

