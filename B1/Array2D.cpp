#include <iostream>
#include <ctime>
using namespace std;

#define MAXROW 50
#define MAXCOL 20


void nhapDongCot(int &r, int &c) {
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r > MAXROW || r <= 0 || c > MAXCOL || c <= 0)
			cout << "Nhap lai!\n";
	} while (r > MAXROW || r <= 0 || c > MAXCOL || c <= 0);
}

void nhapMang(int a[][MAXCOL], int &r, int &c) {
	nhapDongCot(r, c);
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void xuatMang(int a[][MAXCOL], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

//Sinh ma tran ngau nhien
void sinhMaTranNN(int a[][MAXCOL], int &r, int &c) {
	srand((int)time(NULL));

	nhapDongCot(r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand()%10 + 1;//1->100
		}
	}
}

//Tinh tong dong thu vt
int tinhTongDong(int a[][MAXCOL], const int r, const int c, const int vt) {
	int tong = 0;
	for (int j = 0; j < c; j++) {
		tong+=a[vt][j];
	}
	return tong;
}

//Sinh ma trang zigzag dong
void sinhMaTranZigzagDong(int a[][MAXCOL], int &r, int &c) {
	nhapDongCot(r, c);

	int dem = 1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i % 2 == 0)
				a[i][j] = dem++;
			else
				a[i][c - 1 - j] = dem++;
		}
	}
}

//Tinh tong, hieu 2 ma tran cung kich thuoc
void tinhMaTran(int a[][MAXCOL], int b[][MAXCOL],  
	int result[][MAXCOL], const int r, const int c, int phepTinh(int x, int y)) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result[i][j] = phepTinh(a[i][j], b[i][j]);
		}
	}
}

int phepCong(int a, int b) {
	return a + b;
}

int phepTru(int a, int b) {
	return a - b;
}

int main() {

	int a[MAXROW][MAXCOL], rA, cA;
	int b[MAXROW][MAXCOL], rB, cB;
	int result[MAXROW][MAXCOL], r, c;
	//Nhap mang
	//nhapMang(a, r, c);
	/*sinhMaTranZigzagDong(a, rA, cA);*/
	//Xuat mang
	sinhMaTranNN(a, rA, cA);
	cout << "Ma tran A: \n";
	xuatMang(a, rA, cA);

	sinhMaTranNN(b, rB, cB);
	cout << "Ma tran B: \n";
	xuatMang(b, rB, cB);

	if (rA == rB && cA == cB) {
		tinhMaTran(a, b, result, rA, cA, phepTru);
		r = rA;
		c = cA;
		cout << "Ma tran A-B: \n";
		xuatMang(result, r, c);
	}
	else
		cout << "2 ma tran khong cung kich thuoc!\n";
	

	/*for (int i = 0; i < r; i++) {
		cout << "Dong " << i << " = " << tinhTongDong(a, r,c, i) << endl;
	}*/

	system("pause");
	return 0;
}
