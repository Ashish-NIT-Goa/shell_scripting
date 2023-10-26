echo "Enter a:"
read a
echo "Enter b:"
read b
temp=$((a))
a=$((b))
b=$((temp))
echo "Before swapping a=$b ,b=$a"
echo "After swapping a=$a ,b=$b"
