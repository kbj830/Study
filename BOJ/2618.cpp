#include <iostream>
#include <vector>
#include <math.h>

#define endl '\n'

using namespace std;

int n, w, dp[1001][1001], cache[1001][1001];
vector<pair<int, int>> v;

int dist(int a, int b) {
	return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}

int getSum(int a, int b) {
	if (a == w + 1 || b == w + 1)
		return 0;
	
	if (dp[a][b] != 0)
		return dp[a][b];
	
	int nextCase = max(a, b) + 1;
	
	int g = getSum(a, nextCase) + dist(b, nextCase);
	int h = getSum(nextCase, b) + dist(a, nextCase);
	
	if (g < h) {
		cache[a][b] = 2;
	}
	else {
		cache[a][b] = 1;
	}
	
	dp[a][b] = min(g, h);
	
	return dp[a][b];
}

void solve() {
	cin >> n >> w;
	
	v.push_back({ 1, 1 });
	v.push_back({ n, n });
	
	for (int i = 0; i < w; i++) {
		int a, b;
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	cout << getSum(0, 1) << endl;

	int a = 0, b = 1;
	
	for (int i = 2; i < w + 2; i++) {
		int nextCase = max(a, b) + 1;
		if (cache[a][b] == 1) {
			cout << 1 << endl;
			a = i;
		}
		else {
			cout << 2 << endl;
			b = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
