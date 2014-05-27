#ifndef PIECE
#define PIECE
#include<iostream>
#include<vector>
#include "constants.hpp"
#include "move.hpp"
#include "position.hpp"
using namespace std;
enum pieceType {
	empty, pawn, rook, bishop, knight, queen, king
};

class Piece {
public:
	pieceType type;
	int pieceValue;
	Position pos;
	char color;
	bool alive;
	bool operator ==(Piece p2) {
		if (type == p2.type && pos == p2.pos && color == p2.color
				&& alive == p2.alive)
			return true;
		return false;
	}
	Piece() {
		pos = Position();
		type = empty;
		alive = false;
		color = 0;
		pieceValue = 0;
	}
	Piece(Position p, char pc, pieceType t) {
		pos = p;
		alive = true;
		color = pc;
		type = t;
		pieceValue = 0;
		// for pieceValue implement:
		switch (type) {
		case empty:
			pieceValue = 0;
			break;
		case pawn:
			pieceValue = pawnValue;
			break;
		case rook:
			pieceValue = rookValue;
			break;
		case knight:
			pieceValue = knightValue;
			break;
		case king:
			pieceValue = kingValue;
			break;
		case queen:
			pieceValue = queenValue;
			break;
		case bishop:
			pieceValue = bishopValue;
			break;
		}

	}
	vector<Move> knightMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		if (!alive)
			return ret;

