//随机生成20-100的10个数，进行选择排序

#include<stdio.h>
#include<stdlib.h>

void SelectSort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int min = arr[i - 1];

		int flag = i - 1;
		for (int j = i; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				flag = j;
			}
		}
		if (flag != i-1) {
			int temp = arr[i - 1];
			arr[i - 1] = arr[flag];
			arr[flag] = temp;
		}

	}
}

//int main() {
//	int arr[10];
//	for (int i = 0; i < 10; i++) {
//		arr[i] = rand() % 81+20;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	SelectSort(arr, 10);
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//}