// #include <bits/stdc++.h> 
// using namespace std;

// bool issafe(int row, int col, vector<vector<int>>& board, int val) {
//     int n = board.size();

//     // Check row and column
//     for (int i = 0; i < n; i++) {
//         if (board[row][i] == val || board[i][col] == val) {
//             return false;
//         }
//     }

//     // Check 3x3 grid
//     int startRow = 3 * (row / 3);
//     int startCol = 3 * (col / 3);
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (board[startRow + i][startCol + j] == val) {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// bool solve(vector<vector<int>>& board) {
//     int n = board.size();

//     for (int row = 0; row < n; row++) {
//         for (int col = 0; col < n; col++) {
//             // Cell is empty
//             if (board[row][col] == 0) {
//                 for (int val = 1; val <= 9; val++) {
//                     if (issafe(row, col, board, val)) {
//                         board[row][col] = val;

//                         if (solve(board)) {
//                             return true;
//                         } else {
//                             board[row][col] = 0;
//                         }
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void solveSudoku(vector<vector<int>>& sudoku) {
//     solve(sudoku);
// }
