#include "board.hpp"
int main(){
	Move m = Board::doEverything("boardFile.txt", "ipFile.txt");
	/*
		Now write stepper code:
		1. move to m.initial
		2. close gripper
		3. move to m.final - m.initial
		4. open gripper
		5. move to origin
	*/
}
