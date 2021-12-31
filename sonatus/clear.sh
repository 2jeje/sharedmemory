#!/bin/sh

echo "Clearing...."


ipcs -m | grep `whoami` | awk '{ print $2 }' | xargs -n1 ipcrm -m
