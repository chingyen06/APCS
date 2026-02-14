#include <iostream>
using namespace std;

int n;
int s[8], d[8], t[8], used[8]={};

int dfs(int now, int relax, int count) 
{
	int i, check = 1;
	
	if (count == n)  // 任務已經都做完了 
		return 1;  // 直接回傳 1 
	
	for (i=0;i<n;i++) {
		if (max(s[i], now) + t[i] <= d[i] && used[i] == 0) {  // 若截止之前可以做完 & 沒做過 
			used[i] = 1;  // 做這個任務  
			
			if (dfs(max(s[i], now)+t[i]+relax, relax, count+1) == 1)  // DFS 做完這個任務後是否能完成的可能 
				return 1;  // 已經做完了，直接回傳 1 
				
			// 這個組合不行，換其他組合 
			used[i] = 0;  // 不做這個任務 
		}
	}
	
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i;
	int left = 0, right = 1000, mid, ans = 0;
	
	cin >> n;
	
	for (i=0;i<n;i++) {
		cin >> s[i] >> d[i] >> t[i];
	}
	
	while (left <= right) {
		mid = (left + right) / 2;
		
		// cout << mid << " | " << left << " " << right << endl;
		
		if (dfs(0, mid, 0) == 1) {  // 這個間隔時間可以 
			// cout << "Yes: " << mid << endl;
		
			left = mid + 1;
			ans = mid;
		} 
		else {  // 這個間隔時間不行 
			// cout << "No: " << mid << endl;
		
			right = mid - 1;
		}
		
		for (i=0;i<n;i++) {  //  重置使用紀錄 
			used[i] = 0;
		} 
	}
	
	cout << ans;

	return 0;
}
