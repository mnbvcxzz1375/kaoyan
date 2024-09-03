#include<iostream>
#include<cstdlib>
using namespace std;

void bubble_sort(int* arr, int n) {
	//注意的循环的次数
	for (int i = 0; i < n - 1; i++) {
		int count = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count = 1;
			}
		}
		if (count == 0) break;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

//int main() {
//	int n;
//	cin >> n;
//	int* arr = (int*)malloc(sizeof(int) * (n + 1));
//	for (int i = 0; i < n; i++) {
//		arr[i] = rand() % 100;
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	bubble_sort(arr, n);
//}