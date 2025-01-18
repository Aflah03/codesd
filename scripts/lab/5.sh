read -p "Enter the start and end " start end
for((i=$start;$i<=$end;i++));
do
  flag=0
  for((j=2;$j<$i;j++));
  do
    if(($i%$j==0));
    then
      flag=1
      break
    fi
  done
  if(($flag==0));
  then
    echo $i
  fi
done




# read -p "Enter the N " n
# for((i=2;$i<=n;i++));
# do
#   flag=0
#   for((j=2;$j<i;j++));
#   do
#     if(($i%$j==0));
#     then
#       flag=1
#       break
#     fi
#   done
#   if(($flag==0));
#   then
#     echo $i
#   fi
# done
