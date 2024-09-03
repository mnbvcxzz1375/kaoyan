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
//	int g = gcd(n, m);//���Լ��
//	int l = lcm(n, m);//��С������
//	cout << g << " " << l << endl;
//	return 0;
//}