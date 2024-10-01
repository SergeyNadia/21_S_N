#!/bin/bash

cd ..

read -p 'Введите полный путь к файлу ' path

if [ -f $path ]; then
    count=$(cat $path | wc -l | xargs)
    uni_file=$(awk '{print $1}' $path | sort | uniq | wc -l | xargs)
    changes=$(awk '{if ("NULL"!=$8) print $8}' $path | sort | uniq | wc -l | xargs)
    echo "${count} ${uni_file} ${changes}"
else
    echo "Ошибка: Файл не найден."
    exit 1
fi