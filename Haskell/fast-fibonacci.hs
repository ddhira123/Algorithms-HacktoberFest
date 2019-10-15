fiboPairs :: [(Int, Int)]
fiboPairs = iterate nextFib (0, 1)
  where nextFib (a, b) = (b, a + b)

fibonacci :: Int -> Int
fibonacci = fst . (fiboPairs!!)

main :: IO ()
main = do
    n <- readLn :: IO Int
    print (fibonacci n)
