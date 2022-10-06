# Doing the labs on your own computer with a virtual machine

The labs are designed to be performed on a computer running Ubuntu. If you want to do the lab on your own computer one possibility is working over a virtual machine. This page describes how to do it.

## Step 1: Install VirtualBox

Go to  [https://www.virtualbox.org/](https://www.virtualbox.org/) and download the installer for your host operating system. Run the installer and accept all the default options.

*NOTE for Mac users: If installation fails, open System Preferences, go to Security & Privacy, and then click Allow next to "System software from 'Oracle America, Inc.' was blocked from loading". Then re-run the VirtualBox installer.*

## Step 2: Download and import the Ubuntu image

Download Ubuntu Desktop 20.04.2.0 LTS from [here](https://releases.ubuntu.com/20.04/ubuntu-20.04.2.0-desktop-amd64.iso).

## Step 3: Create and configure the virtual machine

1. Launch VirtualBox, click New. The recommended setup is:

- Base memory = 2048MB
- Create a virtual hard disk (10GB), VDI, dynamically allocated

2. Select the virtual machine and click Settings.

3. Go to Settings/Storage/Controller IDE, click the disk icon and select the Ubuntu file that you downloaded before.

4. Go to Settings/Display/Screen and set Graphics Controller = VBoxVGA.

5. Go to Settings/Diplay and create a new shared folder. Select the folder that you want to use to exchange files between your system and the virtual machine (you may prefer to create one for that first). Select the "mount point" (the path within the virtual machine), for instance "/shared".  

## Step 4: Launch the virtual machine and configure Ubuntu

Select your virtual machine and click "Show". You should see the Ubuntu installer. Select "Install Ubuntu". Be careful to select a proper keyboard layout (e.g. "Spanish - Catalan") and accept the default options for the rest. Select a username and a password (and write them down). 

At the end select restart, then close the window selecting "Power off the machine".

## Step 5: Launch the VM again and Install Guest Additions

1. Launch the VM again

2. In the VirtualBox VM menu (top-left of your screen) go to Devices/Install Guest Additions

3. Power off the machine
