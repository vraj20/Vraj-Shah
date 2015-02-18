a1=($(echo $1|fold -w1 ))
for (( i=${#a1[@]}-1;i>=0;i--));do
man=${a1[i]};
done
if [ "$temp" = "$man" ]
then
echo "It is Palindrome..."
else
echo "It is not Palindrome..."
fi


