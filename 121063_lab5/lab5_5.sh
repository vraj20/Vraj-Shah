 echo enter the file name
read f1
echo enter the second file name
read f2
if [ -e $f1 ]
then
if [ -e $f2 ]
then
cat $f1>>$f2
else
cat $f1>$f2
fi
fi
