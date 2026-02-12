#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, N, s_odd, s_even, C;
	int check, place, Max = 0;
	int num[1000]={};
	
	cin >> N;
	
	string s;
	
	for (i=0;i<N;i++) {
		
		cin >> s;
		
		s_odd = 0;
		s_even = 0;
		C = s[12] - '0';  // 第 13 碼轉成 int 存在 C
		
		for (j=0;j<12;j=j+2) {  // 一次 + 2 (一次會處理奇數+偶數) 
			s_odd += s[j] - '0';  // 奇數位
			s_even += s[j+1] - '0';  // 偶數位 
		}
		
		check = (s_odd + 3 * s_even) % 10 + C;  // 合法條件的公式計算 
		
		if (check == 0 || check == 10) {  // 產地合法
			place = (s[0]-'0') * 100 + (s[1]-'0') * 10 + (s[2]-'0');  // 產地轉乘 int
			
			num[place]++;  // 該產地出現數量 + 1 
		}
	}
	
	for (i=1;i<1000;i++) {  // 找出出現次數最多的產地 
		if (num[i] > num[Max]) {
			Max = i; 
		} 
	}
	
	if (Max < 10)
		cout << "00";
	else if (Max < 100)  // 10 < Max < 100
		cout << "0";
	
	cout << Max << " " << num[Max];

	return 0;
}
