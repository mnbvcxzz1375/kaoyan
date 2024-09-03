//输入30个正整数存入数组a[],把数组a[]中的每一个数的平方和存入数组b[],对数组·b[]进行升序排序后输出

#include<stdio.h>
#include<stdlib.h>


void sort(int* b, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (b[j] > b[j + 1]) {
				int temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
}


//int main() {
//	int a[30], b[30];
//	int n = 30;
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d", &a[i]);
//	}
//
//	for (int j = 0; j < n; j++) {
//		b[j] = a[j] * a[j];
//	}
//
//	sort(b, n);
//
//
//	for (int i = 0; i < n; i++) {
//		printf("%d ", b[i]);
//	}
//}