#!/bin/bash

command=htop

if command -v $command
then 
  echo "$command is availiable lets run it"
else
  echo "comman is not availaible lets install it"
fi

$command
