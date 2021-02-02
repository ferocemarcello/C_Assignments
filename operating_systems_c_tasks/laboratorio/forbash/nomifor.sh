#!/bin/bash
$COUNT;
for ((COUNT=0; ${COUNT}<10;COUNT=${COUNT}+1));
do
	mv 1.${COUNT} 2.${COUNT};
done
