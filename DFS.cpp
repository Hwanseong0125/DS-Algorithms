#include <iostream>
#include <stack>
#define X first
#define Y second

using namespace std;
int board[502][502] = { 0, };
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);

	cin >> n >> m;

	stack<pair<int, int>> S;
	vis[0][0] = true;
	S.push({ 0,0 });

	while (!S.empty()) {
		auto cur = S.top(); S.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			S.push({ nx,ny });
		}
	}
}