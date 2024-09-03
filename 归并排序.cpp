#include<stdlib.h>
#include<stdio.h>

void merge(int* arr, int left, int mid, int right) {
	//������������Ϊ [left,mid];������������Ϊ[mid+1,right]
	//����һ����ʱ��temp���飬������ʱ��źϲ���Ľ��
	int temp_size = right - left + 1;
	int* temp = (int*)malloc(sizeof(int) * temp_size);

	//��ʼ���������������ʼ����
	int i = left, j = mid + 1, k = 0;
	//�����������鶼����Ԫ��ʱ������бȽϣ�����С��Ԫ�ظ��Ƶ�����������
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	//����һ������û��Ԫ�غ󣬽���һ����ʣ��Ԫ�أ�ֱ�Ӹ��Ƶ���ʱ������
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	//����ʱ�����е�Ԫ�ظ��ƻ�ԭ�����Ӧ������
	for (int k = 0; k < temp_size; k++) {
		//ע���������!!!!!!!!!!!!!!!!!!!!!!!!
		arr[left + k] = temp[k];
	}
	free(temp);
}


void MergeSort(int* arr, int left, int right) {
	//�������鳤��Ϊ1ʱ��ֹ�ݹ�
	if (left >= right) return;

	//��������л���
	int mid = left + (right - left) / 2;
	//�ݹ�����������
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	//�ϲ��׶�
	merge(arr, left, mid, right);

}


//int main() {
//	int n;
//	scanf_s("%d", &n);
//	int* arr = (int*)malloc((sizeof(int) * (n + 1)));
//	for (int i = 0; i < n; i++) {
//		arr[i] = rand() % 100 + 1;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	MergeSort(arr,0, n-1);
//	for (int i = 0; i < n; i++) {
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	return 0;
//}