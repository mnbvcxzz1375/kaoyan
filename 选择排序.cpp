#include<iostream>
#include<cstdlib>
using namespace std;

//从原始数组中选择最小的1个数据，将其和位于第1个位置的数据交换
void Select_Sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}

		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
			//swap(arr[i], arr[min]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}


int main() {
	int n;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	Select_Sort(arr, n);
}