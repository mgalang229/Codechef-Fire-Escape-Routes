#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<int> mark;
int cnt;

void dfs(int u) {
	// increment 'cnt'
	++cnt;
	// visit vertex 'u'
	mark[u] = 1;
	for (vector<int>::iterator v = a[u].begin(); v != a[u].end(); v++) {
		if (!mark[*v]) {
			// if not yet visited, then run dfs again
			dfs(*v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		// re-declare 'a' with size of 'n'
		a = vector<vector<int>>(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			// store 'v' to 'u'
			a[u].push_back(v);
			// store 'u' to 'v' (this is needed because transitive property ignored)
			a[v].push_back(u);
		}
		int res = 0;
		int ways = 1;
		// set the values of 'mark' to 0
		mark = vector<int>(n, 0);
		for (int u = 0; u < n; u++) {
			if (mark[u]) {
				// if vertex 'u' is visited already, then continue the loop
				continue;
			}
			// otherwise, increment 'res' (routes)
			++res;
			// reset 'cnt' to 0
			cnt = 0;
			// run dfs on vertex 'u' to visit the adjacent nodes
			dfs(u);
			// multiply 'ways' to 'cnt' and take the modulus of 1e9 + 7 because
			// the answer might be too large
			ways = (long long) cnt * ways % 1000000007;
		}
		cout << res << " " << ways << '\n';
	}
	return 0;
}
