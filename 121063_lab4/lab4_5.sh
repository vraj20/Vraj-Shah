echo "enter basic salary for calculating HRA";
read s;
if [ "$s" -gt "0" ] 
then
echo "HRA IS : 0.12 * $s" | bc
else
echo "enter proper Salary Carefully, it should not be nagetive.."
fi
