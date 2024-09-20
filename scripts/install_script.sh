#!/bin/bash

package=htop

sudo apt install $package >> package_install_results.log

if [ $? -eq 0 ]
then 
  echo "The installation of $package was successful"
  echo "the new command is availiable here: "
  which $package
else
  echo "$package failed to install" >> package_install_failure.log
fi
