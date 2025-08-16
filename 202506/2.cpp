#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, m, n, k, max, total = 0, word;
	int distance, top[30]={}, point[26];
	string s[30];
	
	cin >> m >> n >> k;
	
	for (i=0;i<m;i++)
		cin >> s[i];
		
	while (k > 0) {
		max = 0;
		
		for (i=0;i<m;i++) {
			cin >> distance;  //轉動距離 
			
			//移動字串開始的位置  (top[j] 都是存字串開始的位置，由左而右) 
			//用減是因為右轉反而最上面的字元索引在原本的字元的前面 
			//加 (n * 100) 是為了 top - distance 是負的可以正確到對的位置(題目說最多距離+-100) 
			top[i] = (top[i] - distance + n * 100) % n;
		}
		
		for (i=0;i<n;i++) {
			memset(point, 0, sizeof(point));  //point 清零，用於紀錄字元出現次數 
			max = 0;  //紀錄這格出現次數最多的字元的次數
			
			for (j=0;j<m;j++) {
				//出現的字元的字典編號
				word = s[j][(top[j]+i)%n] - 'a';  //(top[j]+i)%n 可以得到第 i 格的字元位置 
				
				point[word]++;  //出現的字元次數加 1
				
				if (point[word] > max)  //比之前的字元出現的次數多 
					max = point[word];  //更新為這格最佳 
			} 
			
			total += max;  //出現次數最多的字元的次數加到總和 
		}
		
		k--;
	}
	
	cout << total;

	return 0;
}
