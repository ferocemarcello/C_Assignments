#!/bin/bash
$COUNT;
$VAR;
for ((COUNT=0; ${COUNT}<10;COUNT=${COUNT}+1));
do
	((VAR=9-${COUNT}));
	mv 1.${COUNT} 2.${VAR};
done
