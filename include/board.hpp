#ifndef board
#define board
#include<list>
enum playerColor={white,black}
class Board{
	public:
	list<Piece> whitePieces;
	list<Piece> blackPieces;
	playerColor turn;
	Board applyMove(Move m){
	}
	Move optimalMove(){
	}
	list<Move> getMoves(){
	}
	bool checkMove(Move m){
	}
	int getBoardValue(){
	}
	int[][] getArray(){
	}
	const Piece pieceAt(const Position p){
	}
}
#endif
