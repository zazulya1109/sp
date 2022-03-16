#!/bin/bash
echo "Program - lab 1"
echo "This program will help you find files in the directory nastya, find the checksum and write it down"
echo "Zazulya Nastya, gr 718 :)"

while true; do

	while true; do

	#1
	echo -e  "Current directory: `pwd` "
echo " "
echo " "
	#2
 	read  -p "Path to file1:" path_file1
	#patn_file1 = "/tmp/1.odt"
	if [ -e "$path_file1" ]
	then
		echo "Right :)"
	else
		echo "Wrong :("
		break
	fi
echo " "
echo " "
	#3
	k_sum=$(md5sum $path_file1 2>error.txt)
	echo "Checksum generation of the first file1: $k_sum"
echo " "
echo " "
	#4
	read  -p "Path to file1:" path_file2
        #patn_file1 = "/tmp/2.odt"
        if [ -e "$path_file2" ]
	then
		echo "Right :)"
        else
		echo "Wrong :("
        	break
        fi
echo " "
echo " "
	#5
	if [ -s "$path_file2" ]
	then echo "The file is not empty, do you want to download it? (y/n)"
		read yn
                if [ $yn = y ]
                then
                        echo $k_sum | tee $path_file2
                        break
                fi
        else
                echo $k_sum | tee $path_file2
                break
        fi

done

	echo "The program has ended. Do you want to continue? (y/n)"
		read yn
                if [ $yn = y ]
                then continue
                else break
                fi
done
