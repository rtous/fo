# Conexión a RAVADA

## Windows

1) Descargar el fichero [spice.reg](https://raw.githubusercontent.com/UPC/ravada/gh-pages/docs/docs/spice.reg). Mejor clicad con el botón derecho sobre el enlace y hace "Guardar enlace como..." y guardadlo en Descargas. Aseguraros de que se descarga con extensión .reg y no .txt (si no canviarla). 

2) Con el explorador de ficheros id a Descargas y ejecutad el fichero spice.reg y aceptad los cambios en el registro.

3) Descargad el fichero [UsbDk_1.0.19_x64.msi](https://www.spice-space.org/download/windows/usbdk/UsbDk_1.0.19_x64.msi). 

4) Reiniciad el PC.

5) Descargad e instalar el [Remote Viewer para Windows](https://releases.pagure.org/virt-viewer/virt-viewer-x64-11.0-1.0.msi).

6) Conectarse a ravada [aquí](https://rvd6.upc.edu/)

7) Seleccionad la máquina LinuxAules2025

8) Seleccionad la pestaña "spice" (cuidado que por defecto está "spice-tls") y copiad la URL y tomad nota de la contraseña que aparece encima.

9) Ejecutad la aplicación "Remote viewer" (buscador de Windows) y entrad la URL y la contraseña.

## Mac

### Install remote-viewer 

Open a Terminal.

Check if Homebrew is installed:

	brew -v

If not install Homebrew with:

	/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

If it's already installed run the following commands

	brew install --cask remoteviewer

### Running

In the browser open https://rvd6.upc.edu/

Select a machine (e.g. LinuxAules2025)

Select the "spice" tab instead of the "spice-tls" tab

Copy the password somewhere

Press view (a file will be saved to Downloads, for instance 9811.vv)

Open the terminal and run:

	remote-viewer Downloads/9811.vv


