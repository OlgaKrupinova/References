 #include <iostream>

template <typename T>
void pswap(T* pointer1, T* pointer2) {
	T tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}


template <typename T>
void rswap(T& ref1, T& ref2) {
	T tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

void foo(int& var1, int& var2);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	

	//Нейтральные указатели
	int* p1 = 0;//создание указателя направленного на область нейтральной памяти из 
	// синтаксиса языка С. 0 это не число, а область памяти
	if (p1 != 0)
		std::cout << p1 << std::endl;
	else
		std::cout << "Указатель не инициализирован\n";

	//int* p1 = &n;//указатель направлен на адрес n

	int* p2 = NULL;//С язык программирования
	if (p2 != NULL)
		std::cout << p2 << std::endl;
	else
		std::cout << "Указатель не инициализирован\n";


	int* p3 = nullptr;//создание указателя направленного на область нейтральной памяти из 
	// синтаксиса языка С. 0 это не число, а область памяти
	if (p3 != nullptr)
		std::cout << p3 << std::endl;
	else
		std::cout << "Указатель не инициализирован\n";

	//Модификации указателей
	//Указатель на константу
	const int* pointer1;
	pointer1 = &n;
	//*pointer1 = 5;//ОШИБКА
	std::cout << *pointer1 << std::endl;

	//Константный указатель или указатель-константа
	int* const pointer2 = &n;
	//pointer2 = &m;//ОШИБКА!
	*pointer2 = 5;
	std::cout << *pointer2 << std::endl;

	//Константный указатель на константу
	const int* const pointer3 = &m;
	//pointer3 = &n;// ОШИБКА
	//*pointer3 = 42;// ОШИБКА
	std::cout << *pointer3 << std::endl;

	//Ссылки на переменные
	int& refn = n;//ссылка, ассоциированная с переменной n
	std::cout << "n = " << n << std::endl;
	std::cout << "refn =  " << refn << std::endl;

	n = 15;
	std::cout << "refn =  " << refn << std::endl;//ссылка меняется вместе с 
	//переменной n

	//Ссылки и функции
	n = 7; m = 15;
	std::cout << n << ' ' << m << std::endl;
	//pswap(&n, &m);//работает, но не удобно
	rswap(n, m);
	std::cout << n << ' ' << m << std::endl;

	//Задача 1 создайте функцию, которая принимает две переменные, если первая 
	// переменная больше, то они обе возводятся в квадрат, если нет то переменные
	//обнуляются

	std::cout << "Задача 1.\nВведите два числа -> ";
	std::cin >> n >> m;
	foo(n, m);
	std::cout << "n = " << n << "; m = " << m << "\n\n";

	return 0;
}


void foo(int& var1, int& var2) {
	if (var1 > var2) {
		var1 *= var1;
		var2 *= var2;
		return;
	}
	var1 = 0;
	var2 = 0;
}