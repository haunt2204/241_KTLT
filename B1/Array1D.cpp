#include <iostream>
using namespace std;

#define MAX 20

//Nhap mang 1 chieu
void nhapMang(int a[MAX], int &n) {
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n > MAX || n <= 0)
			cout << "Nhap lai!\n";
	} while (n > MAX || n <= 0);

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
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
int calArr(int a[MAX], const int n, bool func(int x)) {
	int tong = 0;

	for (int i = 0; i < n; i++) {
		if(func(a[i]))
			tong += a[i];
	}

	return tong;
}
//Kiem tra so am
bool isAm(const int x) {
	/*if (x < 0)
		return true;
	return false;*/
	return x < 0 ? true : false;
}
//Kiem tra so duong
bool isDuong(const int x) {
	return x >= 0 ? true : false;
}
//Kiem tra so chan
bool isChan(const int x) {
	return x % 2 == 0 ? true : false;
}
//Kiem tra so le
bool isLe(const int x) {
	return x % 2 != 0 ? true : false;
}
//Kiem tra so nguyen to
bool isNguyenTo(const int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x*1.0); i++)
		if (x%i == 0)
			return false;
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

	int tam = sqrt(x*1.0);
	return tam*tam == x ? true : false;
}

int main() {
	int a[MAX], n;

	//Nhap mang 
	nhapMang(a, n);
	//Xuat mang
	xuatMang(a, n);
	//Tong so am
	cout << "Tong am: " << calArr(a, n, isAm) << endl;
	//Tong so duong
	cout << "Tong duong: " << calArr(a, n, isDuong) << endl;
	//Tong so nguyen to
	cout << "Tong nguyen to: " << calArr(a, n, isNguyenTo) << endl;
	//Tong so chinh phuong
	cout << "Tong chinh phuong: " << calArr(a, n, isChinhPhuong) << endl;

	return 1;
}