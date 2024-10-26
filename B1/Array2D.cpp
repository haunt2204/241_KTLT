#include <iostream>
#include <ctime>
using namespace std;

#define MAXROW 50
#define MAXCOL 20

//Nhap dong cot 
void nhapDongCot(int &r, int &c) {
	do {
		cout << "Nhap so dong: "; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r <= 0 || c <= 0 || r > MAXROW || c > MAXCOL)
			cout << "Nhap lai dong, cot!\n";
	} while (r <= 0 || c <= 0 || r > MAXROW || c > MAXCOL);
}

//Nhap mang 2 chieu
void nhapMang(int a[][MAXCOL], int &r, int &c) {
	nhapDongCot(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

//Xuat mang 2 chieu
void xuatMang(int a[][MAXCOL], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

//Sinh ma tran ngau nhieu
void sinhMaTranNN(int a[][MAXCOL], int &r, int &c) {
	nhapDongCot(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}
}


//Cac thao tac tren mang 2 chieu:
//Thao tac tren dong
int tinhTongDong(int a[][MAXCOL], const int r, const int c, const int vtDong) {
	int tong = 0;
	for (int j = 0; j < c; j++) {
		tong += a[vtDong][j];
	}
	return tong;
}
//Thao tren cot
int tinhTongCot(int a[][MAXCOL], const int r, const int c, const int vtCot) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		tong += a[i][vtCot];
	}
	return tong;
}

//Ma tran zigzag dong
void sinhMaTranZigzagDong(int a[][MAXCOL], int &r, int &c) {
	nhapDongCot(r, c);
	int dem = 1;
	for (int i = 0; i < r; i++) {
		/*if (i % 2 == 0) {
			for (int j = 0; j < c; j++) {
				a[i][j] = dem++;
			}
		}else
			for (int j = c-1; j >= 0; j--) {
				a[i][j] = dem++;
			}*/
		for (int j = 0; j < c; j++) {
			if(i%2==0)
				a[i][j] = dem++;
			else
				a[i][c-1-j] = dem++;
		}
	}
}

//Ma tran xoan oc
void maTranXoanOc(int a[][MAXCOL], int &r, int &c) {
	nhapDongCot(r, c);
	int r1 = 0, r2 = r-1, c1 = 0, c2 = c-1;
	int dem = 1;
	while (dem <= r*c) {
		for (int j = c1; j <= c2; j++) {
			if(dem<=r*c)
				a[r1][j] = dem++;
		}
		r1++;

		for (int i = r1; i <= r2; i++) {
			if (dem <= r*c)
				a[i][c2] = dem++;
		}
		c2--;
		for (int j = c2; j >= c1; j--) {
			if (dem <= r*c)
				a[r2][j] = dem++;
		}
		r2--;

		for (int i = r2; i >= r1; i--) {
			if (dem <= r*c)
				a[i][c1] = dem++;
		}
		c1++;
	}
}

//Thao tac tren canh bien
int tinhTongBien(int a[][MAXCOL], int &r, int &c) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
				tong += a[i][j];
		}
	}
	return tong;
}

//Tinh tong, hieu 2 ma tran cung kich thuoc
void tinh2MaTran(int a[][MAXCOL], int b[][MAXCOL],
	int result[][MAXCOL], const int r, const int c, int phepTinh(int, int)) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result[i][j] = phepTinh(a[i][j], b[i][j]);
		}
	}
}

int phepCong(int x, int y) {
	return x + y;
}

int phepTru(int x, int y) {
	return x - y;
}

int main() {
	int a[MAXROW][MAXCOL], rA, cA;
	int b[MAXROW][MAXCOL], rB, cB;

	int result[MAXROW][MAXCOL], r, c;

	//nhapMang(a, r, c);
	//sinhMaTranNN(a, r, c);
	//maTranXoanOc(a, r, c);
	//xuatMang(a, r, c);

	/*for (int i = 0; i < r; i++) {
		cout << "Dong " << i + 1 << ": " << tinhTongDong(a, r, c, i) << endl;
	}*/

	srand((int)time(NULL));

	sinhMaTranNN(a, rA, cA);
	cout << "Ma tran A: \n";
	xuatMang(a, rA, cA);

	sinhMaTranNN(b, rB, cB);
	cout << "Ma tran B: \n";
	xuatMang(b, rB, cB);

	if (rA == rB&&cA == cB) {
		r = rA; c = cA;
		tinh2MaTran(a, b, result, r, c, phepTru);
		cout << "Ma tran ket qua A-B: \n";
		xuatMang(result, r, c);
	}
	else
		cout << "Khac kich thuoc!\n";

	return 1;
}