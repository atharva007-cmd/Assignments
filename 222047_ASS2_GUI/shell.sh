#!/bin/bash
while [ "$choice" != 6 ]
do
	echo -e "\n\n\t\tWELCOME"
	echo -e "Please select an option from the following: \
	         \n\t1) Insert\n\t2) Display All\n\t3) Search\n\t4) Delete\n\t5) Modify\n\t6)Exit"
	echo "Enter your choice: "
	read choice
	case $choice in
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
