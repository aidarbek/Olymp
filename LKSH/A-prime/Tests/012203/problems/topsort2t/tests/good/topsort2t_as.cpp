#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

int n, m, bad;
vector<int> adj[100100];
int topol[100100], tnum;
char used[100100], z[100100];

void dfs(int a){
  z[a] = used[a] = 1;
  int i, k;
  for (i=0; i<(int)adj[a].size(); i++){
    k = adj[a][i];
    if (z[k]) bad = 1;
    else if (!used[k]) dfs(k);
  }
  z[a] = 0;
  topol[++tnum] = a;
}


int main(){
  freopen("topsort2t.in", "r", stdin);
  freopen("topsort2t.out", "w", stdout);
  int i, a, b;
  scanf("%d%d", &n, &m);
  assert(1<=n && n<=100000 && 0<=m && m<=100000);
  for (i=1; i<=m; i++){
    scanf("%d%d", &a, &b);
    assert(1<=a && a<=n && 1<=b && b<=n);
    adj[a].push_back(b);
  }
  for (i=1; i<=n; i++){
    if (!used[i]){
      dfs(i);
    }
  }
  if (bad){
    printf("-1\n");
    return 0;
  }
  for (i=n; i>=1; i--){
    printf("%d ", topol[i]);
  }
  printf("\n");
  return 0;
}