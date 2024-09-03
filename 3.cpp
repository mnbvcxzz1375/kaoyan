//产生20个再[200,400]范围内的随机数，存入数组array1,其中能被5整除的数存入数组array2，要求输出array2中的平均值

#include<stdlib.h>
#include<stdio.h>

int k = 0;
void div_5(int* array1, int* array2, int n) {
	for (int i = 0; i < n; i++) {
		if (array1[i] % 5 == 0) array2[k++] = array1[i];
	}
}

//int main() {
//	int array1[20], array2[20];
//	//int array1[20] = { 241 ,376 ,305, 369, 274 ,246 ,221, 212 ,228 ,343 ,225 ,205 ,366, 344 ,312 ,289, 381, 283, 203 ,209 };
//	for (int i = 0; i < 20; i++) {
//		array1[i] = rand() % 201 + 200;
//		printf("%d ", array1[i]);
//	}
//
//	printf("\n");
//
//	div_5(array1, array2, 20);
//	int sum = 0;
//	for (int j = 0; j < k; j++) {
//		printf("%d ", array2[j]);
//		sum += array2[j];
//	}
//	printf("\n");
//	printf("%d", sum / k);
//}