// #include <iostream>
// #include <vector>

// int main() {
//     // Number of vertices in gthe graph.
//     int V = 4;
    
//     // Initialize a 4x4 matrix with 0 edges.
//     std::vector<std::vector<int>> adjMatrix(V, std::vector<int>(V, 0));

//     // Insert the weighted directed edges.
//     adjMatrix[0][1] = 3; // A -> B
//     adjMatrix[0][2] = 2; // A -> C
//     adjMatrix[2][1] = 1; // C -> B
//     adjMatrix[3][0] = 4; // D -> A

//     // Display the adjcency matrix results.
//     char labels[] = {'A', 'B', 'C', 'D'};
//     std::cout << "  A B C D" << std::endl;
//     for (int i = 0; i < V; i++) {
//         std::cout << labels[i] << " ";
//         for (int j = 0; j < V; j++) {
//             std::cout << adjMatrix[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }


#include <iostream>

int main() {
    // 4x4 matrix initialized to 0
    int matrix[4][4] = {0};

    // vertex variables
    const int A = 0, B = 1, C = 2, D = 3;

    // Set graph edges and weights
    matrix[A][B] = 3; 
    matrix[A][C] = 2; 
    matrix[C][B] = 1; 
    matrix[D][A] = 4; 

    std::cout << "  -----------------" << std::endl;
    std::cout << "  | A | B | C | D |" << std::endl;
    std::cout << "  -----------------" << std::endl;

    char labels[4] = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < 4; i++) {
        std::cout << labels[i] << " | ";
        for (int j = 0; j < 4; j++) {
            std::cout << matrix[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << "  -----------------" << std::endl;
    }

    return 0;
}

