# Sparse Matrix Implementation (C++) with linked_list

### Problem
Implement a linked list–based sparse matrix representation in C++.

### Approach
- I used a linked list where each node stores (row, column, value) of a non-zero element.  
- The program inserts each non-zero entry as a node in the list and then a function scans through the list and prints the full matrix in dense form.  

Example for testing
Input

Enter number of rows: 3
Enter number of columns: 4
Enter number of non-zero entries: 3
Enter non-zero entries as:
Entry 1: 0 1 5
Entry 2: 1 3 7
Entry 3: 2 0 4

Output:
0 5 0 0
0 0 0 7
4 0 0 0