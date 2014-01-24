#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int   a[100][100];
int buf[100][100];
int ans[100][100];
int   b[1000];
int   n;
int   x,y;

int check()
{
	int res = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		 	if(buf[i][j]==1)
		 	{
		 		res+=a[i][j];
		 		for(int k=i+1;k<n;k++)
		 		{
		 			if(buf[k][j]==1) 
		 			{
		 				res = -1;
		 				break;
		 			}
		 		}
		 		for(int k=i-1;k>=0;k--)
		 		{
		 			if(buf[k][j]==1) 
		 			{
		 				res = -1;
		 				break;
		 			}
		 		}
		 		for(int k=j-1;k>=0;k--)
		 		{
		 			if(buf[i][k]==1) 
		 			{
		 				res = -1;
		 				break;
		 			}
		 		}
		 		for(int k=j+1;k<n;k++)
		 		{
		 			if(buf[i][k]==1) 
		 			{
		 				res = -1;
		 				break;
		 			}
		 		}
		 		for(int k=1;k<n;k++)
		 		{
		 			if(i+k>=n || j+k>=n) break;
		 			else
		 			{
		 				if(buf[i+k][j+k]==1) 
		 				{
		 					res = -1;
		 					break;
		 				}	
		 			}
		 		}

		 		for(int k=1;k<n;k++)
		 		{
		 			if(i-k<0 || j-k<0) break;
		 			else
		 			{
		 				if(buf[i-k][j-k]==1) 
		 				{
		 					res = -1;
		 					break;
		 				}	
		 			}
		 		}

		 		for(int k=1;k<n;k++)
		 		{
		 			if(i+k>=n || j-k<0) break;
		 			else
		 			{
		 				if(buf[i+k][j-k]==1) 
		 				{
		 					res = -1;
		 					break;
		 				}	
		 			}
		 		}
		 		for(int k=1;k<n;k++)
		 		{
		 			if(i-k<0 || j+k>=n) break;
		 			else
		 			{
		 				if(buf[i-k][j+k]==1) 
		 				{
		 					res = -1;
		 					break;
		 				}	
		 			}
		 		}



		 		if(res==-1) break;
		 	}
		}
		if(res==-1) break;
	}
	return res;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int m = n*n;
	int t = 0, t1 = 0;
	int mx = -9999;
	int chk;
	while(b[m]==0)
	{
		t = 0;
		for(int i=0;i<m;i++)
		{
			if(b[i]==1)
			{
				t++;	
			}

		}
		if(t==n)
		{
			memset(buf,0,sizeof(buf));      
			for(int i=0;i<m;i++)
			{
				if(b[i]==1)
				{
					x = i%n;
					y = i/n;	
					buf[x][y] = 1;
				}				
			}
			chk = check();
			if(chk>-1)
			{
				cerr<<chk<<endl;
				t1 = 0;
				if(chk > mx)
				{
					mx = chk;
					for(int i=0;i<n;i++)
					{
						for(int j=0;j<n;j++)
						{
							ans[i][j] = buf[i][j];	
						}
					}

				}
			}
		}
		b[0]++;
		for(int i=0;i<m;i++)
		{
			if(b[i]>1)
			{
				b[i] = 0;
				b[i+1]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}