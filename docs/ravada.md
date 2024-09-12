# Conexión a RAVADA

Instalar virt-viewer de [aquí](https://virt-manager.org/download.html) (el enlace que pone [Win x64 MSI}(https://releases.pagure.org/virt-viewer/virt-viewer-x64-11.0-1.0.msi)).

Clicar en el instalador para 


1) Descargar el fichero [spice.reg](https://raw.githubusercontent.com/UPC/ravada/gh-pages/docs/docs/spice.reg). Aseguraros de que se descarga con extensión .reg y no .txt (si no canviarla). Ejecutad el fichero y aceptad los cambios en el registro.
2) Descargad el fichero [UsbDk_1.0.19_x64.msi](https://www.spice-space.org/download/windows/usbdk/UsbDk_1.0.19_x64.msi).
3) Reiniciad el PC.
4) Instalar el [Remote Viewer] para Windows (https://releases.pagure.org/virt-viewer/virt-viewer-x64-11.0-1.0.msi).
5) Conectarse a ravada [aquí]( https://infoteleco.upc.edu/ravada/)
6) Seleccionad la máquina Linux_AulesA2
7) Seleccionad la pestaña "spice" y copiad la URL y tomad nota de la contraseña que aparece encima.
8) Ejecutad la aplicación "Remote viewer" y entrad la URL y la contraseña



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


