#include "board.hpp"
Board setStandardBoard(){
	vector<Piece> white,black;
					//white
	//pawns
	white.push_back(Piece(Position(0,1), 1, pawn));
	white.push_back(Piece(Position(1,1), 1, pawn));
	white.push_back(Piece(Position(2,1), 1, pawn));
	white.push_back(Piece(Position(3,1), 1, pawn));
	white.push_back(Piece(Position(4,1), 1, pawn));
	white.push_back(Piece(Position(5,1), 1, pawn));
	white.push_back(Piece(Position(6,1), 1, pawn));
	white.push_back(Piece(Position(7,1), 1, pawn));
	
	//rooks
	white.push_back(Piece(Position(0,0), 1, rook));
	white.push_back(Piece(Position(7,0), 1, rook));
	
	//knights
	white.push_back(Piece(Position(1,0), 1, knight));
	white.push_back(Piece(Position(6,0), 1, knight));
	
	//bishop
	white.push_back(Piece(Position(2,0), 1, bishop));
	white.push_back(Piece(Position(5,0), 1, bishop));
	
	//king
	white.push_back(Piece(Position(3,0), 1, king));
	
	//queen
	white.push_back(Piece(Position(4,0), 1, queen));
	
					//black
	//pawns
	black.push_back(Piece(Position(0,6), -1, pawn));
	black.push_back(Piece(Position(1,6), -1, pawn));
	black.push_back(Piece(Position(2,6), -1, pawn));
	black.push_back(Piece(Position(3,6), -1, pawn));
	black.push_back(Piece(Position(4,6), -1, pawn));
	black.push_back(Piece(Position(5,6), -1, pawn));
	black.push_back(Piece(Position(6,6), -1, pawn));
	black.push_back(Piece(Position(7,6), -1, pawn));
	
	//rooks
	black.push_back(Piece(Position(0,7), -1, rook));
	black.push_back(Piece(Position(7,7), -1, rook));
	
	//knights
	black.push_back(Piece(Position(1,7), -1, knight));
	black.push_back(Piece(Position(6,7), -1, knight));
	
	//bishop
	black.push_back(Piece(Position(2,7), -1, bishop));
	black.push_back(Piece(Position(5,7), -1, bishop));
	
	//king
	black.push_back(Piece(Position(4,7), -1, king));
	
	//queen
	black.push_back(Piece(Position(3,7), -1, queen));
	return Board(white,black,1);
}
int main(){
	Board b=setStandardBoard();
	b.writeBoard("boardFile.txt");
}
