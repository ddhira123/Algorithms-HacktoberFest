data Tree t = Node t (Tree t) (Tree t) | Nilt deriving (Read, Show)

depth :: Tree t -> Int
depth Nilt = 0
depth (Node x tl tr) = max depthLeft depthRight
    where depthLeft = (depth tl) + 1
          depthRight = (depth tr) + 1