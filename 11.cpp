#include<stdio.h>
#include<stdlib.h>

void primer_sort(int* arr, int* temp, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 2) continue;
		if (arr[i] == 2) {
			temp[k++] = arr[i];
			continue;
		}
		int j;
		for ( j = 2; j <= arr[i]; j++) {
			if (arr[i] % j == 0) break;
		}
		if (j == arr[i]) {
			/*printf("yes\n");*/
			temp[k++] = arr[i];
		}
	}

	for (int a = 0; a < k-1; a++) {
		for (int b = 0; b < k - a - 1; b++) {
			if (temp[b] > temp[b + 1]) {
				int tmp = temp[b];
				temp[b] = temp[b + 1];
				temp[b + 1] = tmp;
			}
		}
	}

	for (int c = 0; c < k; c++) {
		printf("%d ", temp[c]);
	}
}



//int main() {
//	int* arr = (int*)malloc(sizeof(int) * 60);
//	int* temp = (int*)malloc(sizeof(int) * 60);
//	//int arr[9] = { 5,4,3,2,1,10,11,7,9 };
//	for (int i = 0; i < 60; i++) {
//		arr[i] = rand() % 101 + 200;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	primer_sort(arr,temp, 60);
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//void primer_sort(int* arr, int* temp, int n) {
//	int k = 0;
//	for (int i = 0; i < n; i++) {
//		if (arr[i] < 2) continue;  // 跳过小于2的非质数
//		int is_prime = 1; // 假设是质数
//		for (int j = 2; j <= sqrt(arr[i]); j++) {
//			if (arr[i] % j == 0) {
//				is_prime = 0; // 如果能整除，则不是质数
//				break;
//			}
//		}
//		if (is_prime) {
//			temp[k++] = arr[i];
//		}
//	}
//
//	// 冒泡排序
//	for (int a = 0; a < k - 1; a++) {
//		for (int b = 0; b < k - a - 1; b++) {
//			if (temp[b] > temp[b + 1]) {
//				int tmp = temp[b];
//				temp[b] = temp[b + 1];
//				temp[b + 1] = tmp;
//			}
//		}
//	}
//
//	// 输出排序后的质数
//	for (int c = 0; c < k; c++) {
//		printf("%d ", temp[c]);
//	}
//	printf("\n");
//}
//
//int main() {
//	int arr[4] = { 5, 4, 3, 2 };
//	int* temp = (int*)malloc(sizeof(int) * 60);
//
//	primer_sort(arr, temp, 4);
//
//	// 释放内存
//	free(temp);
//
//	return 0;
//}

