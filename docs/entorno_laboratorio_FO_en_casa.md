# Instrucciones de instalación

A continuación tenéis las instrucciones para instalar las herramientas del laboratorio según vuestro sistema operativo. Si vais a usar VS Code, consultad también la sección [Cómo usar VS Code para programar y depurar programas en C](#cómo-usar-vs-code-para-programar-y-depurar-programas-en-c).

- [Windows](#windows)
- [Mac](#mac)
- [Linux](#linux)
- [Cómo usar VS Code](#cómo-usar-vs-code-para-programar-y-depurar-programas-en-c)

---

## Windows

### Herramientas básicas

1. **Instalad Windows Subsystem for Linux (WSL).**

   Abrid PowerShell y ejecutad:

   ```powershell
   wsl --install
   ```

   Si os da problemas, consultad la [guía oficial de instalación de WSL](https://learn.microsoft.com/es-es/windows/wsl/install).

   Si todo ha ido bien, deberíais ver una aplicación nueva en Windows llamada **Ubuntu**.

2. **Instalad las herramientas de C y C++ en Ubuntu.**

   Abrid la aplicación Ubuntu (se abrirá un terminal) y ejecutad:

   ```bash
   sudo apt-get update
   sudo apt-get install -y build-essential gdb
   sudo apt-get install -y gedit
   sudo apt-get install -y nemiver
   ```

Con esto ya podéis trabajar con las herramientas básicas del laboratorio (`gcc`, `gedit` y `nemiver`).

> **Acceder a los ficheros de Ubuntu desde Windows:** abrid el Explorador de archivos y escribid en la barra de direcciones `\\wsl$`

Si WSL os da problemas, podéis probar alguna de estas alternativas:

- Usar Visual Studio Code directamente, sin WSL.
- Programar directamente con el terminal de Windows y el Bloc de notas (instrucciones [aquí](mingw.md)).

### Herramientas avanzadas: VS Code (sobre WSL)

1. Instalad [VS Code](https://code.visualstudio.com/).
2. Abrid VS Code e instalad la extensión **WSL** de Microsoft. Después, cerrad VS Code.
3. Abrid Ubuntu, id a la carpeta en la que queráis trabajar (donde estén los ficheros `.c`) y ejecutad:

   ```bash
   code .
   ```

> **Nota:** VS Code se abrirá en Windows, pero fijaos en la esquina inferior izquierda: debería aparecer algo parecido a **"WSL: Ubuntu"**. Eso significa que el VS Code que veis en Windows está conectado a Ubuntu.

---

## Mac

### Herramientas básicas

1. **Instalad las herramientas de desarrollo de Xcode.** Abrid un terminal y ejecutad:

   ```bash
   xcode-select --install
   ```

   También podéis instalar Xcode desde la App Store. Esto instala el compilador de C **clang** (LLVM), que no es el GCC "oficial" pero es muy parecido. Si queréis el GCC de verdad, podéis instalarlo con [Homebrew](https://brew.sh/) (`brew install gcc`), aunque no es necesario.

2. **Abrid un terminal** (buscad "Terminal" en el Launchpad).

3. **Comprobad que podéis usar el compilador:**

   ```bash
   gcc --version
   ```

4. **Instalad un editor de texto** para editar el código. Existe una versión de gedit para Mac, pero os recomendamos [Sublime Text](https://www.sublimetext.com/).

### VS Code

Podéis instalar [VS Code](https://code.visualstudio.com/) y usarlo igual que en el laboratorio.

---

## Linux

### Herramientas básicas

```bash
sudo apt-get update
sudo apt-get install -y build-essential gdb
gcc --version
sudo apt-get install -y gedit
sudo apt-get install -y nemiver
```

### VS Code

Podéis instalar [VS Code](https://code.visualstudio.com/) y usarlo igual que en el laboratorio.

---

## Cómo usar VS Code para programar y depurar programas en C

### Preparación

1. Abrid VS Code, id al menú de extensiones (icono de los cuadraditos o `Ctrl + Shift + X`) e instalad la extensión **C/C++ Extension Pack** de Microsoft.
2. Abrid la carpeta en la que queráis trabajar (donde estarán los ficheros `.c`).
3. Abrid un terminal (**Terminal → New Terminal** o `Ctrl + Shift + ñ`).
4. Compilad y ejecutad en el terminal como siempre.

### Depuración

Hay dos situaciones posibles:

#### Programas de un solo fichero

Situaos sobre el fichero `.c` y pulsad `F5`. Luego seleccionad la primera opción que aparezca. Se compilará y depurará un ejecutable con el mismo nombre que el fichero fuente, pero sin extensión.

> **Atención:** si habéis compilado manualmente generando un ejecutable con un nombre distinto, será ignorado.

#### Programas con varios ficheros

Si el programa tiene varios ficheros (por ejemplo, los ejercicios que usan `colours.c` o el proyecto), necesitaréis crear una configuración de depuración:

1. Id al menú **Run → Add Configuration...**. Se creará un fichero `launch.json`.
2. Reemplazad su contenido por el siguiente:

   ```json
   {
       "version": "0.2.0",
       "configurations": [
           {
               "name": "Depurar programa",
               "type": "cppdbg",
               "request": "launch",
               "program": "${fileDirname}/${fileBasenameNoExtension}",
               "args": [],
               "stopAtEntry": false,
               "cwd": "${workspaceFolder}",
               "externalConsole": false,
               "MIMode": "gdb",
               "miDebuggerPath": "/usr/bin/gdb"
           }
       ]
   }
   ```

3. Compilad manualmente en el terminal. Al pulsar `F5` se depurará el ejecutable que tenga el mismo nombre (sin extensión) que el fichero que tengáis seleccionado.

#### VS Code en Windows sin WSL

Si trabajáis con VS Code en Windows sin WSL, la configuración es diferente:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Depurar programa",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb.exe"
        }
    ]
}
```

En este caso, aseguraos de que el ejecutable acabe en `.exe` cuando compiléis en el terminal (por ejemplo, `gcc programa.c -o programa.exe`).
