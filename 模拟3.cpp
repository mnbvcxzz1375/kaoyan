#include<stdio.h>

int bin_search(int* arr, int n,int key) {
	int low = 0, high = n - 1, mid;
	while (low < high) {
		
		mid = low + (high - low) / 2;
		if (arr[low] == key) return low;
		if (arr[high] == key) return high;
		if (arr[mid] == key)  return mid;
		else if (arr[mid] < key) low = mid + 1;
		else if (arr[mid] > key) high = mid - 1;
	}
	return -1;
}



//int main() {
//	int arr[10] = { 28,30,32,41,49,53,69,82,94,99 };
//	int key;
//	while (scanf_s("%d", &key) != EOF) {
//		int site = bin_search(arr, 10, key);
//		if (site != -1) {
//			printf("%d\n", site);
//		}
//		else printf("no exist\n");
//	}
//	return 0;
//}