echo "Enter the method by which you want to delete record"
echo "1.Name  2.Roll No"
read num

case $num in
	1)
		echo "Enter name to delete"
		read name
		sed -i "/$name/d"  add.txt;;
	2)
		echo "Enter Roll NO to delete"
		read roll
		sed -i "/$roll/d"   add.txt;;
esac
