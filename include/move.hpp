#ifndef MOVE
#define MOVE
#include "position.hpp"
class Move{
	public:
	Position initial;
	Position final;
	bool isValid;
	Move(Position p1, Position p2){
		initial=p1;
		final=p2;
		isValid=true;
	}
};

#endif
