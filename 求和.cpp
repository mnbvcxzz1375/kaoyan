#include<iostream>
#include<cstdlib>
using namespace std;

//int main() {
//	int n = rand() % 51 + 13;
//	int m = rand() % 10 + 5;
//	cout << n << "+" << m << "=" << n + m << endl;
//	return 0;
//}

void norm(int* arr,int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << "norm: " << sum << endl;
}


//ע��ݹ鷽ʽ
int digui(int* arr, int n) {
	if (n == 1) { // ��ֻʣ�����һ��Ԫ��ʱ��ֱ�ӷ������Ԫ��
		return arr[0];
	}
	else {
		return arr[n - 1] + digui(arr, n - 1); // �ݹ��ۼ�ǰ n-1 ��Ԫ��
	}
}

//int main() {
//	int n;
//	cin >> n;
//	int *arr = new int[n];
//	for (int i = 0; i < n; i++) {
//		arr[i] = i;
//	}
//	norm(arr,n);
//	cout<<"digui:"<<digui(arr, n)<<endl;
//}