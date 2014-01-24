#include <iostream>
using namespace std;
int  f[100] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 39916800, 479001600};
int  u[100];
int main()
{
	freopen("C.in", "r",stdin);
	freopen("C.out","w",stdout);
	int n;
	int ans = 0;
	int c = 0;
	int sum = 0;
	int count1 = 0;
	bool checker = 0;
	cin>>n;
	while(u[13]==0)
	{
		sum = 0;
		count1 = 0;
		for(int i=0;i<=12;i++) 
		{
			if(u[i])
			{
				sum+=f[i];
				count1++;
			}
		}
		if(sum==n)
		{
			checker = 1;
			break;
		}           
		u[0]++;
		for(int i=0;i<=12;i++)
		{
			if(u[i]>1)
			{
				u[i] = 0;
				u[i+1]++;
			}
		}
	}	
	int count2 = 0;
	if(checker)
	{
		for(int i=0;i<=12;i++)
		{
			if(u[i])
			{
				count2++;
			  	cout<<i<<"!";
			  	if(count1!=count2) cout<<"+";
			}
		}
	}
	else
	{
		cout<<"Impossible";
	}
	return 0;
}
