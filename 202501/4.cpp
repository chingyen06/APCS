#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, n, k, med;
	
	cin >> n >> k;
	
	long long int x[n], cost[n-k+1], minv = 9e18;
	long long int left_total = 0, right_total = 0, add, minus;
	
	for (i=0;i<n;i++)
		cin >> x[i];
	
	sort(x, x + n);  //x 陣列排序 
	
	//=== 第一組 0 ~ k - 1 === 
	//偶數的中位數這個跟中間兩個取平均的方法答案一樣 
	med = (k-1) / 2;  //取中位數 
	//得到 cost[0]，是 0 ~ k - 1 的成本總和 
	for (i=0;i<med;i++)  //中位數左邊的成本總和 
		left_total += x[med] - x[i];
	for (i=med+1;i<k;i++)  //中位數右邊的成本總和 
		right_total += x[i] - x[med]; 
	//cost[0]，0 ~ k - 1 的成本總和  
	cost[0] = left_total + right_total; 
		
    //=== 其餘組 === 
	for (i=1;i<=n-k;i++) {
		med++;  //中位數右移
		left_total -= x[med-1] - x[i-1];  //刪除最左邊的成本
 		right_total += x[i+k-1] - x[med];  //新增最右邊的成本 
		
		//中位數左邊的成本總和更新
		add = x[med] - x[med-1];  //需要補上的成本 (原中位數與新中位數的差) 
		left_total += add * ((k-1)/2);
		//中位數右邊的成本總和更新
		minus = x[med] - x[med-1];  //需要減去的成本 (原中位數與新中位數的差，負的) 
		right_total -= minus * (k - 1 - (k-1)/2);
		
		cost[i] = left_total + right_total;  //cost[i]，i ~ i + k - 1 的成本總和  
	}
		
	//求最小組合
    long long int best_left[n-k+1], best_right[n-k+1];
    
    best_left[0] = cost[0];  //最左邊成本 
    for (i=1;i<=n-k;i++)
        best_left[i] = min(best_left[i-1], cost[i]);  //求最左邊到 i 的最小成本  
    
    best_right[n-k] = cost[n-k];  //最右邊成本 
    for (i=n-k-1;i>=0;i--)
        best_right[i] = min(best_right[i+1], cost[i]);  //求 i 到最右邊的最小成本  
    
    for (i=0;i<=n-2*k;i++)
        minv = min(minv, best_left[i] + best_right[i+k]);  //求整體成本 
    
    cout << minv;

    return 0;
}
