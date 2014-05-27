#ifndef MOVE
#define MOVE
#include "position.hpp"
#include<iostream>
using namespace std;
class Move{
	public:
	Position initial;
	Position final;
	bool isValid;
	int value;
	Move(){
		initial=Position();
		final=Position();
		isValid=false;
		value=0;
	}
	Move(Position p1, Position p2){
		initial=p1;
		final=p2;
		isValid=true;
		value=0;
	}
	void display(){
		cout<<initial.x<<","<<initial.y<<" to "<<final.x<<","<<final.y<<" value: "<<value<<endl;
	}
	bool operator < (const Move& that){
		return (value<that.value);
	}
};
bool operator <(const Move& m1, const Move& m2){
	return (m1.value<m2.value);
}

#endif
