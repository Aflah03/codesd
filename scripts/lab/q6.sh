#!/bin/bash

is_prime() {
    local num=$1
    if [ "$num" -lt 2 ]; then
        return 1
    fi
    for ((i=2; i*i<=num; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            return 1
        fi
    done
    return 0
}

print_primes_in_range() {
    read -p "Enter the start of the range: " start
    read -p "Enter the end of the range: " end
    echo "Prime numbers between $start and $end:"
    for ((i=start; i<=end; i++)); do
        if is_prime $i; then
            echo -n "$i "
        fi
    done
    echo
}

print_primes_in_range
