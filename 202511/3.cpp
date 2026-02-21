#include <iostream>
using namespace std;

int tree[100001]={};
int p[100001], pos[100001];

void build(int node, int start, int end)
{
	int mid = (start + end) / 2;
	
	if (start == end) {  // 代表在葉節點 (最後一排，底下沒節點) 
		tree[node] = 1;  // 自己一個數量就是 1 
		return;
	}
	
	build(2 * node, start, mid);  // node 的左子節點 
	build(2 * node + 1, mid + 1, end);  // node 的右子節點
	
	// 這個節點 node 的數量就是左右子的加總
	// 自己不算，因為自己的數字存的是代表這區間有多少個葉節點 
	tree[node] = tree[2 * node] + tree[2 * node + 1]; 
} 

int move(int node, int start, int end, int left, int right)
{
	int mid = (start + end) / 2;
	
	// 這節點 node 代表的範圍 [start, end] 不在 [left, right] 內 
	if (right < start || end < left)  
		return 0;
	
	// 這節點 node 代表的範圍 [start, end] 在 [left, right] 內 
	if (left <= start && end <= right)
		return tree[node];
	
	// 這節點 node 代表的範圍 [start, end] 不完全在 [left, right] 內 
    return move(2 * node, start, mid, left, right) + move(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int target)
{
	int mid = (start + end) / 2;
	
	if (start == end) {  // 數字拿走了 
		tree[node] = 0;
		return;
	}
	
    if (target <= mid)  // 要輸出的數字 <= mid 代表在左子節點範圍內 
		update(2 * node, start, mid, target);
    else  // 反之在右子節點範圍內 
		update(2 * node + 1, mid + 1, end, target);
	
	// 把更新後的結果更新到這個節點
	// 這個節點 node 的數量就是左右子的加總 
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, n, now, target;
	long long int t = 0; 
	int left, right;
	
	cin >> n;
	
	for (i=1;i<=n;i++) {
		cin >> p[i];
		
		pos[p[i]] = i;  // 存每個數字的索引 
	}
	
	build(1, 1, n);  // 建立線段樹
	
	now = 1;  // 一開始位置設在 1
	
	for (i=1;i<=n;i++) {
		target = pos[i];  // 查詢現在要輸出的數字的位置
		
		left = min(now, target);  // 小的當左界
		right = max(now, target);  // 大的當右界 
		
		t += move(1, 1, n, left, right);  // 算這次輸出數字移動需要的 pop 數 
	
		update(1, 1, n, target);  // 更新取走要輸出的數字後的線段樹 
		
		now = target;  // 移動位置 
	}
	
	cout << t;

	return 0;
}
