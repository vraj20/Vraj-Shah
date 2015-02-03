echo enter number 1
read a
echo enter number 2
read b 
if [ $a -gt $b ]
then
	echo "$a is greater than $b"
elif [ $a -eq $b ]
then
	echo "both numbers are equal"
else 
	echo "$b is greater than $a"
fi

