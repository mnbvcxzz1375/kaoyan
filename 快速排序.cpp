#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Quick_Sort(int* arr, int left, int right) {
	if (left >= right) return;  //�����鳤��Ϊ1ʱ����ֹ�ݹ�

	//�ڱ�����
	int i = left, j = right;
	//��׼Ԫ��
	int pivot = arr[left];
		while (i < j) {
			//�����������׸�С�ڻ�׼����Ԫ��
			while (arr[j] >= pivot && i < j) {
				j--;
			}
			//�����������׸����ڻ�׼����Ԫ��
			while (arr[i] <= pivot && i < j) {
				i++;
			}
			
			//����������Ԫ��
			swap(arr, i, j);
		}
		//����׼Ԫ�ؽ����������������м�
		swap(arr, i, left);

		Quick_Sort(arr, left, i - 1);
		Quick_Sort(arr, i+1, right);
}

//int main() {
//	int n;
//	scanf_s("%d", &n);
//	int* arr = (int*)malloc((sizeof(int) * (n + 1)));
//	for (int i = 0; i < n; i++) {
//		arr[i] = rand() % 20 + 1;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	Quick_Sort(arr,0, n-1);
//	for (int i = 0; i < n; i++) {
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	return 0;
//}