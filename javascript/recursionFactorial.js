/*
Returns a factorial of a number by recursion
*/

export default function factorial_recursive(number) {
	if(number == 0) {
		return 1;
	} else {
		return number * factorial_recursive(number - 1); 
	}

	console.log('factorial: ', factorial_recursive(number));
}