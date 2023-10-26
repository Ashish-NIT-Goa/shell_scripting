echo "Enter string:"
read str
revstr=$(echo "$str" | rev)
if [ "$str" = "$revstr" ] 
then
   echo "Palindrome"
else
   echo "Not palindrome"
fi
