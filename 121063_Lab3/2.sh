if [ $# -ne 2 ]
then
	echo 'Usage filename x op y' 
	echo 'where x and y are numbers and op is operation'
	exit 1
else
	
	echo "Addition: ` expr $1 + $2 `"
	echo "Multiplication: ` expr $1 \* $2 `"
	echo "Subtraction ` expr $1 - $2 `"
	echo "Division ` expr $1 \/ $2 `"
	
fi
