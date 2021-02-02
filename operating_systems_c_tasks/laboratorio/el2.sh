#!/bin/bash
for name in `ls ./`
do
if [[ -d ${name} ]];
then
echo "${name} è una cartella"
else
echo "${name} è un file"
fi
done
