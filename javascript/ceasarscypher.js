function rot13(str) {
  //empty arr array that will be filled by .push later on
  var arr = [];

  //typical for loop to iterate through str using i
  for (i = 0; i < str.length; i++) {
    //char is declared and given value of the ascii character code determined by i example 65 = A
    var char = str.charCodeAt(i);

    //this keeps the special characters unmodified and pushes them to the array arr
    if (char < 65) {
      arr.push(String.fromCharCode(char));
    } else if (char >= 65 && char < 78) {
      //going after letters in the beginning of the alphabet but not past 77 because adding 13 will take it out of the ascii alphabet
      arr.push(String.fromCharCode(char + 13));
    } else if (char > 77 && char < 91) {
      //going after letters at the end of the alphabet and subtracting 13
      arr.push(String.fromCharCode(char - 13));
    }
  }

  //returning the result from above but joined back together
  return arr.join("");
}
rot13("JUBN V XABJ WNINFPEVCG!");
