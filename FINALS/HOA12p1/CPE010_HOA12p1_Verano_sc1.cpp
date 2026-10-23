#include <iostream>
#include <vector>

int Paths(const std::vector<std::vector<int>>& matrix, int m, int n, int cost) {
    // first condition, no negative values.
    if (m < 0 || n < 0 || cost < 0) {
        return 0;
    }
    
    // second condition, Once in the starting cell, calculations 
    // and checks the sum of the path if it is equivalent to 
    // the cost (target value)
    if (m == 0 && n == 0) {
        return (matrix[m][n] == cost) ? 1 : 0;
    }
    
    // third condition, If m has reached 0, It means it's in the
    // first row / top row. Meaning it can only move left as a 
    // valid path to reach (0, 0)
    if (m == 0) {
        return Paths(matrix, 0, n - 1, cost - matrix[m][n]);
    }

    // last condition, The opposite of the m, if n has reached 0, it
    // memans it's in the first column or left most of the matrix, therefore,
    // it can only move up as a valid path to reach (0, 0)
    if (n == 0) {
        return Paths(matrix, m - 1, 0, cost - matrix[m][n]);
    }

    // if no condition has been met yet, it will keep recursing until
    // it reaches the end of its condition.
    int fromTop = Paths(matrix, m - 1, n, cost - matrix[m][n]);
    int fromLeft = Paths(matrix, m, n - 1, cost - matrix[m][n]);

    return fromTop + fromLeft;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    // represents the number of columns
    int M = matrix.size();

    // represents the number of rows
    int N = matrix[0].size();

    // lookups a target cost from 20 - 30. verifying all possible paths.
    for (int target = 20; target <= 30; target++) {
        int pathFound = Paths(matrix, M - 1, N - 1, target);

        std::cout << " Target Cost [" << target << "] : ";
        if (pathFound > 0) {
            std::cout << pathFound << " Path(s) Found in the matrix." << std::endl;
        }
        else {
            std:: cout << "0 paths found in the matrix." << std::endl;
        }

    }
    return 0;
}
