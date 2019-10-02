/*
 * @param(end) number to end at
 * @return fibonacci number at end.
 */

export function fibonacci(end) {
  if(!Number.isInteger(end)) {
    return -1;
  } else {
    if(end > 1) {
      return fibonacci(end - 1) + fibonacci(end - 2);
    }
    else {
      return end;
    }
  }
}
export function fibTests() {
  console.assert(fibonacci(1) === 1);
  console.assert(fibonacci(0) === 0);
  console.assert(fibonacci(3.6) === -1);
  console.assert(fibonacci(6) === 8);
}