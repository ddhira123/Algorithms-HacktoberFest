set -x
arr=(120 30 40 1 4 6 7 8 2 11 33 45 2 3 4 2 1 4 2 3 4 5 12 22 1 1 1 1 1 45 5 120)

insertion_sort(){
local len=${#arr[@]}
for (( i=1; i<$len; i++ ))
do
	local key=${arr[$i]}
	local j=$i
	while(( ($j>0) && (${arr[$j-1]}>$key) )) 
	do
	arr[$j]=${arr[$(( $j-1 ))]}
	(( j-- ))
	done
	arr[$j]=$key
done

}

echo ${arr[@]}
insertion_sort
echo ${arr[@]}