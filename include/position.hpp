#ifndef POSITION
#define POSITION

#include<cmath>
#include<assert.h>

class Position
{
  public:	
  int x;
  int y;

  Position(int a, int b)
  {
    assert(a<9);
    assert(b<9);
  }

  void operator = (Position p)
  {
  	x=p.x;
  	y=p.y;
  }

  bool operator ==( Position a)
  {
  	return (x == a.x  && y == a.y) ;

  }

};


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