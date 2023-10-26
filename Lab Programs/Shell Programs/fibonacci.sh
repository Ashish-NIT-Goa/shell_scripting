echo "Enter n"
read n
fib0=0
fib1=1
fib2=1
index=0
while [ $index -le $n ] 
do
   echo "$fib0"
   fib0=$((fib1))
   fib1=$((fib2))
   fib2=$((fib0+fib1))
   index=$((index+1))
done
   
