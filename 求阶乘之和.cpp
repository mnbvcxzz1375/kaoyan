#include<iostream>
#include<cstdlib>
using namespace std;

//递归实现阶乘
int f(int n) {
	if (n == 1) return 1;
	else return n * f(n - 1);
}


//int main() {
//	int n;
//	cin >> n;
//	int sum1 = 0,sum2=0;
//
//	for (int i = 1; i <= n; i++) {
//		//递归实现
//		sum1 += f(i);
//		//cout << f(i) << " " << endl;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		//非递归实现
//		int summ = 1;
//		for (int j = 1; j <= i; j++) {
//			summ *= j;
//		}
//		//cout << summ << " " << endl;
//		sum2 += summ;
//	}
//	cout << sum1 << " " << sum2 << endl;
//}