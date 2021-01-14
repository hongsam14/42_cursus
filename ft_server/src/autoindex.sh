#!/bin/bash
echo "check environment variable about AUTOINDEX..."
if [ $AUTOINDEX = "" ]
then
	echo "No environment variable about AUTOINDEX. use default setting... >> autoindex on "
	mv default_org default
elif [ $AUTOINDEX = off ]
then
	echo "change autoindex... >> autoindex $AUTOINDEX "
	cat default_org | sed 's/autoindex on/autoindex off/' > default
#rm default_org
else
	echo "nothing changes... >> autoindex $AUTOINDEX "
	mv default_org default
fi
rm default_org
