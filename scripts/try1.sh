if (($# !=2))
then 
	echo "insufficent"
	exit 1
else
	sum=$(($1+$2))
	echo "SUm is $sum"
fi
