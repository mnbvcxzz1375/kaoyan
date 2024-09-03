#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

void shellSort(int *arr, int n) {
    // �𲽼��ٲ���
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // ��ÿ����������в�������
        for (int i = gap; i < n; i++) { //�� arr[i] ����֮ǰ��Ԫ�ؽ��бȽ�
            int temp = arr[i];  //��Ӧ����������һ��Ԫ��
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {  
                /*������ j = i ��ʼ������ǰ�Ƚϲ���Ϊ gap ��Ԫ�أ�
                ֱ���ҵ�һ���� temp С��Ԫ�ػ�ﵽ�����������ʼλ�á�*/
                arr[j] = arr[j - gap];    //��� arr[j - gap] > temp���� arr[j - gap] ����ƶ���ֱ���ҵ����ʵ�λ�á�
            }
            arr[j] = temp;  //��arr[j]���뵽��ȷλ��
        }
    }
}

//int main() {
//	int* arr = (int*)malloc(sizeof(int) * maxsize);
//	for (int i = 0; i < maxsize; i++) {
//		arr[i] = rand() % 100;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//    shellSort(arr, maxsize);
//	
//	for (int i = 0; i < maxsize; i++) {
//		printf("%d ", arr[i]);
//	}
//
//}