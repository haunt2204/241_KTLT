//Thao tac tren mang 2 chieu (cap phat dong): chua biet truoc r va c
#include <iostream>
#include <ctime>
using namespace std;
#define MAX 50

void nhapMang(int **&a, int &r, int &c) {
	do {
		cout << "Nhap so dong: "; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r<1 || c <1 || r>MAX || c>MAX)
			cout << "Nhap lai: so dong, so cot!\n";
	} while (r<1 || c <1 || r>MAX || c>MAX);
	
	//Cap phat theo so dong
	a = new int*[r];

	//Cap phat theo so cot
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}

	//Nhap du lieu cho tung phan 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> *(*(a + i) + j);
		}
	}
}

void xuatMang(int **a, int r, int c) {
	if (a != NULL) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				/*cout << a[i][j] << "\t";*/
				cout << *(*(a+i)+j) << "\t";
			}
			cout << endl;
		}
	}
}

int main() {
	//Khai bao con tro cap 2 (mang 2 chieu)
	int **a, r, c;
	//Cap phat theo so dong + Cap theo so cot
	nhapMang(a, r, c);
	

	//Thao tac tren mang 2 chieu
	xuatMang(a, r, c);

	//Giai phong vung nho
	for (int i = 0; i < r; i++) {
		delete[]a[i];
	}
	delete[]a;
	return 1;
}