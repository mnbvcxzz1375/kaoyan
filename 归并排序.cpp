#include<stdlib.h>
#include<stdio.h>

void merge(int* arr, int left, int mid, int right) {
	//左子数组区间为 [left,mid];右子数组区间为[mid+1,right]
	//创建一个临时的temp数组，用于暂时存放合并后的结果
	int temp_size = right - left + 1;
	int* temp = (int*)malloc(sizeof(int) * temp_size);

	//初始化左右子数组的起始索引
	int i = left, j = mid + 1, k = 0;
	//当左右子数组都还有元素时，则进行比较，将较小的元素复制到辅组数组中
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	//当有一个数组没有元素后，将另一个的剩余元素，直接复制到临时数组中
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	//将临时数组中的元素复制会原数组对应区间中
	for (int k = 0; k < temp_size; k++) {
		//注意这个区间!!!!!!!!!!!!!!!!!!!!!!!!
		arr[left + k] = temp[k];
	}
	free(temp);
}


void MergeSort(int* arr, int left, int right) {
	//当子数组长度为1时终止递归
	if (left >= right) return;

	//对数组进行划分
	int mid = left + (right - left) / 2;
	//递归左右子数组
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	//合并阶段
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