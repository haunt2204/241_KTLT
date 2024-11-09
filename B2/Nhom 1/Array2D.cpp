//Chua biet truoc r, c
#include <iostream>
using namespace std;

#define MAX 50

void nhapMang(int **&a, int &r, int &c) {
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r <= 0 || c <= 0 || r > MAX || c > MAX)
			cout << "Nhap lai!\n";
	} while (r <= 0 || c <= 0 || r > MAX || c > MAX);

	//Cap phat theo so dong
	a = new int*[r];

	//Cap phat theo so cot
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}

	//Thao tac nhap phan tu 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
			//cin >> *(*(a+i)+j); //Ky phap do doi tren mang duoc cap phat dong
		}
	}
}

void xuatMang(int **a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << (long) &a[i][j] << "\t";
		}
		cout << endl;
	}
}


int main() {
	//Khai bao
	int **a = NULL, r, c;

	//Cap phat
	nhapMang(a, r, c);
	xuatMang(a, r, c);

	cout << "Dia chi: " << a << endl;
	//Thao tac

	//Giai phong
	for (int i = 0; i < r; i++) {
		delete[]a[i];
	}

	delete[]a;

	return 1;
}