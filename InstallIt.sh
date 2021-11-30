#!/bin/bash

install_file () {
	echo "Installing $1"
	cp $1 /usr/avr/include/CxFramework/
}

create_install_dir () {
	echo "Creating install dir /usr/avr/include/$1"
	mkdir "/usr/avr/include/$1"
}

echo "Hello in CxPins installer!"
echo "Installing for avr-gcc..."
echo ""

if [ ! -d /usr/avr/include/CxFramework/ ]; then 
	create_install_dir CxFramework
fi

install_file CxPins.h
