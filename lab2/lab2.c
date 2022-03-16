#include <stdio.h>

int main(){
	int mas[10] = {10, -12, 2, 7, 3, -44, 150, 8, -9, 17};
	int sum = 0;
	int n;

	for (n = 0; n < 10; n++){
		if (mas[n] > 0){
			sum += mas[n];
		}
		else {
			mas[n] = mas[n] * (-1);
			sum += mas[n];
		}
	}
	printf ("Получается что: %d \n", sum);
	return 0;
}
