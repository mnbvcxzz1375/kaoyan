#include<iostream>
#include<cstdlib>
#include<malloc.h>
using namespace std;

//ע��sum��ʼ��Ϊ1����Ϊ0�ͻ�ȫ��Ϊ0
void norm_mult(int* arr, int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= arr[i];
	}
	cout << "norm_mult:" << sum << endl;
}

int digui_mult(int* arr, int n) {
	if (n == 1) return arr[1];
	else
		return arr[n] * digui_mult(arr, n - 1);
}

//int main() {
//	int n;
//	cin >> n;
//	int* arr = (int*)malloc(sizeof(int) * (n+1));
//	for (int i = 1; i <= n; i++) {
//		arr[i] = i;
//	}
//
//	norm_mult(arr, n);
//	cout<<"dugui_mult:"<<digui_mult(arr, n)<<endl;
//
//}