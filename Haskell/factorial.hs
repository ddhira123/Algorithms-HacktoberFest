factorial 2 = 2
factorial n = n * (factorial (n - 1))

main = do
    n <- readLn :: IO Int
    print (factorial n)
