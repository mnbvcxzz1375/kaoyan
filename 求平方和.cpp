#include<iostream>
#include<math.h>
using namespace std;


int powf(int *arr,int n) {
	if (n == 1) return pow(arr[n], 2);
	else {
		return pow(arr[n], 2) + powf(arr, n - 1);
	}
}

//int main() {
//	int n;
//	cin >> n;
//	int* arr = (int*)malloc(sizeof(int) * (n + 1));
//	for (int i = 1; i <= n; i++) {
//		arr[i] = i;
//	}
//
//	//�ǵݹ�
//	int sum1 = 0;
//	for (int i = 1; i <= n; i++) {
//		/*sum1 += (arr[i] * arr[i]);*/
//		sum1 += pow(arr[i], 2);
//	}
//
//	//�ݹ�
//	int sum2 =powf(arr,n);
//	cout << sum1 << " " << sum2 << endl;
//}