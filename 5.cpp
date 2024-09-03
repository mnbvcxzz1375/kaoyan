//ÅĞ¶Ï25¡¢36¡¢71ÊÇ·ñÎªËØÊı

#include<stdlib.h>
#include<stdio.h>

void primer(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			printf("No\n");
			continue;
		}
		if (arr[i] == 2) {
			printf("Yes\n");
			continue;
		}
		int j;
		for (j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) break;
		}
		if (j != arr[i]) printf("No\n");
		else if (j == arr[i]) printf("Yes\n");
	}
}


//int main() {
//	int arr[10] = { 25,36,71,1,2,5,7,9,11,10 };
//	primer(arr, 10);
//}