#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
bool oneIntPoint(int x1,int y1,int x2,int y2,int x5,int y5,int x6,int y6)
{
	pair<int,int> p1[10];
	pair<int,int> p2[10];
	
	int x3 = x1;
	int y3 = y2;	
	int x4 = x2;
	int y4 = y1;


	//x2, y2;
	int x7 = x5;
	int y7 = y6;
	int x8 = x6;
	int y8 = y5;
	int same = 0;
	//cerr<<"\n-----------\n"<<x1<<" - "<<y1<<"\n"<<x2<<" - "<<y2<<"\n"<<x3<<" - "<<y3<<"\n"<<x4<<" - "<<y4<<"\n"<<x5<<" - "<<y5<<"\n"<<x6<<" - "<<y6<<x7<<" - "<<y7<<"\n"<<x8<<" - "<<y8;
	p1[1].first  = x1;
	p1[1].second = y1;
	
	p1[2].first  = x2;
	p1[2].second = y2;

	p1[3].first  = x3;
	p1[3].second = y3;

	p1[4].first  = x4;
	p1[4].second = y4;

	p2[1].first  = x5;
	p2[1].second = y5;

	p2[2].first  = x6;
	p2[2].second = y6;
	
	p2[3].first  = x7;
	p2[3].second = y7;
	
	p2[4].first  = x8;
	p2[4].second = y8;
	
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(p1[i].first  == p2[j].first && p1[i].second == p2[j].second && i!=j) same++;  		
		}
	}	
	if(same==1) return 1;
	else return 0;
}
bool intLine(int x1,int y1,int x2,int y2,int x5,int y5,int x6,int y6)
{   
	if(oneIntPoint(x1,y1,x2,y2,x5,y5,x6,y6)) return 0;
	//x1, y1;
	int x3 = x1;
	int y3 = y2;	
	int x4 = x2;
	int y4 = y1;

	//x2, y2;
	int x7 = x5;
	int y7 = y6;
	int x8 = x6;
	int y8 = y5;
	int from, to;
	
	if(y1>y3) {from = y3,to=y1;}
	else {from = y1, to = y3;}
	int same = 0;
	for(int i=from;i<=to;i++)
	{
		if(x1==x5 && i==y5 || x1==x6 && i==y6 || x1==x7 && i==y7 || x1==x8 && i==y8 )
		{
			cerr<<x1<<" "<<i<<endl;
			same++;
		}		
	}

	if(y2>y4) from = y4,to=y2;
	else from = y2, to = y4;
	for(int i=from;i<=to;i++)
	{
		if(x2==x5 && i==y5 || x2==x6 && i==y6 || x2==x7 && i==y7 || x2==x8 && i==y8 )
		{
			cerr<<x2<<" "<<i<<endl;
			same++;
		}		
	}
	if(x1 > x4) from=x4,to=x1;
	else from= x1, to = x4;
	for(int i=from;i<=to;i++)
	{
		if(y1==y5 && i==x5 || y1==y6 && i==x6 || y1==y7 && i==x7 || y1==y8 && i==x8 )
		{
			cerr<<i<<" "<<y1<<endl;
			same++;
		}		
	}
	if(x2 > x3) from=x3,to=x2;
	else from= x2, to = x3;
	for(int i=from;i<=to;i++)
	{
		if(y2==y5 && i==x5 || y2==y6 && i==x6 || y2==y7 && i==x7 || y2==y8 && i==x8 )
		{         
			cerr<<i<<" "<<y2<<endl;
			
			same++;
		}		
	}
	if(same>1) return 1;
	else return 0;

}
bool oneInAnother(int x1,int y1,int x2,int y2, int x5,int y5)
{
	if((x5>=x1) and (x5<=x2) and (y5<=y1) and (y5>=y2))  return 1;
	else return 0; 
}
bool ontOnAnother(int x1,int y1,int x2,int y2,int x5,int y5,int x6,int y6)
{
	pair<int,int> p1[10];
	pair<int,int> p2[10];
	
	int x3 = x1;
	int y3 = y2;	
	int x4 = x2;
	int y4 = y1;


	//x2, y2;
	int x7 = x5;
	int y7 = y6;
	int x8 = x6;
	int y8 = y5;
	int same = 0;
	
	if(oneInAnother(x5,y5,x6,y6,x1,x1)) return 1;
	if(oneInAnother(x5,y5,x6,y6,x2,x2)) return 1;
	if(oneInAnother(x5,y5,x6,y6,x2,x2)) return 1;
	if(oneInAnother(x5,y5,x6,y6,x2,x2)) return 1;

	if(oneInAnother(x6,y6,x5,y5,x1,x1)) return 1;
	if(oneInAnother(x6,y6,x5,y5,x2,x2)) return 1;
	if(oneInAnother(x6,y6,x5,y5,x2,x2)) return 1;
	if(oneInAnother(x6,y6,x5,y5,x2,x2)) return 1;

	if(oneInAnother(x7,y7,x8,y8,x1,x1)) return 1;
	if(oneInAnother(x7,y7,x8,y8,x2,x2)) return 1;
	if(oneInAnother(x7,y7,x8,y8,x2,x2)) return 1;
	if(oneInAnother(x7,y7,x8,y8,x2,x2)) return 1;

	if(oneInAnother(x8,y8,x7,y7,x1,x1)) return 1;
	if(oneInAnother(x8,y8,x7,y7,x2,x2)) return 1;
	if(oneInAnother(x8,y8,x7,y7,x2,x2)) return 1;
	if(oneInAnother(x8,y8,x7,y7,x2,x2)) return 1;



	if(oneInAnother(x1,y1,x2,y2,x5,x5)) return 1;
	if(oneInAnother(x1,y1,x2,y2,x6,x6)) return 1;
	if(oneInAnother(x1,y1,x2,y2,x7,x7)) return 1;
	if(oneInAnother(x1,y1,x2,y2,x8,x8)) return 1;

	if(oneInAnother(x2,y2,x1,y1,x5,x5)) return 1;
	if(oneInAnother(x2,y2,x1,y1,x6,x6)) return 1;
	if(oneInAnother(x2,y2,x1,y1,x7,x7)) return 1;
	if(oneInAnother(x2,y2,x1,y1,x8,x8)) return 1;

	if(oneInAnother(x3,y3,x4,y4,x5,x5)) return 1;
	if(oneInAnother(x3,y3,x4,y4,x6,x6)) return 1;
	if(oneInAnother(x3,y3,x4,y4,x7,x7)) return 1;
	if(oneInAnother(x3,y3,x4,y4,x8,x8)) return 1;

	if(oneInAnother(x4,y4,x3,y3,x5,x5)) return 1;
	if(oneInAnother(x4,y4,x3,y3,x6,x6)) return 1;
	if(oneInAnother(x4,y4,x3,y3,x7,x7)) return 1;
	if(oneInAnother(x4,y4,x3,y3,x8,x8)) return 1;
	return 0;

   
}
int t;

bool state;
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		 cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		 if(intLine(x1,y1,x2,y2,x3,y3,x4,y4))          cout<<2;
		 else if(oneIntPoint(x1,y1,x2,y2,x3,y3,x4,y4)) cout<<1;
		 else if(ontOnAnother(x1,y1,x2,y2,x3,y3,x4,y4))cout<<3;
		 else cout<<0;
		 
	}
	return 0;
}