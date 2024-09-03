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
		hanoi(n - 1, a, c, b);//��A���ϵ�n-1��Բ��ͨ��C�Ƶ�B��
		move(a, c); //��A���ϵ����һ��Բ���Ƶ�C��
		hanoi(n - 1, b, a, c);//��B���ϵ�n-1��Բ��ͨ��A�Ƶ�C��
	}
}

//int main() {
//	int n;
//	cin >> n;
//	int step = Hanoi_step(n);
//	cout << "sum step:" << step << endl;
//	//Բ���������ֱ�����֣�ע�����֣���������
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//}