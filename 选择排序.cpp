#include<iostream>
#include<cstdlib>
using namespace std;

//��ԭʼ������ѡ����С��1�����ݣ������λ�ڵ�1��λ�õ����ݽ���
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