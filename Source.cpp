#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define chui(ch) (unsigned int)ch // для возвращения символов в числы

	// Задача 1
string tobinary(char num);
string tobinary(short num);
string tobinary(int num);
// Задача 2
int tohex(string bin);

int main() {
	setlocale(LC_ALL, "Russian");
	
	unsigned char n, m;
	unsigned char result;
	//Битовые сдвиги
	/* // Налево
	n = 34;    // 00100010
	//n <<= 2; // 10010000 = 136
	cout << chui(n) << endl;
	 // Направо
	n = 200; // 11001000
	n >>= 4; // 00011000 = 12
	cout << chui(n) << endl;*/

	//Дополнение(инверсия)
	/*n = 4;   // 00000100
	n = ~n;  // 11111011 = 251
	cout << chui(n) << endl;
	unsigned int X = 10;
	X = ~X;
	cout << X << endl;*/

	//Битовое И
	/*n = 17;         // 00010001 
	m = 205;        // 11001101 
	result = n & m; // 00000001 - 1
	cout << chui(result) << endl;*/

	//Битовое ИЛИ
	/*n = 152;      // 10011000
	m = 43;         // 00101011
	result = n | m; // 10111011 = 187
	cout << chui(result) << endl;*/

	//Исключащее ИЛИ
	/*n = 154;        // 10011010
	m = 43;         // 00101011
	result = n ^ m; // 10110001 = 177
	cout << chui(result) << endl;*/

	// Задача 1
	/*char z1ch = 77;    // 1001101
	short z1sh = 1555; // 11000010011
	int z1i = 88000;   // 10101011111000000
	cout << chui(z1ch) << " = " << tobinary(z1ch) << endl;
	cout << z1sh << " = " << tobinary(z1sh) << endl;
	cout << z1i << " = " << tobinary(z1i) << endl;*/

	// Задача 2
	try {
		cout << "Задача 1.\nВведите двоичный код:\n";
		string bin;
		cin >> bin;
		cout << bin << " = " << tohex(bin) << "\n\n";
	}
	catch(const invalid_argument &ex ) {
		cout << "Ошибка: " << ex.what() << endl;
	}

	return 0;
}
// Задача 1
string tobinary(char num) {
	string res;
	for (int i = 7; i >= 0; i--) {
		int X = (num >> i) & 1;
		res += to_string(X);
	}
	return res;
}
string tobinary(short num) {
	string res;
	for (int i = 15; i >= 0; i--)
	{
		int X = (num >> i) & 1;
		res += to_string(X);
	}
	return res;
}
string tobinary(int num) {
	string res;
	for (int i = 31; i >= 0; i--)
	{
		int X = (num >> i) & 1;
		res += to_string(X);
	}
	return res;

}
// Задача 2
int tohex(string bin) {
	int res = 0;
	for (int i = bin.length() - 1; i >= 0; i--) {
		if (bin[i] != '0' && bin[i] != '1')
			throw invalid_argument("not binary");

		int tmp = bin[i] - '0';
		tmp = tmp * pow(2, bin.length() - i - 1);
		res += tmp;
	}
	return res;
}