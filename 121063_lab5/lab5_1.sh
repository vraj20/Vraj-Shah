str=($(echo $1|fold -w1 ))
for (( i=${#str[@]}-1;i>=0;i--));
do 
echo "${str[i]}";
 done
