read -p "Enter file name" fname
if [! -f $fname]
then 
	echo "invalid file name"
	exit 1
fi
while read line
do 
	echo $line
done < $fname
