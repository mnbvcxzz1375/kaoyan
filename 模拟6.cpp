#include<stdio.h>

void Insert_sort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
					arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

//int main() {
//	int arr[6] = { 44,18,74,61,42,31 };
//
//	Insert_sort(arr, 6);
//	for (int i = 0; i < 6; i++) {
//		printf("%d ", arr[i]);
//	}
//}