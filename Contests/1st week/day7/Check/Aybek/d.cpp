#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>

#define S second
#define F first
#define ll long long
#define eps 1e-9
#define mkp make_pair
#define pb push_back
#define ull unsigned long long
#define inc(i,x,n) for(int i=(int)x;i<=(int)n;i++)
#define dec(i,n,x) for(int i=(int)n;i>=(int)x;i--)
#define sz size

using namespace std;

const int inf=1000000000; // default 1e9

double Time()
{
  return double(clock())/double(CLOCKS_PER_SEC);
}

const int N=71;

int q[8]={1,1,1,0,0,-1,-1,-1};
int w[8]={-1,0,1,-1,1,-1,0,1};
int n;
char ch[N][N];
int a[N][N],si,sj;
pair<int,pair<int,int> > d[N][N];
queue<int> iq,jq;

bool check(int i,int j){
	return (i>=1&&i<=n&&j>=1&&j<=n);
}

int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	inc(i,1,n){
		inc(j,1,n){
			cin>>ch[i][j];
			if(ch[i][j]=='P'){
				si=i;
				sj=j;
			}
		}
	}
	inc(i,1,n){
		inc(j,1,n){
			cin>>a[i][j];
			d[i][j]=mkp(0,mkp(0,0));
		}
	}
	d[si][sj]=mkp(0,mkp(a[si][sj],a[si][sj]));
	iq.push(si);
	jq.push(sj);
	while(!iq.empty()){
		int i=iq.front(),j=jq.front();
		pair<int,pair<int,int> > p=d[i][j];
//		cout<<i<<" "<<j<<" "<<p.F<<" "<<p.S.F<<" "<<p.S.S<<endl;
		iq.pop();jq.pop();
		inc(z,0,7){
			if(check(i+q[z],j+w[z])){
				pair<int,pair<int,int> > t=d[i+q[z]][j+w[z]];
			   if(t.F==0&&t.S.F==0&&t.S.S==0){
					int up=min(a[i+q[z]][j+w[z]],p.S.F);
					int down=max(a[i+q[z]][j+w[z]],p.S.S);
					iq.push(i+q[z]);
					jq.push(j+w[z]);
					d[i+q[z]][j+w[z]]=mkp(abs(up-down),mkp(up,down));
				}
				else{
					int up=min(a[i+q[z]][j+w[z]],p.S.F);
					int down=max(a[i+q[z]][j+w[z]],p.S.S);
					if(t.F>abs(up-down)){
						iq.push(i+q[z]);
						jq.push(j+w[z]);
						d[i+q[z]][j+w[z]]=mkp(abs(up-down),mkp(up,down));
					}
				}
			}
		}
	}
	int up=inf,down=-inf;
	inc(i,1,n){
		inc(j,1,n){
//			cout<<d[i][j].F<<" "; 
			if(ch[i][j]=='K'){
				up=min(up,d[i][j].S.F);
				down=max(down,d[i][j].S.S);
			}
		}
//		cout<<endl;
	}
	cout<<down-up;
return 0;
}
