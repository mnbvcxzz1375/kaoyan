#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
using namespace  std;

void norm_prim(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cout << arr[i] << ":NO" << endl; // 1 不是素数
			continue;
		}
		else if (arr[i] == 2) {
			cout << arr[i] << ":YES" << endl; // 2 是素数
			continue;
		}
		int k;
		for ( k = 2; k <= arr[i]; k++) {
			if (arr[i] % k == 0) break;
		}
		//注意判断条件，是arr[i]
		if (arr[i] == k)
			cout << arr[i] << ":YES" << endl;
		else
			cout << arr[i] << ":NO" << endl;

	}
}


void norm_sqrt(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cout << arr[i] << ":NO" << endl; // 1 不是素数
		}
		else if (arr[i] == 2) {
			cout << arr[i] << ":YES" << endl; // 2 是素数
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
//	//若题目给定的头文件没有cmath或者math.h就不能使用
//	norm_sqrt(arr, n);
//	
//}