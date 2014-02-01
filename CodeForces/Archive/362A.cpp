#include <iostream>
#include <set>
#include <string.h>
#include <string>
#define MAXN 10000
using namespace std;
set<int> d1[10][10], d2[10][10];
set<int>::iterator it;
bool u1[10][10], u2[10][10];
char a[10][10];
bool comp(int x, int y)
{
	if(x>=1 && x<=8 && y>=1 && y<=8) return true;
	else return false;
}
void srch1(int x, int y, int cost)
{
	cerr<<"1 half-horse = "<<x<<"-"<<y<<"="<<cost<<endl;
	//d1[x][y]=min(d1[x][y],cost);
	d1[x][y].insert(cost);
	u1[x][y] = 1;
	if(comp(x+2,y+2)) if(!u1[x+2][y+2]) srch1(x+2,y+2,cost+1);	
	if(comp(x+2,y-2)) if(!u1[x+2][y-2]) srch1(x+2,y-2,cost+1);	
	if(comp(x-2,y+2)) if(!u1[x-2][y+2]) srch1(x-2,y+2,cost+1);	
	if(comp(x-2,y-2)) if(!u1[x-2][y-2]) srch1(x-2,y-2,cost+1);	
}
void srch2(int x, int y, int cost)
{                  
	//d2[x][y]=min(d2[x][y],cost);
	cerr<<"2 half-horse = "<<x<<"-"<<y<<"="<<cost<<endl;
	d2[x][y].insert(cost);
	u2[x][y] = 1;                            
	if(comp(x+2,y+2)) if(!u2[x+2][y+2]) srch2(x+2,y+2,cost+1);	
	if(comp(x+2,y-2)) if(!u2[x+2][y-2]) srch2(x+2,y-2,cost+1);	
	if(comp(x-2,y+2)) if(!u2[x-2][y+2]) srch2(x-2,y+2,cost+1);	
	if(comp(x-2,y-2)) if(!u2[x-2][y-2]) srch2(x-2,y-2,cost+1);	
}           
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	bool first = 0;
	for(int k=1;k<=t;k++)
	{
		for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) d1[i][j].clear(),d2[i][j].clear();
		memset(u1,0,sizeof(u1));
		memset(u2,0,sizeof(u2));
		first = 0;
		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='K' && !first)
				{
					first = 1;
					srch1(i,j,0);
				}
				else if(a[i][j]=='K' && first)
				{
					srch2(i,j,0);
				}
			}
		}
		bool yes = 0;
		/*for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				cout<<d1[i][j]<<" ";
			}          
			cout<<endl;
		}
		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				cout<<d2[i][j]<<" ";
			}          
			cout<<endl;
		}*/


		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				if(u1[i][j] && u2[i][j] && a[i][j]!='#') 
				{           
					for(it=d1[i][j].begin();it!=d1[i][j].end();++it)
					{
						cerr<<*it<<endl;
						if(d2[i][j].find(*it)!=d2[i][j].end())
							yes = 1;
					}
				}
			}          
		}
		if(yes) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}