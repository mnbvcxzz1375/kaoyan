//����30����������������a[],������a[]�е�ÿһ������ƽ���ʹ�������b[],�����顤b[]����������������

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