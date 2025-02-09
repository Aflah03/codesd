#!/bin/bash

while true; do
  echo "Process Information Menu:"
  echo "a) Number of processes forked since the last boot"
  echo "b) Number of processes currently in the system"
  echo "c) Number of running processes"
  echo "d) Number of blocked processes"
  echo "e) PID of the current shell"
  echo "f) Number of context switches performed by this shell (voluntary and involuntary)"
  echo "q) Quit"
  echo -n "Enter your choice: "
  read choice

  case $choice in
    a)
      forked_processes=$(awk '/processes/ {print $2}' /proc/stat)
      echo "Number of processes forked since the last boot: $forked_processes"
      ;;
    b)
      current_processes=$(ps -e | wc -l)
      echo "Number of processes currently in the system: $current_processes"
      ;;
    c)
      running_processes=$(ps -eo stat | grep -c '^R')
      echo "Number of running processes: $running_processes"
      ;;
    d)
      blocked_processes=$(ps -eo stat | grep -c '^D')
      echo "Number of blocked processes: $blocked_processes"
      ;;
    e)
      current_shell_pid=$$
      echo "PID of the current shell: $current_shell_pid"
      ;;
    f)
      context_switches=$(cat /proc/$$/status | grep -E 'voluntary_ctxt_switches|nonvoluntary_ctxt_switches')
      echo "Context switches performed by this shell:"
      echo "$context_switches"
      ;;
    q)
      echo "Exiting the script. Goodbye!"
      exit 0
      ;;
    *)
      echo "Invalid choice. Please try again."
      ;;
  esac
  echo
done
