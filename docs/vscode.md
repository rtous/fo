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
