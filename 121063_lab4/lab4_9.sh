echo "Enter fileName:"
read a
cat $a | tr -d '\n' | tr -s " " '\n' | wc -l
