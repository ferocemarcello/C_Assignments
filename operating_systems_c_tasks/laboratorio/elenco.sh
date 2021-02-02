#!/bin/bash
LungNomiDirectory=0;
for name in `ls ./` ;  do
	echo vaffa
done
if [[ -d ${name} ]] ; then
echo “${name} è una cartella";
((${LungNomiDirectory}=${LungNomiDirectory}+${#name}))
	echo vaffa2
else
echo “${name} è un file";
	echo vaffa3
fi;
done
echo ${LungNomiDIrectory}
