#include<iostream>
#include<cstdlib>
using namespace std;
//二分查找（折半查找）的前提是数组有序


int Binary_Search(int* arr, int key ,int num) {
	int low = 0, high = num - 1, mid;

	while (low < high) {
		//对边界进行查找，减少查找次数
		if (arr[low] == key)  return low;
		if (arr[high] == key)  return high;
		mid = low + (high - low) / 2;

		if (arr[mid] == key)  return mid;
		else if (arr[mid] > key)
			high = mid - 1;
		else if (arr[mid] < key)
			low = mid + 1;
	}
}

//int main() {
//	int n,key;
//	cin >> n >>key;
//	int* arr = (int*)malloc(sizeof(int) * (n + 1));
//	for (int i = 0; i < n; i++) {
//		arr[i] = i;
//	}
//	int site = Binary_Search(arr, key,10);
//	cout << site << endl;
//	return 0;
//}