#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define  MAXN 100003
using namespace std;

int n;
int x[MAXN],y[MAXN],z[MAXN],val[MAXN];
int x1,y1,z1,x2,y2,z2;
int q;
int v;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin>>n;
	scanf("%d",&n);
	int c = 0;
	int ans;
	while(true)
	{
		scanf("%d",&q);
		//cin>>q;
		if(q==3)
		 break;
		if(q==1)
		{
		    //cin>>x1>>y1>>z1>>v; 	
			scanf("%d %d %d %d", &x1, &y1, &z1, &v);			
			//printf("%d", x1,y1,z1,v);
			x[c]  = x1;
			y[c]  = y1;
			z[c]  = z1;
			val[c]=v;
			++c;
		}
		else
		{
			//cin>>x1>>y1>>z1>>x2>>y2>>z2;

			scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			//cout<<x1<<endl;
			ans=0;
			for(int i=0;i<c;++i)
			{
				if(x1<=x[i] && x2>=x[i] && y1<=y[i] && y[i]<=y2 && z1<=z[i] && z[i]<=z2)
				{                   
					ans+=val[i];
				}
			}
			printf("%d\n", ans);
			//cout<<ans<<endl;
		}
	}
	return 0;
} 