#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, k, l;
	int R, C, D, K, M, r, c;
	int a, b, s, d;
	int t, Max, Min;
	
	cin >> R >> C >> D >> K;
	
	int mapp[C][R]={}, dinosaur[C][R]={};
	
	for (i=0;i<C;i++) {  // 初始高度設為 D 
		for (j=0;j<R;j++) {
			mapp[i][j] = D;
		}
	}
	
	for (i=0;i<K;i++) {
		cin >> r >> c;
		
		dinosaur[c][r]++;
	}
	
	cin >> M;
	
	for (j=0;j<M;j++) {
		cin >> a >> b >> s >> d;
		
		t = 0;  // 範圍內是否有清醒的恐龍
		
		// cout << "k: " << b-s/2 << "~" << b+s/2 << endl;
		// cout << "l: " << a-s/2 << "~" << a+s/2 << endl;
		
		for (k=b-s/2;k<=b+s/2;k++) {  // 列的範圍 (y 座標) 
			for (l=a-s/2;l<=a+s/2;l++) {  // 行的範圍 (x 座標) 
				if (k < 0 || k >= C || l < 0 || l >= R)  //超出邊界 
					continue;  // 略過
				
				if (dinosaur[k][l] > 0) { 
					// cout << l << " " << k << " | " << dinosaur[k][l] << endl;
					t++;
					dinosaur[k][l] = 0;  // 砸暈所有恐龍 
				} 
			}
		}
		
		if (t == 0) {  // 沒有清醒的恐龍 
			for (k=b-s/2;k<=b+s/2;k++) {  // 列的範圍 (y 座標) 
				for (l=a-s/2;l<=a+s/2;l++) {  // 行的範圍 (x 座標) 
					if (k < 0 || k >= C || l < 0 || l >= R)  //超出邊界 
						continue;  // 略過
					
					mapp[k][l] = mapp[k][l] - d;  // 地面高度下降 
				}
			}
		}
	}
	
	t = 0;  // 存剩餘的清醒恐龍數 
	Max = mapp[0][0];  // 存最高的地面高度
	Min = mapp[0][0];  // 存最低的地面高度
	
	for (i=0;i<C;i++) {
		for (j=0;j<R;j++) {
			t += dinosaur[i][j];
			
			if (mapp[i][j] > Max)  // 取較大的當最高的地面高度
				Max = mapp[i][j];
				
			if (mapp[i][j] < Min)  // 取較小的當最低的地面高度
				Min = mapp[i][j];
				
			// cout << mapp[i][j] << " ";
		}
		
		// cout << endl;
	}
	
	cout << Max << " " << Min << " " << t; 

	return 0;
}
