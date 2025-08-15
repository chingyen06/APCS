#include <iostream>
using namespace std;

int main()
{
	int k, x1, x2, y1, y2, p = 0, v;
	
	cin >> k >> x1 >> y1 >> x2 >> y2;
	
	v = k;  //當前生命值 (其實也可以直接用 k)
	
	while (v > 0) {
		p = p + v;
		
		if (p % x1 == 0)  //位置在 x1 的倍數
			v -= y1;  //扣除 y1 點生命值 
		if (p % x2 == 0)  //位置在 x2 的倍數
			v -= y2;  //扣除 y1 點生命值 
	} 
	
	cout << p;

	return 0;
}
