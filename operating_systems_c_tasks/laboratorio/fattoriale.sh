#!/bin/bash
NUM=1
FAT=1
while (( "${NUM}" <= "$*" ))
do
# notare il ! davanti al NUM
# echo "arg ${NUM} is ${!NUM} "
((FAT=${NUM}*${FAT}))
((NUM=${NUM}+1))
done
echo ${FAT}
