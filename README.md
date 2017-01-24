# Algorithms

1.InsertionSort  done

Pseudocode：
1.
INSERTION-SORT (A, n)⊳A[1 . . n]
    for j ←2 to n 
        do  key ←A[ j]
            i ←j –1
            while  i > 0 and  A[i] > key
                do A[i+1] ←A[i]
                    i ←i –1
            A[i+1] = key
