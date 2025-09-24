# Conexión a RAVADA desde Mac

### Install remote-viewer 

Open a Terminal.

Check if Homebrew is installed:

	brew -v

If not install Homebrew with:

	/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

If Hombrew it's already installed run the following commands to install virt-viewer:

	brew tap jeffreywildman/homebrew-virt-manager
	brew install jeffreywildman/virt-manager/virt-viewer

(only if error) If it raises an error saying that there's a previous virt-viewer uninstall it with: 

	brew uninstall virt-viewer

(only if error) And try again:
	
	brew install jeffreywildman/virt-manager/virt-viewer

### Running

In the browser open https://rvd6.upc.edu/

Select the machine LinuxAules2026

Select the "spice" tab instead of the "spice-tls" tab

Copy the password somewhere

Press view (a file will be saved to Downloads, for instance 9811.vv)

Open the terminal and run:

	remote-viewer Downloads/9811.vv


