#include <bits/stdc++.h>
using namespace std;

struct Item {
	char w;
	int s;
};

struct Content {
	int n;
	Item st[12];  // 由後往前可以當 stack 用 
	int start = 0;
};

Content content[6];

// 存在一個向量 {?, ?, ?, ?, ?, ?} 的狀態下 (? 存剩餘的物品數)
// 繼續 DFS 的最大分數 
map<vector<int>, int> mapp;

int dfs(int k)
{	
	int i, j, temp, Max = 0;
	int num1, num2;
	
	// 從 30 分到 100 分
	vector<int> state;  // 目前狀態 
	for(i=0;i<k;i++) {
		state.push_back(content[i].start);
	}
	
	if (mapp.count(state))  // 已經試過了 
		return mapp[state];  // 直接回傳 
	// 
	
	for (i=0;i<k;i++) {
		for (j=i+1;j<k;j++) {
			if (i == j)  // 同一個略過
				continue; 
			
			num1 = content[i].start;  // 這一回合堆疊一頂部的物品的索引 
			num2 = content[j].start;  // 這一回合堆疊二頂部的物品的索引
			
			if (num1 >= content[i].n || num2 >= content[j].n)  // 有任何地方取完了 
				continue;
			 
			// 頂部的物品的字母相同
			if (content[i].st[num1].w == content[j].st[num2].w) {
				// 暫時的分數 = 這一回合獲得的分數(2個堆疊) + dfs其他選項的最大分數 
				temp = content[i].st[num1].s + content[j].st[num2].s;
				content[i].start++;  // 用掉之後 
				content[j].start++;  // 用掉之後
				
				temp += dfs(k);  // DFS 使用掉這個 i、j 後最大的可能 
				
				if (temp > Max)
					Max = temp;
				
				content[i].start--;  // 還回去，不取 i 的其他可能 
				content[j].start--;  // 還回去，不取 j 的其他可能
			}
		}
	}
	
	// 從 30 分到 100 分
	mapp[state] = Max;  // 存目前狀態下，繼續 DFS 的最大分數，表示之後不必再查 
	//
	
	return Max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, k;
	
	cin >> k;
	
	for (i=0;i<k;i++) {
		cin >> content[i].n;  // n_i
		
		for (j=0;j<content[i].n;j++) {
			cin >> content[i].st[j].w >> content[i].st[j].s;
		}
	}
	
	cout << dfs(k);

	return 0;
}
