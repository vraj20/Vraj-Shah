echo -n "Enter any number whatever you want..."
read no
n=`expr $no / 2 `
i=2
Rem=0
if [ $no == 2 ]
then
Rem=0
elif [ $no == 3 ]
then 
Rem=0
else
while [ "$i" -le "$n" ]
do

Mod=`expr $no % $i `

if [ $Mod == 0 ]
then
Rem=1
fi

i=`expr $i + 1 `
done
fi

if [ $Rem == 1 ]
then
echo Not a prime number
else
echo It is  a prime number 
fi 
