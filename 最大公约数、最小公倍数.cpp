#include<iostream>
#include<cstdlib>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

//int main() {
//	int n, m;
//	cin >> n >> m;
//	int g = gcd(n, m);//最大公约数
//	int l = lcm(n, m);//最小公倍数
//	cout << g << " " << l << endl;
//	return 0;
//}