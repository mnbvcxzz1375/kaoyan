#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
using namespace  std;

void norm_prim(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cout << arr[i] << ":NO" << endl; // 1 ��������
			continue;
		}
		else if (arr[i] == 2) {
			cout << arr[i] << ":YES" << endl; // 2 ������
			continue;
		}
		int k;
		for ( k = 2; k <= arr[i]; k++) {
			if (arr[i] % k == 0) break;
		}
		//ע���ж���������arr[i]
		if (arr[i] == k)
			cout << arr[i] << ":YES" << endl;
		else
			cout << arr[i] << ":NO" << endl;

	}
}


void norm_sqrt(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cout << arr[i] << ":NO" << endl; // 1 ��������
		}
		else if (arr[i] == 2) {
			cout << arr[i] << ":YES" << endl; // 2 ������
		}
		else {
			bool is_prime = true;
			int limit = sqrt(arr[i]);
			for (int k = 2; k <= limit; k++) {
				if (arr[i] % k == 0) {
					is_prime = false;
					break;
				}
			}
			if (is_prime)
				cout << arr[i] << ":YES" << endl;
			else
				cout << arr[i] << ":NO" << endl;
		}
	}
}

//int main() {
//	int n;
//	cin >> n;
//	int* arr = (int*)malloc(sizeof(int) * (n+1));
//	for (int i = 1; i <= n; i++) {
//		arr[i] = rand()%10+1;
//	}
//	norm_prim(arr, n);
//	cout << "-----------------------" << endl;
//	//����Ŀ������ͷ�ļ�û��cmath����math.h�Ͳ���ʹ��
//	norm_sqrt(arr, n);
//	
//}