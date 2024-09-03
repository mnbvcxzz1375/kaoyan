#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

void shellSort(int *arr, int n) {
    // 逐步减少步长
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个子数组进行插入排序
        for (int i = gap; i < n; i++) { //将 arr[i] 和它之前的元素进行比较
            int temp = arr[i];  //对应子数组的最后一个元素
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {  
                /*从索引 j = i 开始，逐步向前比较步长为 gap 的元素，
                直到找到一个比 temp 小的元素或达到了子数组的起始位置。*/
                arr[j] = arr[j - gap];    //如果 arr[j - gap] > temp，则将 arr[j - gap] 向后移动，直到找到合适的位置。
            }
            arr[j] = temp;  //将arr[j]插入到正确位置
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