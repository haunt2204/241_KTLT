#include <iostream>
using namespace std;
#define MAX 20

//Nhap mang 1 chieu
void nhapMang(int a[MAX], int &n) {
	do {
		cout << "Nhap n = ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap lai!\n";
	} while (n <= 0 || n > MAX);

	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}

//Xuat mang 1 chieu
void xuatMang(int a[MAX], const int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Cac thao tac tren mang 1 chieu
int calArr(int a[MAX], const int n, bool func(int)) {
	int tong = 0;

	for (int i = 0; i < n; i++) {
		if(func(a[i]))
			tong+=a[i];
	}

	return tong;
}

//Kiem tra so duong
bool isDuong(const int x) {
	return x >= 0;
}
//Kiem tra so am
bool isAm(const int x) {
	return x < 0;
}
//Kiem tra so chan
bool isChan(const int x) {
	return x % 2 == 0;
}
//Kiem tra so le
bool isLe(const int x) {
	return x % 2 == 0;
}
//Kiem tra so nguyen to
bool isNguyenTo(const int x) {
	if (x < 2)
		return false;
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	for (int i = 2; i <= sqrt(x*1.0); i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}
//Kiem tra so chinh phuong
bool isChinhPhuong(const int x) {
	/*int i = 1;
	while (i*i <= x) {
		if (i*i == x)
			return true;
		i++;
	}
	return false;*/

	int tam = sqrt(x*1.0);//4 ==> 2, 5 ==> 2

	return tam*tam == x;
}

int main() {
	int a[MAX], n;

	nhapMang(a, n);
	xuatMang(a, n);

	cout << "Tinh tong cac so duong: " << calArr(a, n, isDuong) << endl;
	cout << "Tinh tong cac so am: " << calArr(a, n, isAm) << endl;
	cout << "Tinh tong cac so nguyen to: " << calArr(a, n, isNguyenTo) << endl;
	cout << "Tinh tong cac so chinh phuong: " << calArr(a, n, isChinhPhuong) << endl;

	system("pause");
	return 1;
}