#!/bin/bash
# rename some files for better sorting
# i.e. rename "1-2.c" to "1-02.c" so it will be "smaller" 
# than "1-10.c"
#
path=~/workspace/knrC/
number=0
for cw in `ls $path | grep 'chapter[0-9][0-9]*'`
do
    chapterdir=${cw}"/"
    chapternum=`echo $chapterdir | cut -c 8`
    re=${chapternum}".[0-9].c"
    for i in `ls $chapterdir | grep $re`
    do
        no=`echo $i | cut -c 3`
        newname=${chapternum}"-0"${no}".c"
        mv ${chapterdir}${i} ${chapterdir}${newname}
        echo "${chapterdir}${i} ->  ${chapterdir}${newname}"
        number=$((number+1))
    done
done

echo "Rename done! $number filename(s) have been changed!"
