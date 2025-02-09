#!/bin/bash
while true; do
echo "MENU"
echo "1.addition"
echo "2.subtraction"
echo "3.multiplication"
echo "4.division"
echo "5.sin"
echo "6.cosine"
echo "7.tan"
echo "8.power"
echo "9.square root"
echo "10.exit"
echo -n "enter your choice :"
read choice
case $choice in
1)echo "sum"
echo "input the first number"
read a
echo "input the second number"
read b
c=$((a+b))
echo "sum is $c"
;;
2)echo "substraction"
echo "enter first value"
read a
echo "enter sec value"
read b
c=$((a-b))
echo "difference is $c"
;;
3) echo "multiplication"
echo "input first value"
read a
echo "input sec value"
read b
c=$((a*b))
echo "product is $c"
;;
4)echo "Division"
echo "Input first value:"
read a
echo "Input second value:"
read b
if [ $b -eq 0 ]; then
echo "Division not possible (cannot divide by zero)."
else
result=$(echo "scale=2; $a / $b" | bc -l)
echo "Result of division: $result"
fi
;;
5)echo "sin operation"
calculate_sine() {
angle_in_degrees=$1
angle_in_radians=$(echo "$angle_in_degrees * (4 * a(1)) / 180"
,→ | bc -l)
sine_value=$(echo "s($angle_in_radians)" | bc -l)
echo "Sine of $angle_in_degrees is: $sine_value"
}
read -p "Enter the angle in degrees: " angle
calculate_sine "$angle"
;;
6) echo "cosine operation"
calculate_cosine() {
angle_in_degrees=$1
angle_in_radians=$(echo "$angle_in_degrees * (4 * a(1)) / 180"
,→ | bc -l)
cosine_value=$(echo "c($angle_in_radians)" | bc -l)
echo "Cosine of $angle_in_degrees is: $cosine_value"
}
read -p "Enter the angle in degrees: " angle
calculate_cosine "$angle"
;;
7)echo "tan"
calculate_tangent() {
angle_in_degrees=$1
angle_in_radians=$(echo "$angle_in_degrees * (4 * a(1)) / 180"
,→ | bc -l)
tangent_value=$(echo "s($angle_in_radians) /
,→ c($angle_in_radians)" | bc -l)
echo "Tangent of $angle_in_degrees is: $tangent_value"
}
read -p "Enter the angle in degrees: " angle
calculate_tangent "$angle"
;;
8)echo "power"
calculate_power() {
base=$1
exponent=$2
result=$(echo "$base ^ $exponent" | bc -l)
echo "$base raised to the power of $exponent is: $result"
}
read -p "Enter the base: " base
read -p "Enter the exponent: " exponent
calculate_power "$base" "$exponent"
;;
9)echo "square root"
calculate_square_root() {
number=$1
square_root=$(echo "scale=10; sqrt($number)" | bc -l)
echo "Square root of $number is: $square_root"
}
read -p "Enter the number: " number
calculate_square_root "$number"
;;
10)
echo "exiting good bye"
break
;;
*)
echo "invalid choice"
;;
esac
echo
done
