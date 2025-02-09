
#!/bin/bash

if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <N> <word> <filename>"
  exit 1
fi

N=$1
word=$2
filename=$3

if [ ! -f "$filename" ]; then
  echo "Error: File '$filename' does not exist."
  exit 1
fi

word_count=$(grep -o -w "$word" "$filename" | wc -l)

if [ "$word_count" -gt "$N" ]; then
  sed -i "s/\b$word\b//g" "$filename"
  echo "Removed all occurrences of '$word' from '$filename' as it appeared more than $N times."
else
  echo "The word '$word' appears $word_count times, which is not more than $N. No changes made."
fi
