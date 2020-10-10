data Tree t = Node t (Tree t) (Tree t) | Nilt deriving (Read, Show)

insert :: Ord t => Tree t -> t -> Tree t
insert Nilt x = Node x Nilt Nilt 
insert (Node x treeL treeR) num = ins num x
    where ins num x
            | num < x = (Node x (insert treeL num) treeR)
            | otherwise = (Node x treeL (insert treeR num))

-- Receive a tree and a list of numbers and insert them into the tree
insertList :: Ord t => Tree t -> [t] -> Tree t
insertList tree (x:[]) = insert tree x
insertList tree (x:xs) = insertList t xs
    where t = insert tree x