if [ ! -f $3 ] ; then
	echo "$3 not found"
	exit 1
fi
count=$(grep -o "\b$2\b" $3 | wc -l)
if (($1 < count)); then
	sed -i "s/\b$2\b//g" "$3"
fi

