module Main 
where

problem1 xs = sum [x | x <- xs, x `mod` 3 == 0 || x `mod` 5 == 0]
main = do
    (putStrLn . show . problem1) [1..999]
