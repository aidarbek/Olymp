/*
Решение кого-то из школьников, которое дает PE на тесте 4
В чем ошибка, я не разбирался
*/
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector < vector <int> > G;
vector <int> used;
vector <int> T;
bool cycle;

void dfs(int v, int c) {
    used[v] = c;
    for(int i=0; i<G[v].size(); ++i) {
        if(used[G[v][i]] == c) cycle = true;
        else if(used[G[v][i]] == 0) dfs(G[v][i], c);
    }
    T.push_back(v);
}

int main() {
    freopen("topsort2t.in", "r", stdin);
    freopen("topsort2t.out", "w", stdout);
    
    int a, b, c, m, n;
    cin >> n >> m;
    G.resize(n);
    used.resize(n);
    used.assign(n, 0);
    for(int i=0; i<m; ++i) {
        scanf("%d%d", &a, &b);
        G[a-1].push_back(b-1);
    }
    c = 1;
    cycle = false;
    for(int i=0; i<n; ++i) {
        if(used[i] == 0) dfs(i, c);
        c++;
    }
    if(cycle) cout << -1;
    else {
        for(int i=T.size()-1; i>=0; --i)
            printf("%d ", T[i]+1);
    }
    
    return 0;
}
