# Instrucciones de instalación

A continuación tenéis las instrucciones para instalar las herramientas del laboratorio según vuestro sistema operativo. Si vais a usar VS Code, consultad también la sección [Cómo usar VS Code para programar y depurar programas en C](vscode.md).

- [Windows](#windows)
- [Mac](#mac)
- [Linux](#linux)
- [Cómo usar VS Code](vscode.md)

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

