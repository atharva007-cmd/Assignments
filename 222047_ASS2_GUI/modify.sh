echo "Enter the content by which you want to Modify record"
echo "1.Name  2.Roll No"
read num

case $num in
	1)
		echo "Enter name to modify"
		read name
		echo "Enter new name"
		read new
		sed -i "s/$name\t/$new/g"  add.txt;;
	2)
		echo "Enter Roll No to modify"
		read roll
		echo "Enter new Roll No"
		read nroll
		sed -i "s/$roll/$nroll/g"  add.txt;;
esac
