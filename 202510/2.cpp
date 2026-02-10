#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j;
	int R, C;
	int s[4]={}, Max;
	
	cin >> R >> C;
	
	int A[R][C], B[R][C];
	
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> A[i][j];
		}
	}
	
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> B[i][j];
		}
	}
	
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			if (A[i][j] == B[i][j]) {  // 旋轉 0 度 
				s[0]++;
			}
			if (A[i][j] == B[R-i-1][C-j-1]) {  // 旋轉 180 度 
				s[2]++;
			}
			
			if (R == C) {  // 必須 R == C (正方形)，旋轉 90 度與 270 度才能比 
				if (A[i][j] == B[j][R-i-1]) {  // 旋轉 90 度 
					s[1]++;
				}
				if (A[i][j] == B[R-j-1][i]) {  // 旋轉 270 度 
					s[3]++;
				}
			}
		}
	}
	
	Max = s[0];  // 存 S 的最大值 
	
	for (i=0;i<4;i++) {  // 計算 S 的最大值 
		if (s[i] > Max) {
			Max = s[i];
		} 
		// cout << s[i] << " ";
	}
	
	cout << (Max * 100) / (R * C)  << "%";

	return 0;
}
