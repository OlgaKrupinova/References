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

	

	//����������� ���������
	int* p1 = 0;//�������� ��������� ������������� �� ������� ����������� ������ �� 
	// ���������� ����� �. 0 ��� �� �����, � ������� ������
	if (p1 != 0)
		std::cout << p1 << std::endl;
	else
		std::cout << "��������� �� ���������������\n";

	//int* p1 = &n;//��������� ��������� �� ����� n

	int* p2 = NULL;//� ���� ����������������
	if (p2 != NULL)
		std::cout << p2 << std::endl;
	else
		std::cout << "��������� �� ���������������\n";


	int* p3 = nullptr;//�������� ��������� ������������� �� ������� ����������� ������ �� 
	// ���������� ����� �. 0 ��� �� �����, � ������� ������
	if (p3 != nullptr)
		std::cout << p3 << std::endl;
	else
		std::cout << "��������� �� ���������������\n";

	//����������� ����������
	//��������� �� ���������
	const int* pointer1;
	pointer1 = &n;
	//*pointer1 = 5;//������
	std::cout << *pointer1 << std::endl;

	//����������� ��������� ��� ���������-���������
	int* const pointer2 = &n;
	//pointer2 = &m;//������!
	*pointer2 = 5;
	std::cout << *pointer2 << std::endl;

	//����������� ��������� �� ���������
	const int* const pointer3 = &m;
	//pointer3 = &n;// ������
	//*pointer3 = 42;// ������
	std::cout << *pointer3 << std::endl;

	//������ �� ����������
	int& refn = n;//������, ��������������� � ���������� n
	std::cout << "n = " << n << std::endl;
	std::cout << "refn =  " << refn << std::endl;

	n = 15;
	std::cout << "refn =  " << refn << std::endl;//������ �������� ������ � 
	//���������� n

	//������ � �������
	n = 7; m = 15;
	std::cout << n << ' ' << m << std::endl;
	//pswap(&n, &m);//��������, �� �� ������
	rswap(n, m);
	std::cout << n << ' ' << m << std::endl;

	//������ 1 �������� �������, ������� ��������� ��� ����������, ���� ������ 
	// ���������� ������, �� ��� ��� ���������� � �������, ���� ��� �� ����������
	//����������

	std::cout << "������ 1.\n������� ��� ����� -> ";
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