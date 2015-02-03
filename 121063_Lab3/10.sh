fruits=("apple" "banana" "grapes" "watermelon" "peach" "mango");
echo -n "enter the fruit you want to search  "
read string
search=`echo ${fruits[*]} | grep "$string"`

if [ "${search}" != "" ]; then
  echo -n list contains: $string 
else
  echo -n $string not list
fi
