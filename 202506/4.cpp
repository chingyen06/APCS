#include <bits/stdc++.h>
using namespace std;

int visited[500];

int dfs(int n, int start, int d[500][500], int distance)
{
	int i;
	
	for (i=0;i<n;i++) {
		//兩個物品距離小於規定的 distance & 還沒被分過組 
		if (d[start][i] < distance && visited[i] == 0) {
			visited[i] = 1;  //設為已分過組 
			dfs(n, i, d, distance);  //繼續找有沒有還可以分為一組的 
		}
	}
}

int allow(int n, int k, int d[500][500], int distance)
{
	int i, team = 0;

	memset(visited, 0, sizeof(visited));
	
	for (i=0;i<n;i++) {
		if (visited[i] == 0) {  //還沒被分過組 
			visited[i] = 1;  //設為已分過組 
			dfs(n, i, d, distance);   //找有沒有還可以分為一組的 
			team++;  //組數 + 1 
		}
	}
	
	if (team >= k)  //分為 k 組以上 
		return 1;
		
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, n, k;
	int left = 1e9, right = 0, mid, ans;
	int d[500][500];
	
	cin >> n >> k;
	
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			cin >> d[i][j];
			
			if (d[i][j] < left)  //找最小距離 
				left = d[i][j];
			if (d[i][j] > right)  //找最大距離 
				right = d[i][j];
		}
	}
	
	while (left <= right) {
		mid = (left + right) / 2;
		
		if (allow(n, k, d, mid) == 1) {
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	
	cout << ans;

	return 0;
}
