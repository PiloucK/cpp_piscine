#!/bin/bash

echo 

whiptail --title "Simple c++ class setup" --inputbox "To create the .cpp and .hpp file, type the name of the class:" 16 72

if whiptail --yesno "Is this a good question" 16 72 ;then
    echo Yes
else
    echo No
fi
