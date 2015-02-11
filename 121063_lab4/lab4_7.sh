echo 'Do you want to revoke the read and write permissions for file $a?'
echo 'If yes then press y otherwise n'
read b
if [ $b = 'y' ]
then 
echo "Write the code for the permission"
read c
chmod $c $#
else
echo No changes needed
fi
