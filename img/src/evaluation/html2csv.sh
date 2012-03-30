#!/bin/bash

gawk -v RS='</tr>' -v FS='</td>[[:space:]]*<td>' -v OFS=';' '{$1=$1} gsub(/.*<td>|<\/td>.*/,"")' $1 | sed 's/ /-/g' | sed 's/;/ /g'
