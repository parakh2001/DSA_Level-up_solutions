#include<bits/stdc++.h>
using namespace std;
const int N = 9;
// Function to check if a digit can be placed in a particular cell
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
	// Check if num is not in the current row and column
	for (int i = 0; i < N; ++i) {
		if (grid[row][i] == num || grid[i][col] == num) {
			return false;
		}
	}
	// Check if num is not in the 3x3 box
    // 	int startRow = row - row % 3;
    // int startCol = col - col % 3;
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
	for (int i = startRow; i < startRow+3; ++i) {
		for (int j = startCol; j < startCol+3; ++j) {
			if (grid[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}
// Function to find an unassigned cell
bool findUnassignedLocation(vector<vector<int>>& grid, int& row, int& col) {
	for (row = 0; row < N; ++row) {
		for (col = 0; col < N; ++col) {
			if (grid[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}

// Recursive function to solve the Sudoku puzzle
bool helper(vector<vector<int>>& grid) {
	int row, col;
	if (!findUnassignedLocation(grid, row, col)) {
		return true; // All cells are filled
	}

	for (int num = 1; num <= 9; ++num) {
		if (isSafe(grid, row, col, num)) {
			grid[row][col] = num; // Assign the digit

			if (helper(grid)) {
				return true; // Move to the next unassigned cell
			}

			grid[row][col] = 0; // Backtrack
		}
	}

	return false; // No valid digit can be placed
}

vector<vector<int> > solveSudoku(vector<vector<int> > grid){
    if(helper(grid)){
        return grid;
    }
    return grid;
}
