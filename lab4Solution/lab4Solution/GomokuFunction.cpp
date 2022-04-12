#include "gameBase.h"



using namespace std;
GomokuGame::GomokuGame() {
	
	boardWidth = 19;
	boardHeight = 19;
	connectNum = 5;
	piece = "B";
	winner = " ";
	player1 = {};
	player2 = {};
}

GomokuGame::GomokuGame(int boardSize, int connectNumInput) {
	boardWidth = boardSize;
	boardHeight = boardSize;
	connectNum = connectNumInput;
	piece = "B";
	winner = " ";
	player1 = {};
	player2 = {};
}
/*Declare and define a public virtual (non-static) done() method that takes no parameters
(other than the this pointer that's passed implicitly to all non-static methods and operators)
and has a bool return type. The method should return true if 5 stones of the same color
are in a row or column or diagonal (otherwise the method should return false.*/


bool GomokuGame::done() {
	int first_piece_index = 0;
	size_t diagonal_upper_right = static_cast<size_t>(boardWidth) + 1;
	size_t diagonal_lower_right = static_cast<size_t>(boardWidth) - 1; 
	size_t vert_inc = static_cast<size_t>(boardWidth);
	size_t diag_inc_r = static_cast<size_t>(boardWidth)+1;
	size_t diag_inc_l = static_cast<size_t>(boardWidth)-1;
	size_t connectNumLen = connectNum - 1;
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight); i++) {
		for (size_t j = first_piece_index; j < static_cast<size_t>(boardWidth); j++) {
			size_t index = boardWidth * i + j;

			//Check for vertical 
			if (i + connectNumLen < static_cast<size_t>(boardHeight)) {
				if (pieceList[index].boardDisplay != " ") {
					bool doneCheck = true;
					size_t tempConnect = 1;
					while (doneCheck && tempConnect <= connectNumLen) {
						if (pieceList[index].boardDisplay != pieceList[(long)index + vert_inc * tempConnect].boardDisplay) {
							doneCheck = false;
						} 
						tempConnect++;
					}
					if (doneCheck) {
						winner = pieceList[index].boardDisplay;
						return true;
					}
				}
			}

			//check for horizontal
			if (j + connectNumLen < static_cast<size_t>(boardWidth)) {
				if (pieceList[index].boardDisplay != " ") {
					bool doneCheck = true;
						size_t tempConnect = 1;
						while (doneCheck && tempConnect <= connectNumLen) {
							if (pieceList[index].boardDisplay != pieceList[(long)index + tempConnect].boardDisplay) {
								doneCheck = false;
							}
							tempConnect++;
						}
					if (doneCheck) {
						winner = pieceList[index].boardDisplay;
						return true;
					}
				}
			}

			//diagonal to the right check
			if ((i < boardHeight - (connectNumLen - 1)) && (j < boardHeight - (connectNumLen - 1))) {
				if (pieceList[index].boardDisplay != " ") {
					bool doneCheck = true;
					size_t tempConnect = 1;
					while (doneCheck && tempConnect <= connectNumLen) {
						if (pieceList[index].boardDisplay != pieceList[(long)index + diag_inc_r*tempConnect].boardDisplay) {
							doneCheck = false;
						}
						tempConnect++;
					}
					if (doneCheck) {
						winner = pieceList[index].boardDisplay;
						return true;
					}
				}
			}
			
			if ((i < boardHeight - (connectNumLen - 1)) && (connectNumLen < j)) {
				if (pieceList[index].boardDisplay != " ") {
					bool doneCheck = true;
					size_t tempConnect = 1;
					size_t temp_i = i+1;
					size_t temp_j = j-1;
					while (doneCheck && tempConnect <= connectNumLen) {
						if (pieceList[index].boardDisplay != pieceList[static_cast<size_t>(boardWidth) * temp_i + temp_j].boardDisplay) {
							doneCheck = false;
						}
						tempConnect++;
						temp_i++; 
						temp_j--;
					}
					if (doneCheck) {
						winner = pieceList[index].boardDisplay;
						return true;
					}
				}
			}
			
		}
	}
	
	//game is not done yet
	return false;
}

/*Declare and define a public virtual (non-static) draw() method that takes no
parameters(other than the this pointer that's passed implicitly to all non-static methods
and operators) and has a bool return type. The method should return true if there is no
path left that can lead to 5 stones in a row, otherwise the method should return false.*/

