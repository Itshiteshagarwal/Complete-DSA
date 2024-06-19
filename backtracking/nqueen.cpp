// #include <bits/stdc++.h>

// void addsolution(std::vector<std::vector<int>>& ans, std::vector<std::vector<int>>& board, int n) {
//     std::vector<int> temp;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             temp.push_back(board[i][j]);
//         }
//     }
//     ans.push_back(temp);
// }

// bool issafe(int row, int col, std::vector<std::vector<int>>& board, int n) {
//     // Check for row
//     for (int i = 0; i < col; i++) {
//         if (board[row][i] == 1)
//             return false;
//     }

//     // Check upper diagonal
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//         if (board[i][j] == 1)
//             return false;
//     }

//     // Check lower diagonal
//     for (int i = row, j = col; i < n && j >= 0; i++, j--) {
//         if (board[i][j] == 1)
//             return false;
//     }

//     return true;
// }

// // Solve function
// void solve(int col, std::vector<std::vector<int>>& ans, std::vector<std::vector<int>>& board, int n) {
//     if (col == n) {
//         addsolution(ans, board, n);
//         return;
//     }

//     for (int row = 0; row < n; row++) {
//         if (issafe(row, col, board, n)) {
//             // If it's safe to place a queen, mark the cell as 1
//             board[row][col] = 1;

//             // Recursively solve for the next column
//             solve(col + 1, ans, board, n);

//             // Backtrack to remove the queen and try the next row
//             board[row][col] = 0;
//         }
//     }
// }

// std::vector<std::vector<int>> nQueens(int n) {
//     // Initialize an n*n matrix with 0
//     std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
//     std::vector<std::vector<int>> ans;

//     // Call the solve function
//     solve(0, ans, board, n);

//     return ans;
// }  
//tc O(facto n) and sc - O(n*n)
