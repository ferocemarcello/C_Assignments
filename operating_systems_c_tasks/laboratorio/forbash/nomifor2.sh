#!/bin/bash
$COUNT;
for ((COUNT=0; ${COUNT}<10;COUNT=${COUNT}+1));
do
	mv 2.${COUNT} 1.${COUNT};
done
