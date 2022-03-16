#include <iostream>
#include <ctime>

using namespace std;

int main(){
	srand(time(0));
	long long n=0;
	long long x = 10;
	long long arr[x];

	cout << "Сгенерированный массив 0_0\n";

	for (int i = 0; i < x; i++){
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}
	cout << "\nВведите количество смещений(1-...): ";
	cin >> n;

	long long *n_arr = &arr[0];

	if (n < 1){
		cout << "\nЧТо-то пошло не так :(\n";
		return -1;
	}

	asm(
		"mov	%[n],	%%rcx			\n\t" //сдвиг в rcx
		"mov	$1,	%%rdx 			\n\t" //1 в rdx
		"mov	%[n_arr], %%rbx 		\n\t" //указатель на начала массива в rbx
		"inc	%%rcx				\n\t" //увел. на 1

		"start: 				\n\t"
			"mov	$10,	%%rax		\n\t" //добавления в rax 10 число

		"less:					\n\t"
			"push	(%%rbx)			\n\t" //кладем в стэк значение массива
			"add	$8,	%%rbx		\n\t" //переход к след. элем. массива
			"push	(%%rbx)			\n\t" //кладем в стек
			"add	$-8,	%%rbx		\n\t" //возращаемся на предвед. эле. масс>

			"pop	(%%rbx)			\n\t" //вытаскиваем из стека
			"add	$8,	%%rbx		\n\t" //переход след. элем. массива

			"pop	(%%rbx)			\n\t" //вытаскиваем элем. массива
			"dec	%%rax			\n\t" //уменьшаем на 1 элем. массива
			"cmp	%%rax,	%%rdx		\n\t" //сравниваем

			"jne	less			\n\t" //переход в less, если не равны
			"dec	%%rcx			\n\t" //уменьшаем на 1,
			"add	$-72,	%%rbx		\n\t" //возращаемся к адресу 1 элем. масс>
			"cmp	%%rcx,	%%rdx 		\n\t" //сравниваем

			"jne	start			\n\t" //если плохо, то в лоп стар
		"end_asm: 				\n\t"
		:
		: [n_arr]"m"(n_arr),
		  [n]"m"(n)
		: "%rax", "%rbx", "%rcx", "%rdx"
	);

	cout << endl << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "Получается что" << endl;

	for (int i = 0; i < x; i++){
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}
