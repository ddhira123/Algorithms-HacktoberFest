import           Data.List  ((\\))
import qualified Data.Map   as Map
import           Data.Maybe (fromMaybe)

type Graph = Map.Map Int [Int]

graph :: Graph
graph = Map.fromAscList [
  (0, [1, 2, 3]),
  (1, [2]),
  (2, [0]) ]

dfsHelper :: Graph -> [Int] -> [Int] -> [Int]
dfsHelper graph [] _ = []
dfsHelper graph (current:rest) visited = current:(dfsHelper graph (rest ++ toVisit) (current:visited))
  where neighbors =  Map.findWithDefault [] current graph
        toVisit = neighbors \\ (rest ++ visited)

dfs :: Graph -> Int -> [Int]
dfs graph root = dfsHelper graph [root] []

main :: IO ()
main = do
  putStrLn $ show $ dfs graph 0
