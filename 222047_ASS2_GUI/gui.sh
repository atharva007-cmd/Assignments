#!/bin/bash
HEIGHT=15
WIDTH=80
CHOICE_HEIGHT=10
MENU="Please select an option from the following:"
gdialog --msgbox "\tWelcome." \ 10 30 50
while [ "$CHOICE" != 6 ]
do
	
	OPTIONS=(1 "Insert"
         2 "Display"
         3 "Search"
         4 "Delete"
         5 "Modify"
         6 "Exit" )

	CHOICE=$(gdialog --clear \
                --menu "$MENU" \
                $HEIGHT $WIDTH $CHOICE_HEIGHT \
                "${OPTIONS[@]}" \
                2>&1 >/dev/tty)

clear
case $CHOICE in
        1)
            sh ./insert.sh;;
        2)
            sh ./display.sh;;
        3)
            sh ./search.sh;;
        4)
        	sh ./delete.sh;;
        5)
        	sh ./modify.sh;;
esac 
done
