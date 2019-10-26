
concatbuckets() {
echo ${bucket0[@]}
echo ${bucket1[@]}
echo ${bucket2[@]}
echo ${bucket3[@]}
echo ${bucket4[@]}
echo ${bucket5[@]}
echo ${bucket6[@]}
echo ${bucket7[@]}
echo ${bucket8[@]}
echo ${bucket9[@]}
}

emptybuckets(){
bucket0=()
bucket1=()
bucket2=()
bucket3=()
bucket4=()
bucket5=()
bucket6=()
bucket7=()
bucket8=()
bucket9=()
}
n=0
for i in $@
do
	if [ ${#i} -gt $n ]
	then
	n=${#i}
	fi
done

list=($( printf "%0${n}d " $@ ))
echo ${list[@]}

for (( i=n-1; i>=0; i-- ))
do
	emptybuckets
		for j in ${list[@]}
		do
		digit=${j:$i:1}
		case $digit in 
			0) bucket0+=( $j ) ;;
			1) bucket1+=( $j ) ;; 
			2) bucket2+=( $j ) ;; 
			3) bucket3+=( $j ) ;; 
			4) bucket4+=( $j ) ;; 
			5) bucket5+=( $j ) ;; 
			6) bucket6+=( $j ) ;; 
			7) bucket7+=( $j ) ;; 
			8) bucket8+=( $j ) ;; 
			9) bucket9+=( $j ) ;; 
		esac
		done
	list=( $( concatbuckets ) )
done

nopad=()
for k in ${list[@]}
do	
echo $((k*1))
nopad+=( $((k*1)) )
done
echo ${list[@]}
echo ${nopad[@]}
