import           Data.List

merge :: ([Int], [Int]) -> [Int]
merge (xs, []) = xs
merge ([], ys) = ys
merge (x:xs, y:ys)
  | x < y = x:(merge (xs, y:ys))
  | otherwise = y:(merge (x:xs, ys))

splitHelper :: [Int] -> ([Int], [Int]) -> ([Int], [Int])
splitHelper [] split             = split
splitHelper (x:xs) (left, right) = splitHelper xs (right, x:left)

split :: [Int] -> ([Int], [Int])
split xs = splitHelper xs ([], [])

mapTuple :: (a -> b) -> (a, a) -> (b ,b)
mapTuple f (a, b) = (f a, f b)

mergeSort :: [Int] -> [Int]
mergeSort []  = []
mergeSort [x] = [x]
mergeSort xs  = merge $ mapTuple mergeSort $ split xs

main = do
    unsorted <- readLn :: IO [Int]
    let sorted = mergeSort unsorted
    print sorted