/*
bool GomokuGame::draw() {
	size_t first_piece_index = 0;
	size_t diagonal_upper_right = static_cast<size_t>(boardWidth) + 1;
	size_t diagonal_lower_right = static_cast<size_t>(boardWidth) - 1;

	//horizontal check for black
	for (size_t i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			//starting from the initial piece, check all 5 spots in the path if there is a white stone.
			//Path is valid if there are no white stones
			if (pieceList[j].boardDisplay != "W" && pieceList[j + displace1].boardDisplay != "W" && pieceList[j + displace2].boardDisplay != "W" &&
				pieceList[j + displace3].boardDisplay != "W" && pieceList[j + displace4].boardDisplay != "W") {
				return false;
			}
		}
	}

	//horizontal check for white
	for (size_t i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + displace1].boardDisplay != "B" && pieceList[j + displace2].boardDisplay != "B" &&
				pieceList[j + displace3].boardDisplay != "B" && pieceList[j + displace4].boardDisplay != "B") {
				return false;
			}
		}
	}

	//vertical check for black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + boardWidth].boardDisplay != "W" &&
				pieceList[j + displace2 * static_cast<size_t>(boardWidth)].boardDisplay != "W" &&
				pieceList[j + displace3 * static_cast<size_t>(boardWidth)].boardDisplay != "W" &&
				pieceList[j + displace4 * static_cast<size_t>(boardWidth)].boardDisplay != "W") {
				return false;
			}
		}
	}

	//vertical check for white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + boardWidth].boardDisplay != "B" && 
				pieceList[j + displace2* static_cast<size_t>(boardWidth)].boardDisplay != "B" &&
				pieceList[j + displace3* static_cast<size_t>(boardWidth)].boardDisplay != "B" &&
				pieceList[j + displace4* static_cast<size_t>(boardWidth)].boardDisplay != "B") {
				return false;
			}
		}
	}

	//diagonal to upper right, black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + displace2 * diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + displace3 * diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + displace4 * diagonal_upper_right].boardDisplay != "W") {
				return false;
			}
		}
	}

	//diagonal to upper right, white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + diagonal_upper_right].boardDisplay != "B" && 
				pieceList[j + displace2* diagonal_upper_right].boardDisplay != "B" &&
				pieceList[j + displace3* diagonal_upper_right].boardDisplay != "B" &&
				pieceList[j + displace4* diagonal_upper_right].boardDisplay != "B") {
				return false;
			}
		}
	}

	//diagonal to bottom right, black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + displace2 * diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + displace3 * diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + displace4 * diagonal_lower_right].boardDisplay != "W") {
				return false;
			}
		}
	}

	//diagonal to upper right, white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + displace2 * diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + displace3 * diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + displace4 * diagonal_lower_right].boardDisplay != "B") {
				return false;
			}
		}
	}

	// no possible path for a winning condition
	return true;
}

*/

bool GomokuGame::draw() {

	int num2Win = 5;//Number of pieces to connect to win

	//Rows are from bottom to top, columns are from left to right
	

	//Iterate through each row
	for (int row = boardHeight - 1; row >= 0; --row) {

		//Iterate through each column (of each row)
		for (int col = 0; col < boardWidth - 1; ++col) {

			int index = row * boardWidth + col;

			//Only check horizontal empty spaces for pieces at 0 to (boardwidth -num2Win) columns
			if (col <= boardWidth - num2Win) {

				
				bool allEmpty = true;//Tracks if all horizontal pieces are emtpy

				//Check if this and the next four pieces are empty, if so, not draw
				for (int i = index; i < index + num2Win; ++i) {

					//If any pieces is not empty (aka is "B" or "W" piece), the horizontal line is not empty
					if ((pieceList[i].boardDisplay.compare("B") == 0) || (pieceList[i].boardDisplay.compare("W") == 0) ){
						allEmpty = false;
					}
				}

				//If there are five consecutive spaces, the game is not draw, so false is returned
				if (allEmpty) {
					return false;
				}	

			}

			//Only check vertical empty spaces for pieces at row (boardHeight - 1) to (num2Win - 1)
			if (row >= num2Win - 1) {

				bool allEmpty = true;//Tracks if all vertical pieces are emtpy

				//Check if this and the next four pieces are empty, if so, not draw
				for (int i = index; i >= index - (num2Win - 1) * boardWidth; i-=boardWidth) {

					//If any pieces is not empty (aka is "B" or "W" piece), the horizontal line is not empty
					if ((pieceList[i].boardDisplay.compare("B") == 0) || (pieceList[i].boardDisplay.compare("W") == 0)) {
						allEmpty = false;
					}
				}

				//If there are five consecutive spaces, the game is not draw, so false is returned
				if (allEmpty) {
					return false;
				}


			}

			//Only check main diagonal if there are enough pieces below and on the right to check
			if ((row >= num2Win - 1) && (col <= boardWidth - num2Win)) {

				bool allEmpty = true;

				//Check if this and next four pieces in the bottom right diagonal are empty
				for (int i = index; i >= (index - (num2Win - 1) * (boardWidth - 1)); i -= (boardWidth - 1)) {

					//If any pieces is not empty (aka is "B" or "W" piece), the main disgonal line is not empty
					if ((pieceList[i].boardDisplay.compare("B") == 0) || (pieceList[i].boardDisplay.compare("W") == 0)) {
						allEmpty = false;
					}

				}

				if (allEmpty) {
					return false;
				}


			}

			//Only check minor diagonal (bottom left to upper right) if there are enough pieces above and on the right




		}
	}
	return false;
}

int GomokuGame::turn() {
	unsigned int x_coor = 0;
	unsigned int y_coor = 0;
	int promptResult;
	if (piece == "B") {
		cout << "current player: B" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl; //print board
			cout << "Player B: "; //print player's past moves.
			for (unsigned int i = 0; i < player1.size(); i++) {
				cout << player1[i].first << "," << player1[i].second << "; ";
			}
			cout << endl;
			piece = "W"; // switch player turn
			moves_num++; //increment total moves played by both players.
		}
		else {
			return promptResult;
		}
	}
	else if (piece == "W") {
		cout << "current player: W" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl;
			cout << "Player W: ";
			for (unsigned int i = 0; i < player2.size(); i++) {
				cout << player2[i].first << "," << player2[i].second << "; ";
			}
			cout << endl;
			piece = "B";
			moves_num++;
		}
		else {
			//tracks whether a player quit game, the program failed to extract coordinates, or if the coordinate was valid.
			return promptResult;
		}
	}
	return success;
}
void GomokuGame::print() {
	cout << *this << endl;
}



