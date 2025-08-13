#include <bits/stdc++.h>
using namespace std;

string exchange(int n, string s)
{
	int i;
	char temp;
	
	for (i=0;i<n;i=i+2) {
		temp = s[i];
		s[i] = s[i+1];
		s[i+1] = temp;
	}
	
	return s;
}

string sorting(int n, string s)
{
	int i;
	char temp;
	
	for (i=0;i<n;i=i+2) {
		if (s[i] > s[i+1]) { 
			temp = s[i];
			s[i] = s[i+1];
			s[i+1] = temp;
		} 
	}
	
	return s;
}

string rearrange(int n, string s)
{
	string temp = s;
	int i, m = n / 2, num = 0;  //m為s字串一半的長度, num 存已更新的長度 
	
	for (i=0;i<m;i++) {
		s[num] = temp[i];  //前半字串 
		s[num+1] = temp[m+i];  //後半字串
		
		num = num + 2;
	}
	
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int i, n, k, category;
	
	cin >> s;
	
	n = s.size();  //字串長度 
	
	cin >> k;
	
	for (i=0;i<k;i++) {
		cin >> category;  //指令類別
		
		if (category == 0)  //兩兩交換 
			s = exchange(n, s);
		else if (category == 1)  //兩兩排序
			s = sorting(n, s);
		else  //完美重排 
			s = rearrange(n, s);
	}
	
	cout << s;

	return 0;
}
