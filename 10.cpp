//有一大家庭，有许多兄弟姐妹。一直每一个孩子的年龄的大小都相差两岁，
//请问在一个程序中来计算所有人的年龄，输入人数以及最小年龄的情况下，如何让计算老大的年龄,使用递归

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