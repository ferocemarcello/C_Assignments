IN=${RANDOM};
VAR=0;
while ((${IN}%10!=2))
do
((VAR=${VAR}+1))
echo ${IN};
IN=${RANDOM};
done
echo ${VAR};
