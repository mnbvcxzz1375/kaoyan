#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;

int Hanoi_step(int n) {
	return pow(2, n) - 1;
}

void move(char x, char y) {
	cout << x << "--->" << y << endl;
}

void hanoi(int n,char a ,char b, char c) {
	if (n == 1) {
		move(a, c);
	}
	else {
		hanoi(n - 1, a, c, b);//将A座上的n-1个圆盘通过C移到B上
		move(a, c); //将A座上的最后一个圆盘移到C上
		hanoi(n - 1, b, a, c);//将B座上的n-1个圆盘通过A移到C上
	}
}

//int main() {
//	int n;
//	cin >> n;
//	int step = Hanoi_step(n);
//	cout << "sum step:" << step << endl;
//	//圆盘数，座分别的名字，注意区分！！！！！
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//}