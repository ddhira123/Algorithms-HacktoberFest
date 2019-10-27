public String fizzBuzz(int number) {
    if (number % 15 == 0) {
        return "fizzbuzz";
    } else if (number % 5 == 0) {
        return "buzz";
    } else if (number % 3 == 0) {
        return "fizz";
    }
    return String.valueOf(number);
}
