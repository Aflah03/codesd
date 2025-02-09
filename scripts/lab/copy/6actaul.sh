#!/bin/bash

# Function to convert a decimal number to binary
convert_to_binary() {
  local decimal=$1
  local binary=""
  while (( decimal > 0 )); do
    binary=$(( decimal % 2 ))$binary
    decimal=$(( decimal / 2 ))
  done
  echo "$binary"
}

# Function to convert a decimal number to octal
convert_to_octal() {
  local decimal=$1
  local octal=""
  while (( decimal > 0 )); do
    octal=$(( decimal % 8 ))$octal
    decimal=$(( decimal / 8 ))
  done
  echo "$octal"
}

# Function to convert a decimal number to hexadecimal
convert_to_hexadecimal() {
  local decimal=$1
  local hex=""
  local hex_map="0123456789ABCDEF"
  while (( decimal > 0 )); do
    remainder=$(( decimal % 16 ))
    hex="${hex_map:$remainder:1}$hex"
    decimal=$(( decimal / 16 ))
  done
  echo "$hex"
}

# Main menu-driven program
while true; do
  echo "Choose an option:"
  echo "1. Convert to Binary"
  echo "2. Convert to Octal"
  echo "3. Convert to Hexadecimal"
  echo "4. Exit"
  read -p "Enter your choice: " choice

  case $choice in
    1)
      read -p "Enter a positive decimal number: " decimal
      if [[ $decimal =~ ^[0-9]+$ ]]; then
        echo "Binary: $(convert_to_binary $decimal)"
      else
        echo "Invalid input. Please enter a valid positive decimal number."
      fi
      ;;
    2)
      read -p "Enter a positive decimal number: " decimal
      if [[ $decimal =~ ^[0-9]+$ ]]; then
        echo "Octal: $(convert_to_octal $decimal)"
      else
        echo "Invalid input. Please enter a valid positive decimal number."
      fi
      ;;
    3)
      read -p "Enter a positive decimal number: " decimal
      if [[ $decimal =~ ^[0-9]+$ ]]; then
        echo "Hexadecimal: $(convert_to_hexadecimal $decimal)"
      else
        echo "Invalid input. Please enter a valid positive decimal number."
      fi
      ;;
    4)
      echo "Exiting the program."
      exit 0
      ;;
    *)
      echo "Invalid choice. Please choose a valid option."
      ;;
  esac
done

