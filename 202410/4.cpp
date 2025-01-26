#include <bits/stdc++.h>
using namespace std;
typedef int long long ull;

struct bus {
	ull start, end;
};

int rule(bus a, bus b)  //排序規則
{
	if (a.end != b.end)  //路線終點小的往前 
		return a.end < b.end;
	else  //路線終點一樣，則路線起點小的往前 
		return a.start < b.start;
}

int binary_search(bus route[], ull l, ull r, ull key, int mode)  //二分搜尋法
{
	ull mid = (l + r) / 2;
	
	while (l <= r) {
		mid = (l + r) / 2;		

		if (route[mid].end >= key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	if (mode == 0)  //找 >= key 的前一個 
		return l;
	else if (mode == 1)  //找 < key 的
		return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i;
	ull n, m, p;
	
	cin >> n >> m >> p;
	
	bus route[n+1];  //公車路線
	ull prefix[n+1]={}; 
	map<ull, ull> station;  //儲存到該站牌的方法數 
	
	route[0].start = -1;
	route[0].end = -1;
	
	for (i=1;i<=n;i++)  //輸入路線起點 
		cin >> route[i].start;
		
	for (i=1;i<=n;i++)  //輸入路線終點 
		cin >> route[i].end;
		
	sort(route, route + n + 1, rule);  //將路線依據 rule 排序 
	
	for (i=1;i<=n;i++) {
		ull begin, ends, total = 0;
		
		begin = binary_search(route, 0, n, route[i].start, 0);  //搜尋第一個 >= 此路線起點為 begin 
		ends = binary_search(route, 0, n, route[i].end, 1);  //搜尋最後一個 < 此路線終點的為 ends 
		
		total = (prefix[ends] - prefix[begin-1] + p) % p;  //找到這條路線有幾種搭車方式 % p 的結果 
			
		if (route[i].start == 0)  //起點在 0 固定有 1 條路線 
			total++;
		
		prefix[i] = (total % p + prefix[i-1] % p) % p;  //搭車方式的前綴和
		
		if (station.find(route[i].end) != station.end())  //紀錄到某一個點 (route[i].end) 的搭車方式 % p 的結果 
			station[route[i].end] += total % p;
		else
			station[route[i].end] = total % p;
	}
		
	cout << station[m] % p;

	return 0;
}
