#ifndef POSITION
#define POSITION

#include<cmath>
#include<assert.h>

class Position
{
  public:	
  int x;
  int y;
  Position(){
  x=0;
  y=0;
  }
  Position(int a, int b)
  {
    x=a;
    y=b;
  }

  void operator = (Position p)
  {
  	x=p.x;
  	y=p.y;
  }

  bool operator ==(Position a)
  {
  	return (x == a.x  && y == a.y) ;

  }

};

bool isValid(int x,int y){
	return (x>=0 && x<=7 && y>=0 && y<=7);
}
bool areDiagonal(Position p1, Position p2)
{
   if( std::abs(p1.x - p2.x) == std::abs(p1.y - p2.y) )
   	
   return true;
   
   return false;
}

bool areVertical(Position p1, Position p2)
{
   if(std::abs(p1.y - p2.y) == 0)
   	
   return true;
   
   return false;
}

bool areHorizontal(Position p1, Position p2)
{
   if( std::abs(p1.x - p2.x) == 0)
   	
   return true;
   
   return false;
}




#endif
