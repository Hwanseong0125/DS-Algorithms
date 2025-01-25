#include <iostream>
#include <Queue>
#define X first
#define Y second

using namespace std;
int board[502][502] = {0,};
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);

	cin >> n >> m;

	queue<pair<int, int>> Q;
	vis[0][0] = true;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}