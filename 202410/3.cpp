#include <bits/stdc++.h>
using namespace std;

int start_x, start_y;
int m, n, q;
int a[600][600], visited[600][600];
int moves[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  //上下左右 

struct boom_range {
	int y, x, t;  //y, x儲存該位置的座標  | t儲存剩餘能量 
};

int bfs(int start_range)
{
	int i, affected = 1, total = 0;  //affected 紀錄受波及格子數
	queue<boom_range> spread;  //儲存會波及的地方 
	
	memset(visited, -1, sizeof(visited));
	//將 visited 儲存的受波及後該格剩餘的能量，避免後面 power 跟 visited 都是 0會出現例外 
	
	spread.push({start_y, start_x, start_range});
	
	while (spread.size() > 0) {
		total++;
		boom_range point = spread.front();
		spread.pop();
		
		int power = point.t;
		
		if (power > 0) {
			for (i=0;i<4;i++) {
				int next_y, next_x, next_power;
				next_y = point.y + moves[i][0];
				next_x = point.x + moves[i][1];
				
				next_power = power - 1;
				
				if (next_power > visited[next_y][next_x] - 100 && a[next_y][next_x] >= 0) {  
				//若新給予的能量比其他炸彈給予的能量大且不是石頭、邊界或初始炸彈 
					if (visited[next_y][next_x] == -1) {  //若是先前尚未受波及
						affected++;
						
						if (a[next_y][next_x] > next_power)  //若是尚未引發的炸彈且爆炸能量 > 剩餘能量 
							next_power = a[next_y][next_x];
					}
						
					spread.push({next_y, next_x, next_power});
					visited[next_y][next_x] = next_power + 100;  //儲存該位置剩餘能量 + 100 (避免 point.t 恰好是 0) 
				}
			}
		} 
	}
	
	if (affected >= q)
		return 1;
	
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	
	cin >> m >> n >> q;
	
	memset(a, -1, sizeof(a));  //預設全部都是石頭 (避免之後須考慮邊界問題) 
	
	for (i=1;i<=m;i++) {
		for (j=1;j<=n;j++) {
			cin >> a[i][j];
			
			if (a[i][j] == -2) {
				start_y = i;
				start_x = j;
			}
		}
	}
	
	int l = 0, r = n * m;
	
	while (l <= r) {
		int mid = (l + r) / 2;
		
		if (bfs(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	cout << l;

	return 0;
}
