#include<stdio.h>
#include<string.h>


void digui_reserve(int arr[], int n) {
	if (n == 0) {
		printf("%d ", arr[n]);
		return;
	}
	else {
		printf("%d ", arr[n]);
		digui_reserve(arr, n - 1);	
	}
}

//int main() {
//	int arr[10];
//	int temp[10];
//	for (int i = 0; i < 10; i++) {
//		arr[i] = i;
//	}
//
//	for (int i = 0; i < 10; i++) {
//		temp[i] = arr[10 - i - 1];
//	}
//
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", temp[i]);
//	}
//	printf("\n");
//
//	digui_reserve(arr, 9);
//}