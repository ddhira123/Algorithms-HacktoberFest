/**
 * factorial
 * 
 * Max input value with signed long = 20, otherwise it gives an inaccurate result
 */
public class Factorial {

    public static void main(String[] args) {

        Long input = (long) 5;
        if (args.length > 0) {
            try {
                input = Long.parseLong(args[0]);
            } catch (NumberFormatException nfe) {
                System.out.println("Using default input 5");
            }
        }
        Long res = (long) 1;

        for (Long i = input; i > (long) 0; i--) {
            res *= i;
        }

        System.out.println("Result: " + res);
    }
}