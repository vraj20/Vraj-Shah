echo "Pattern you want to search:";
 read pat;
echo "which file you are looking for this Pattern?";
read files;
b= grep $pat $files;
if [ $? -eq $files ]
then              
echo found it is...;
else
echo Sorry not found...;
fi
