#!/usr/bin/env bash
rev=''
for ch in `echo "$1" | grep -o .`; do rev=$ch$rev; done
echo $rev

# Solution 1
# echo $1 | rev
