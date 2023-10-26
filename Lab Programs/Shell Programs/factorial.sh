echo "number:"
read n
factorial=1
while [ $n -gt 0 ]
do
   factorial=$((factorial*n))
   n=$((n-1))
done
echo "$factorial"
