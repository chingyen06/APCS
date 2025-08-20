#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, n, t;
	long long int total = 0, sandbag;
	stack<long long int> stk;
	
	cin >> n >> t;
		
	for (i=0;i<n;i++) {
		cin >> sandbag;  //輸入關卡沙包數 
		
		//堆疊內還有未完成關卡 & 前一個未完成關卡的沙包比較少
		while (stk.size() > 0 && stk.top() <= sandbag) {
			total += stk.top();  //總分增加前一個未完成關卡的沙包
			sandbag += stk.top();  //此關卡沙包加上前一個未完成關卡的沙包 
			stk.pop();  //前一個未完成關卡移出堆疊
		}
		
		if (sandbag <= t)  //此關卡是否搬得動 
			stk.push(sandbag);  //搬得動的話就將此關卡加入堆疊 
	}
	
	while (stk.size() > 0) {  //堆疊內還有搬得動的未完成關卡
		total += stk.top();  //總分增加關卡的沙包數 
		
		stk.pop();
	} 
	
	cout << total;

	return 0;
}
