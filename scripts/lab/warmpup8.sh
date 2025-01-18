printstatus(){
  # if (($# == 4)); then
  #   echo "2 arguments in total"
  # fi
  # if (($# == 3)); then
  #   echo "3 arguments in total"
  # fi
  # if (($# == 2)); then
  #   echo "2 arguments in total"
  # fi
  # if (($# == 1)); then
  #   echo "1 arguments in total"
  # fi

  echo "Hello"
  if (($# <= 1)); then
    echo "Less than required arguments"
    exit 1
  fi

  if (($#==1));
  then
    files=$((ls | wc -l))
  fi
while true;
do
 echo " 1. total number of files in the directory dty"
 echo " 2. list the extensions of all the files present in dty"
 echo " 3. count of files having each extension."
 
read -p "Enter choice" choice
case $choice in
  1)
    echo "contains $files no of files"
    ;;
  2)
    ;;
  3)
    ;;
  4)
    exit 1;;
  *)
    echo "Invalid choice"
    ;;
esac  
done
}

