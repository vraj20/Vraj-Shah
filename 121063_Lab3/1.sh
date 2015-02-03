echo enter number 1
read n1
echo enter number 2
read n2
echo n1 is $n1 and n2 is $n2 
echo 'Enter what operation you want to perform:'
echo 1-addition
echo 2-subtraction
echo 3-multiplication
echo 4-division
echo 5-Modulo
read ch
if [ $ch = 1 ]
then 
echo `expr $n1 + $n2`
fi
if [ $ch = 2 ]
then 
echo `expr $n1 - $n2`
fi
if [ $ch = 3 ]
then 
echo `expr $n1 \* $n2`
fi
if [ $ch = 4 ]
then 
if [ $n2 != 0 ]
then
echo `expr $n1 \/ $n2`
fi
fi
if [ $ch = 5 ]
then 
echo ` expr $n1 \% $n2`
fi
