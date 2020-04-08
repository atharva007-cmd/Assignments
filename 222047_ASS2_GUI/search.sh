echo "Enter the method by which you want to search record"
echo "1.Name  2.Roll NO"
read num

case $num in
	1)
		echo "Enter name to search"
		read name
		grep $name  add.txt;;
	2)
		echo "Enter Roll No to search"
		read roll
		grep $roll  add.txt;;
esac
