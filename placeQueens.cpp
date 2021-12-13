#include<iostream>
#include<vector>

using namespace std;

//check if column and diagonal lines at (row,column) are available
bool isAvailable(vector<vector<int>>board, int row, int column) {  
	for (int i = 0; i < board.size(); i++) if (board[i][column] == 1) return false;
	for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 1) return false;
	for (int i = row, j = column; i >= 0 && j < board.size(); i--, j++) if (board[i][j] == 1) return false;
	return true;
}

void printBoard(vector<vector<int>>board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) cout << board[i][j] << " ";
		cout << endl;
	}
}

//backtracking 
void placeQueen(vector<vector<int>>board, int row) {
	if (row < board.size()) {
		for (int col = 0; col < board.size(); col++) {
			if (isAvailable(board, row, col)) {
				board[row][col] = 1;
				placeQueen(board, row + 1);
				board[row][col] = 0;
			}
		}
	}
	else {
		printBoard(board);
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>>board(n, vector<int>(n, 0));
	placeQueen(board, 0); 
}
