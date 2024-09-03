#include<stdlib.h>
#include<stdio.h>
#define maxsize 10

void search(int* arr, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			printf("%d", i);
		}
	}
	printf("not exist");
}

//int main() {
//	int* arr = (int*)malloc(sizeof(int) * maxsize);
//	for (int i = 0; i < maxsize; i++) {
//		arr[i] = rand() % 100 + 10;
//		printf("%d %d ", i, arr[i]);
//	}
//	printf("\n");
//	int key;
//	scanf_s("%d", &key);
//	search(arr, maxsize, key);
//	return 0;
//}