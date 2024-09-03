//产生50个[100,300]的随机数，先对这50个随机数进行升序排序，然后再用二分查找的从键盘输入关键数字，
//找到回复位置，找不到回复不存在


#include<stdlib.h>
#include<stdio.h>

void Sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int binary_Search(int* arr, int n, int key) {
	int low = 0, high = n - 1, mid;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[low] == key) return low;
		if (arr[high] == key) return high;
		
		if (arr[mid] == key)  return mid;
		else if (arr[mid] > key)
			high = mid - 1;
		else if (arr[mid] < key)
			low = mid + 1;
	}
	return -1;
}



//int main() {
//	int arr[50];
//	for (int i = 0; i < 50; i++) {
//		arr[i] = rand() % 201 + 100;  //%201 == 0 - 200      +100 ==100 - 300
//	}
//	
//	int key;
//	Sort(arr, 50);
//	for (int i = 0; i < 50; i++) {
//		printf("%d %d ", i, arr[i]);
//	}
//	printf("\n");
//
//	scanf_s("%d", &key);
//
//	int num = binary_Search(arr, 50, key);
//	if (num != -1) printf("%d", num);
//	else printf("not exist");
//}