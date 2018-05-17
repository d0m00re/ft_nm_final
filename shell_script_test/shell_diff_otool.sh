#!/bin/sh

echo $1
otool -t $1 > coucou
./ft_otool $1 > coucou2
result=$(diff coucou coucou2)
echo $result
