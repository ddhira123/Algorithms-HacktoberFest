fibonacci 1 = 1
fibonacci 2 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)


main = do
    n <- readLn :: IO Int
    print (fibonacci n)
