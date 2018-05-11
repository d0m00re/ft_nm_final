#!/bin/sh

echo $1
nm $1 > coucou
./ft_nm $1 > coucou2
result=$(diff coucou coucou2)
echo $result
