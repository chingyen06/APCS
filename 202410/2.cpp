#include <bits/stdc++.h>
using namespace std;

int jewel[102][102];
int moves[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int end(int r, int c)
{
	int i, ok = 4;
		
	if (jewel[r][c] == 0)  //當前位置無寶石 
		return 1;
			
	for (i=0;i<4;i++)  //判斷四面是否都是牆壁
		if (jewel[r+moves[i][0]][c+moves[i][1]] == -1)
			ok--;
				
	if (ok == 0)  //四面都是牆壁 
		return 1;
		
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j;
	int m, n, k, r, c;
	int dir = 0, score = 0, t = 0;
	
	cin >> m >> n >> k >> r >> c;
	
	r++;
	c++;
	
	memset(jewel, -1, sizeof(jewel));  //預設為全部都是牆壁 
	
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			cin >> jewel[i][j];
			
	while (true) {
		if (end(r, c))  //符合結束條件
			break;
		
		score += jewel[r][c];
		t++;
		jewel[r][c]--;
		
		if (score % k == 0)  //score是k的倍數 
			dir = (dir + 1) % 4; 
		
		int temp_r, temp_c;
		
		while (true) {
			temp_r = r + moves[dir][0];
			temp_c = c + moves[dir][1];
			
			if (jewel[temp_r][temp_c] == -1)  //面向牆壁或邊界外
				dir = (dir + 1) % 4; 
			else
				break;
		}
		
		r = temp_r;
		c = temp_c;
	}
	
	cout << t;

	return 0;
}
