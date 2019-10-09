arr=( 1 4 5 9 10 20 1 3 4 22 300 127 456 909 101 )
selection_sort() {
local len=${#arr[@]}
for (( i = 0; i<$len; i++ ))
do
	local least=$i
	for (( j=$i+1; j<$len; j++ ))
	do
	if(( ${arr[$j]} < ${arr[$least]}))
	then
	least=$j
	fi
	done
	local temp=${arr[$i]}
	arr[$i]=${arr[$least]}
	arr[$least]=$stemp
	
done
}

echo ${arr[@]}
selection_sort
echo ${arr[@]}
