#!/bin/bash

HOST='10.7.8.9'
PORT='2121'
USER='anonymous'
PASSWD='anonymous'
REMPATH=/data/pkg
files=(./*.pkg)

while [ ${#files[@]} -gt 0 ]; do
 curl --user "${USER}:" -T "${files[0]}" ftp://${HOST}:${PORT}${REMPATH}/ || echo "Error $?"
 files=("${files[@]:1}") 
done
echo "File(s) uploaded with status $?"
