#!/bin/bash


cd ..

read -p 'Введите полный путь к файлу ' path
read -p 'Введите строку которую хотите изменить ' old_str
read -p 'Введите строку на которую хотите поменять ' new_str

if [[ -n "$path" && -n "$old_str" && -n "$new_str" ]]; then
    sed -i '' "s/$old_str/$new_str/g" $path
    size=$(stat -f "%z" "$path")
    datetime=$(stat -f "%Sm" -t "%Y-%m-%d %H:%M" "$path")
    key=$(shasum -a 256 "$path" | awk '{print $1}')
    echo "${path} - ${size} - ${datetime} - ${key} - sha256" >> src/files.log
    echo "OK."
else
    echo "Одно из веденных полей была пуста"
fi
