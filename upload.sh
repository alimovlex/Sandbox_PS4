#!/bin/sh

HOST='10.6.9.69'
PORT='2121'
USER='anonymous'
PASSWD='anonymous'
FILE='IV0000-BREW00085_00-NETWORKKEX000000.pkg'

ftp -n $HOST -p $PORT <<END_SCRIPT
user ${USER} ${PASSWD}
cd /data/pkg
put $FILE
quit
END_SCRIPT
echo "The file has been successfully uploaded"