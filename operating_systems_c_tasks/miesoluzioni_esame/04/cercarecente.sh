#!/bin/bash
RECENT="";
for name in `find  /usr/include/linux/ -name *.h -type f`; do
if [[ ${RECENT} -ot ${name} ]] ; then
RECENT=${name};
fi;
done;
echo ${RECENT}
