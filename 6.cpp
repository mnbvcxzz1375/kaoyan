//计算sinx的值，sinx=x-x^3/3!+x^5/5!...直到最后一项的绝对值小于10^-5时为止


#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int nn(int i) {
	if (i == 0) return 1;
	else return i * nn(i - 1);
}

double sum = 0;
void sinx(double x) {
	int i = 1;
	int flag = 0;
	while (fabs(pow(x, i) / nn(i)) >= (pow(10, -5))) {
		if (flag % 2 == 0) {
			sum += fabs(pow(x, i) / nn(i));
			flag++;
		}
		else {
			sum -= fabs(pow(x, i) / nn(i));
			flag++;
		}
		i += 2;
	}
	printf("%d %lf",i, sum);
}


//int main() {
//	double x;
//	scanf_s("%d", &x);
//	sinx(x);
//}

//#include<stdlib.h>
//#include<stdio.h>
//#include<math.h>
//
//int nn(int i) {
//	int result = 1;
//	for (int j = 1; j <= i; j++) {
//		result *= j;
//	}
//	return result;
//}
//
//void sinx(double x) {
//	double sum = 0;
//	int i = 1;
//	double term;
//
//	while (fabs(term = pow(x, i) / nn(i)) >= 1e-5) {
//		sum += pow(-1, (i - 1) / 2) * term;
//		i += 2;
//	}
//
//	printf("sin(%.2lf) = %lf\n", x, sum);
//}
//
//int main() {
//	double x;
//	scanf_s("%lf", &x);
//	sinx(x);
//	return 0;
//}
