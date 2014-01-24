#include <iostream>
using namespace std;
struct Treap
{
	 int x;//Key
	 int y;//Priority
	 Treap * Left;
	 Treap * Right;	 
	 Treap() { }
     Treap(int x, int y) : x(x), y(y), Left(NULL), Right(NULL) { }
};
Treap Merge(Treap l,Treap r)
{   	
	if(!&l) return r;
	if(!&r) return l;
	if(l.y > r.y )
	{  
		Treap newR =  Merge(l.Right, r);
		return Treap(l.x,l.y,l.Left,newR);
	} 
	else
	{
		Treap newL = Merge(&l,& r.Left);
		return Treap(&r.x,&r.y,&newL,&r.Right);	
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	Treap a, b,c;
	a.x = 10;
	a.y = 12;
	b.x = 23;
	b.y = 13;
    c = Merge(a,b);
    cout<<c.x<<" "<<c.Left.x<<" "<<c.Right.x;         
    return 0;
}