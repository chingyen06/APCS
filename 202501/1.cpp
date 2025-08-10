#include <iostream>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, a, b, n, cycle, people, wait, total = 0;
	
	cin >> a >> b >> n; 

	cycle = a + b;  //綠燈 + 紅燈的週期 

	for (i=0;i<n;i++) {
		cin >> people;  //騎行時間 
		
		wait = people % cycle - a;  //省下的等待時間 
		
		if (wait < 0)  //綠燈時通過 
			wait = 0;  //無需等待
		else
			wait = b - wait;  //需等待的紅燈時間 
			
		total += wait;  //總等待時間 
	}
	
	cout << total;

	return 0;
}
