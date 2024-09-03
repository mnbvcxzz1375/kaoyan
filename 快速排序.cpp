#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Quick_Sort(int* arr, int left, int right) {
	if (left >= right) return;  //子数组长度为1时，终止递归

	//哨兵划分
	int i = left, j = right;
	//基准元素
	int pivot = arr[left];
		while (i < j) {
			//从右向左找首个小于基准数的元素
			while (arr[j] >= pivot && i < j) {
				j--;
			}
			//从左向右找首个大于基准数的元素
			while (arr[i] <= pivot && i < j) {
				i++;
			}
			
			//交换这两个元素
			swap(arr, i, j);
		}
		//将基准元素交换到两个子数组中间
		swap(arr, i, left);

		Quick_Sort(arr, left, i - 1);
		Quick_Sort(arr, i+1, right);
}

//int main() {
//	int n;
//	scanf_s("%d", &n);
//	int* arr = (int*)malloc((sizeof(int) * (n + 1)));
//	for (int i = 0; i < n; i++) {
//		arr[i] = rand() % 20 + 1;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	Quick_Sort(arr,0, n-1);
//	for (int i = 0; i < n; i++) {
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	return 0;
//}