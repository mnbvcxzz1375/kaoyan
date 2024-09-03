#include<iostream>
#include<cstdlib>
using namespace std;
//���ֲ��ң��۰���ң���ǰ������������


int Binary_Search(int* arr, int key ,int num) {
	int low = 0, high = num - 1, mid;

	while (low < high) {
		//�Ա߽���в��ң����ٲ��Ҵ���
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