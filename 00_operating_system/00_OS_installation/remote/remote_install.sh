#!/bin/bash

# You need to do this process FROM an OPENSUSE system (or at least from a system that has grub, I guess)
# Do these operations as root:

######## REMOTE INSTALLATION ########################
######## REMOTE INSTALLATION ########################
######## REMOTE INSTALLATION ########################
cd /boot
wget --output-document=vmlinuz.install http://download.opensuse.org/tumbleweed/repo/oss/boot/x86_64/loader/linux
wget --output-document=initrd.install http://download.opensuse.org/tumbleweed/repo/oss/boot/x86_64/loader/initrd

# The problem here is that the instructions that are online are for GRUB, not for GRUB2!!!
#now to add the entry in grub2 maybe it's enough to grub-update...

cd /boot/grub/

# menu.lst
# here we want to append this stuff:

# title Boot -- openSUSE tumble
#    root (hd0,0)
#    kernel /boot/vmlinuz.install usessh=1 sshpassword="12345678" install=http://download.opensuse.org/factory/repo/oss/ hostip=10.0.0.2 netmask=255.255.255.0 gateway=10.0.0.1 nameserver=129.118.1.3
#    initrd /boot/initrd.install

# default 0

# (see the script setupgrubfornfsinstall)

# then REBOOT (init 6)

# Then connect again:
# ssh -X root@192.168.10.10  #here you have to put the password, I WANT TO DO IT PASSWORDLESS
# then run yast

# /usr/lib/YaST2/startup/YaST2.ssh

######## REMOTE INSTALLATION ########################
######## REMOTE INSTALLATION ########################
######## REMOTE INSTALLATION ########################