		const char x = pos.x;
		const char y = pos.y;
		if (isValid(x - 1, y + 2)
				&& (myBoard[x - 1][y + 2] == 0
						|| myBoard[x - 1][y + 2] == -color))
			ret.push_back(Move(pos, Position(x - 1, y + 2)));
		if (isValid(x + 1, y + 2)
				&& (myBoard[x + 1][y + 2] == 0
						|| myBoard[x + 1][y + 2] == -color))
			ret.push_back(Move(pos, Position(x + 1, y + 2)));
		if (isValid(x + 2, y + 1)
				&& (myBoard[x + 2][y + 1] == 0
						|| myBoard[x + 2][y + 1] == -color))
			ret.push_back(Move(pos, Position(x + 2, y + 1)));
		if (isValid(x - 2, y + 1)
				&& (myBoard[x - 2][y + 1] == 0
						|| myBoard[x - 2][y + 1] == -color))
			ret.push_back(Move(pos, Position(x - 2, y + 1)));
		if (isValid(x - 1, y - 2)
				&& (myBoard[x - 1][y - 2] == 0
						|| myBoard[x - 1][y - 2] == -color))
			ret.push_back(Move(pos, Position(x - 1, y - 2)));
		if (isValid(x + 1, y - 2)
				&& (myBoard[x + 1][y - 2] == 0
						|| myBoard[x + 1][y - 2] == -color))
			ret.push_back(Move(pos, Position(x + 1, y - 2)));
		if (isValid(x + 2, y - 1)
				&& (myBoard[x + 2][y - 1] == 0
						|| myBoard[x + 2][y - 1] == -color))
			ret.push_back(Move(pos, Position(x + 2, y - 1)));
		if (isValid(x - 2, y - 1)
				&& (myBoard[x - 2][y - 1] == 0
						|| myBoard[x - 2][y - 1] == -color))
			ret.push_back(Move(pos, Position(x - 2, y - 1)));
		return ret;
	}
	vector<Move> kingMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		if (!alive)
			return ret;

		const char x = pos.x;
		const char y = pos.y;
		for (char i = -1; i <= 1; i++) {
			for (char j = -1; j <= 1; j++) {
				if (i == 0 && j == 0)
					continue;
				if (isValid(x + i, y + j)
						&& (myBoard[x + i][y + j] == (-color)
								|| myBoard[x + i][y + j] == 0))
					ret.push_back(Move(pos, Position(x + i, y + j)));
			}
		}
		return ret;
	}
	vector<Move> queenMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		if (!alive)
			return ret;

		const char x = pos.x;
		const char y = pos.y;
		//up
		for (char otherx = x, othery = y + 1; othery <= 7; othery++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//down
		for (char otherx = x, othery = y - 1; othery >= 0; othery--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//right
		for (char otherx = x + 1, othery = y; otherx <= 7; otherx++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//left
		for (char otherx = x - 1, othery = y; otherx >= 0; otherx--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//upright
		for (char otherx = x + 1, othery = y + 1; otherx <= 7 && othery <= 7;
				otherx++, othery++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//downright
		for (char otherx = x + 1, othery = y - 1; otherx <= 7 && othery >= 0;
				otherx++, othery--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//upleft
		for (char otherx = x - 1, othery = y + 1; otherx >= 0 && othery <= 7;
				otherx--, othery++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//downleft
		for (char otherx = x - 1, othery = y - 1; otherx >= 0 && othery >= 0;
				otherx--, othery--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		return ret;
	}
	vector<Move> bishopMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		if (!alive)
			return ret;

		const char x = pos.x;
		const char y = pos.y;
		//upright
		for (char otherx = x + 1, othery = y + 1; otherx <= 7 && othery <= 7;
				otherx++, othery++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//downright
		for (char otherx = x + 1, othery = y - 1; otherx <= 7 && othery >= 0;
				otherx++, othery--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//upleft
		for (char otherx = x - 1, othery = y + 1; otherx >= 0 && othery <= 7;
				otherx--, othery++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//downleft
		for (char otherx = x - 1, othery = y - 1; otherx >= 0 && othery >= 0;
				otherx--, othery--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		return ret;
	}
	vector<Move> emptyMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		return ret;
	}
	vector<Move> pawnMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		if (!alive)
			return ret;
		char x = pos.x;
		char y = pos.y;
		char change = color == 1 ? 1 : -1; //define what "ahead" is
		if (isValid(x, y + change) && (myBoard[x][(y + change)]) == 0) { //one step ahead
			ret.push_back(Move(pos, Position(x, y + change)));

			if (((y == 1 && color == 1) || (y == 6 && color == -1))
					&& myBoard[x][y + 2 * change] == 0) //two steps ahead
				ret.push_back(Move(pos, Position(x, y + 2 * change)));
		}
		if (isValid(x + 1, y + change)
				&& myBoard[x + 1][y + change] == (-color)) //one step ahead, and one to the right
			ret.push_back(Move(pos, Position(x + 1, y + change)));
		if (isValid(x - 1, y + change)
				&& myBoard[x - 1][y + change] == (-color)) //one step ahead and one to the left
			ret.push_back(Move(pos, Position(x - 1, y + change)));
		return ret;
	}

	vector<Move> rookMoves(const char myBoard[8][8]) {
		vector<Move> ret;
		if (!alive)
			return ret;

		const char x = pos.x;
		const char y = pos.y;
		//up
		for (char otherx = x, othery = y + 1; othery <= 7; othery++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//down
		for (char otherx = x, othery = y - 1; othery >= 0; othery--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//right
		for (char otherx = x + 1, othery = y; otherx <= 7; otherx++) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		//left
		for (char otherx = x - 1, othery = y; otherx >= 0; otherx--) {
			if (isValid(otherx,othery) && myBoard[otherx][othery] == 0)
				ret.push_back(Move(pos, Position(otherx, othery)));
			if (isValid(otherx,othery) && myBoard[otherx][othery] == color)
				break;
			if (isValid(otherx,othery) && myBoard[otherx][othery] == (-color)) {
				ret.push_back(Move(pos, Position(otherx, othery)));
				break;
			}
		}
		return ret;
	}

	vector<Move> getMoves(const char myBoard[8][8]) {
		//myBoard=board;
		vector<Move> ret;
		if (!alive)
			return ret;
		switch (type) {
		case empty:
			ret = emptyMoves(myBoard);
			break;
		case pawn:
			ret = pawnMoves(myBoard);
			break;
		case bishop:
			ret = bishopMoves(myBoard);
			break;
		case rook:
			ret = rookMoves(myBoard);
			break;
		case knight:
			ret = knightMoves(myBoard);
			break;
		case king:
			ret = kingMoves(myBoard);
			break;
		case queen:
			ret = queenMoves(myBoard);
			break;
		}
		return ret;
	}
};
#endif
