#!/bin/bash

# The assumptions are: same user and same password, and (for certain commands) also same OS distro
# But I think this can be relaxed with a little effort

#Is it better to connect as user and then do su or to connect directly as root?
# Well, you have to transmit the password over the network anyway,
# so as long as it's encrypted it's alright.
# now I need to generate a KEY PAIR 
# not only for gbornia and student
# but also for gbornia and root
# The public key for gbornia is already there, I only have to add it to 
# the authorized_keys in ROOT

  #CLEARLY IF YOU SELECT FROM a window in Windows that 
  #DOES NOT COMMUNICATE WITH THE X SERVER!!!

# Notice: the machines with DUAL BOOT will SHARE the ADDRESS with WINDOWS,
# but the machines with the MONITOR SWITCH will NOT, because 
# they are two separate computers with two separate network cards,
# so they will have DIFFERENT IP ADDRESSES!

for computer in \
 129.118.33.49 \
129.118.30.37 \
129.118.30.8  \
129.118.30.141 \
129.118.30.146 \
129.118.30.25  \
129.118.30.55 \
129.118.30.153 \
129.118.30.166  \
129.118.30.156  \
129.118.30.169  \
129.118.33.42  \
129.118.30.1  \
129.118.30.171   \
129.118.30.172  \
129.118.30.178  \
129.118.30.127  \
129.118.30.200
#  129.118.30.225  #this is the lab113 podium
# 
# The next ones are the Windows counterparts for the ones with "monitor switch"
# (all the first row and the extremes of the second row): 
# 129.118.30.103
# 129.118.30.74 
# 129.118.30.134 
# 129.118.30.83 
# 129.118.30.108 
# 129.118.30.56 
# 129.118.30.227 
# 129.118.30.77 
do 
echo "==========" $computer  "=========="

# command to check if the SSH server is running or not
# command to deactivate kwallet in all computers
# if Windows is running, is there any way to restart it and then tell the grub to choose opensuse, FROM NETWORK... 
# Well I guess that is a bit too ambitious...


# BEGIN USER PASSWORDLESS LOGIN CONFIGURATION  =================

# USER - STEP 1 
# scp $HOME/.ssh/id_rsa.pub student@$computer:~/   #is this tilde going to be the one of THAT computer? Well hopefully so...

# USER - STEP 2
# ssh -X  student@$computer "  
# mkdir -p ~/.ssh/
# cat ~/id_rsa.pub >> ~/.ssh/authorized_keys
# rm ~/id_rsa.pub
# "
# END USER PASSWORDLESS LOGIN CONFIGURATION  =================



# BEGIN ROOT PASSWORDLESS LOGIN CONFIGURATION  =================

# ROOT - STEP 1 
# scp $HOME/.ssh/id_rsa.pub root@$computer:~/

# ROOT - STEP 2
# ssh -X  root@$computer "
# mkdir -p ~/.ssh/
# cat ~/id_rsa.pub >> ~/.ssh/authorized_keys
# rm ~/id_rsa.pub
# "

# END ROOT PASSWORDLESS LOGIN CONFIGURATION   =================


# CONTAINER FOR THE LIST OF COMMANDS TO PERFORM
ssh  student@$computer "
kdialog --display :0 --progressbar 'HELLOOO!' &
"

### root
# init 6
# service SuSEfirewall2 status
# zypper up -l

### student
# echo Good morning
# kdialog --display :0 --progressbar 'HELLOOO!' &
# exit




done

# how do i do this popup without keeping the terminal busy?!?
# this popup seems to disconnect only if the end-user clicks on OK
# also, can I login as ROOT and CONNECT to the DISPLAY of a USER?
# it seems like it behaves differently with user login or root login...

# ok, there are two things that seem to work differently...:
# ROOT vs USER
# -X vs -Y
# so what should I do?!?
# If the current display belongs to "student", an ssh with root says 
# that you cannot even connect to the X server :0 !
# So, I tried with a graphical login for root, and if you ssh with root IT WORKS,
# so the morale is that you have to do SSH with the SAME USER 
# to whom the current display belongs!

# Then, another fact is that the terminal STOPS BEING BUSY only if you go
# on the real display and you click OK on the popup...
# and this is what i would like to change...

#OK I FOUND THE SOLUTION! It must not be --msgbox, I guess because that is somehow "active",
# but it must be --passivepopup or --progressbar... The best one is --progressbar!

# it is clear that by connecting through ssh I don't actually connect to the  current display 
# (as a matter of fact, there may be no currently logged in user running a display)
# In order to connect to the CURRENT DISPLAY, in case there is one,
# I should do vnc or something else


# how to add a user in each computer
# useradd student -m -c "Student"
# passwd student  # then go interactive, to enable student login


