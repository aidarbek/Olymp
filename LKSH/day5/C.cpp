#include <iostream>
using namespace std;
int n;
int d[1000][1000];	
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=9;i++)
	{
		d[1][i] = 1;
	}
	d[1][0] = 0;                         
    for(int i=2;i<=n;i++)
    {
    	d[i][0] = d[i-1][0] + d[i-1][1];
    	d[i][9] = d[i-1][9] + d[i-1][8];
    	for(int j=1;j<=8;j++)
    	{
    		d[i][j] = d[i-1][j]+d[i-1][j-1]+d[i-1][j+1];
    	}
    }
    int sum = 0;
    for(int i=0;i<=9;i++)
    {
    	 sum+= d[n][i];
    }
    cout<<sum<<endl;
	return 0;
}
