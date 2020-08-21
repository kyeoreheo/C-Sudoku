#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sudoku {
public:
	void printBoard(vector<int> &board) { 
		for(int i = 0; i < board.size(); i += 3) {
			int rowSum = 0;
			for(int r = i; r < i + 3; r++) {
				cout << "[" << board[r] << "]" ;
				rowSum += board[r];
			}
			cout << " = " << rowSum <<  endl;
		}
		cout << " =  =  = " << endl;
		cout << " " << board[0] + board[3] + board[6];
		cout << " " << board[1] + board[4] + board[7];
		cout << " " << board[2] + board[5] + board[8];
		cout << endl;

		cout << "---------------------------" << endl;
	}

	int sumOfRow1(vector<int>& board) {
		return board[0] + board[1] + board[2];
	}
	int sumOfRow2(vector<int>& board) {
		return board[3] + board[4] + board[5];
	}
	int sumOfRow3(vector<int>& board) {
		return board[6] + board[7] + board[8];
	}
	int sumOfCol1(vector<int>& board) {
		return board[0] + board[3] + board[6];
	}
	int sumOfCol2(vector<int>& board) {
		return board[1] + board[4] + board[7];
	}
	int sumOfCol3(vector<int>& board) {
		return board[2] + board[5] + board[8];
	}
	int sumOfCross1(vector<int>& board) {
		return board[0] + board[4] + board[8];
	}
	int sumOfCross2(vector<int>& board) {
		return board[2] + board[4] + board[6];
	}

	bool isAnswer(vector<int>& board) {
		bool result = true;
		vector<int> sums; 
		sums.push_back(sumOfRow1(board)); 
		sums.push_back(sumOfRow2(board));
		sums.push_back(sumOfRow3(board));
		sums.push_back(sumOfCol1(board));
		sums.push_back(sumOfCol2(board));
		sums.push_back(sumOfCol3(board));
		sums.push_back(sumOfCross1(board));
		sums.push_back(sumOfCross2(board));

		int firstElement = sums[0]; //15
		for(int i = 0; i < sums.size(); i++) {
			if(firstElement != sums[i]) 
				return false;
		}
		return result;
	}

	bool isCorrect(int index, vector<int> board, vector<int> possibleNumbers) {
		for(int i = 0; i < possibleNumbers.size(); i++) {
			vector<int> myPossibleNumber = possibleNumbers; //copy 1 [2]~9
			vector<int> myBoard = board; //copy

			myBoard.push_back(myPossibleNumber[i]); // 
			myPossibleNumber.erase(myPossibleNumber.begin() + i); // 
			printBoard(myBoard);

			if(myPossibleNumber.size() == 0) {
				if (isAnswer(myBoard)) {
					cout << "found it" << endl;
					return true; 
				} else {
					return false;
				}
			} else if(isCorrect(i, myBoard, myPossibleNumber)) {
				return true;
			} 
		}
		return false;
	}

	void run() {
		for(int i = 0; i < 9; i++) {
			possibleNumbers_.push_back(i + 1);
		}

		if (isCorrect(0, board_, possibleNumbers_)) {
			cout << "YAY" << endl;
		}
	}

private:
	vector<int> board_;
	vector<int> possibleNumbers_;
};





