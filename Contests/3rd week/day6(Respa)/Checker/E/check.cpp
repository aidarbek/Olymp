#include <cstdio>
#include <set>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

const int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int MAXN = 500;

int a[MAXN][MAXN];
int r[MAXN][MAXN];

void wa(const char *s) {
	printf("%s\n", s);
	exit(1);
}

void je(const char *s) {
	printf("%s\n", s);
	exit(2);
}

void ok(const char *s) {
	printf("%s\n", s);
	exit(0);
}

int main(int argc, char *argv[]) {
	assert(argc == 4);
	
	FILE* fin = fopen(argv[1], "r");
	FILE* fout = fopen(argv[2], "r");
	FILE* fans = fopen(argv[3], "r");
	
	int n, m, k;
	fscanf(fin, "%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fscanf(fin, "%d", &a[i][j]);
		}
	}
	set<pair<int, int> > start, finish;
	for (int i = 0; i < k; ++i) {
		int x, y;
		fscanf(fin, "%d %d", &x, &y);
		--x; --y;
		start.insert(make_pair(x, y));
	}
	for (int i = 0; i < k; ++i) {
		int x, y;
		fscanf(fin, "%d %d", &x, &y);
		--x; --y;
		finish.insert(make_pair(x, y));
	}
	fclose(fin);
	
	int o_result, a_result, t;
	if ((t = fscanf(fout, "%d", &o_result)) != fscanf(fans, "%d", &a_result)) {
		wa("Wrong format");
	}
	if (t == 0) {
		ok("OK");
	}
	if (o_result > a_result) {
		wa("Wrong cost");
	}
	
	set<int> s;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (fscanf(fout, "%d", &r[i][j]) != 1) {
				wa("Wrong format");
			}
			if ((r[i][j] < 0) || (r[i][j] > k)) {
				wa("Wrong format");
			}
			s.insert(r[i][j]);
		}
	}
	if (s.find(0) != s.end()) s.erase(s.find(0));
	if ((int)s.size() != k) {
		wa("Wrong number of paths");
	}
	
	int result = 0;
	
	for (set<pair<int, int> >::iterator it = start.begin(); it != start.end(); ++it) {
		if (s.find(r[it->first][it->second]) == s.end()) {
			wa("Inconsistent answer 1");
		}
		int x = r[it->first][it->second];
		s.erase(s.find(x));
		int i = it->first, j = it->second;
		while (true) {
			r[i][j] = 0;
			result += a[i][j];
			bool f = false;
			for (int t = 0; t < 4; ++t) {
				int ii = i + dd[t][0], jj = j + dd[t][1];
				if ((ii >= 0) && (jj >= 0) && (ii < n) && (jj < m) && (r[ii][jj] == x)) {
					f = true;
					i = ii, j = jj;
					break;
				}
			}
			if (!f) break;
		}
		if (finish.find(make_pair(i, j)) == finish.end()) {
			wa("Inconsistent answer 2");
		}
		finish.erase(finish.find(make_pair(i, j)));
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (r[i][j] != 0) {
				wa("Inconsistent answer 3");
			}
		}
	}
	
	if (result != o_result) {
		wa("Path costs isn't equals to the output");
	}
	if (s.size() || finish.size()) {
		wa("Inconsistent answer 4");
	}
	
	if (result < a_result) {
		je("OOPS: Jury error!");
	}

	ok("OK");
	return 0;
}
