//��һ���ͥ��������ֵܽ��á�һֱÿһ�����ӵ�����Ĵ�С��������꣬
//������һ�������������������˵����䣬���������Լ���С���������£�����ü����ϴ������,ʹ�õݹ�

#include<stdio.h>
#include<stdlib.h>

int max_age(int num, int min_age) {
	if (num == 1) 
		return min_age;
	else 
		return max_age(num - 1, min_age) + 2;
}


//int main() {
//	int num = 0, min_ages = 0;
//	scanf_s("%d %d", &num, &min_ages);
//
//	int max = max_age(num, min_ages);
//	printf("%d", max);
//}