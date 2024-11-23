//Bai thuc hanh de qui
#include <iostream>
using namespace std;

//Tinh tong
int tinhTong(int n, int sum=0) {
	//Basic case
	if (n == 0)
		return sum;

	//General case
	return tinhTong(n - 1, sum + n);
}

//Tinh tong binh phuong
int tinhTongBP(int n, int sum = 0) {
	if (n == 0)
		return sum;

	return tinhTongBP(n - 1, sum + n*n);
}

//Tinh tong le
double tinhTongLe(int n, double sum = 0.0) {
	if (n < 0)
		return sum;
	return tinhTongLe(n - 2, sum + 1.0 / n);
}

//Tinh giai thua 
int tinhGiaiThua(int n, int res = 1) {
	//Basic case
	if (n == 1)
		return res;
	//General case
	return tinhGiaiThua(n - 1, res*n);
}

//Tinh tong giai thua
int tinhTongGT(int n, int sum = 0) {
	if (n == 0)
		return sum;

	return tinhTongGT(n - 1, sum + tinhGiaiThua(n));
}

//Tinh so fibo thu n: 0 1 1 2 3 5... (Nhi phan)
int fibo(int n) {
	//Basic case
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	//General case
	return fibo(n - 1) + fibo(n - 2);
}

//Tinh luy thua x^n
double tinhLuyThua(int x, int n) {
	if (n == 0)
		return 1;
	if (n > 0)
		return x*tinhLuyThua(x, n - 1);
	else {
		if (x == 0)
			return -1;//Loi chia cho so 0
		return 1.0 / tinhLuyThua(x, -n);
	}	
}

//Dem chu so
int demChuSo(int n, int dem = 0) {
	if (n == 0)
		return dem;

	return demChuSo(n / 10, dem+1);
}

//Tinh tong chu so chan
int tinhTongCSChan(int n, int sum = 0) {
	if (n == 0)
		return sum;
	int chuSo = n % 10;
	if (chuSo % 2 == 0)
		return tinhTongCSChan(n / 10, sum + chuSo);
	else
		return tinhTongCSChan(n / 10, sum);
}

//Tinh so dao nguoc
int tinhSDN(int n, int sdn = 0) {
	if (n == 0)
		return sdn;

	return tinhSDN(n / 10, sdn * 10 + n % 10);
}

//Tim uoc chung lon nhat
int timUCLN(int a, int b) {
	if (a == b)
		return a;

	if (a > b)
		return timUCLN(a - b, b);
	else
		return timUCLN(a, b - a);
}

//Tinh tong phan tu tren mang 1 chieu
int tinhTongArr(int a[], int left, int right, int sum = 0) {
	if (left > right)
		return sum;

	return tinhTongArr(a, left + 1, right, sum + a[left]);
}

//Tim max tren mang 1 chieu
int timMax(int a[], int left, int right) {
	if (left == right)
		return a[left];

	int max = timMax(a, left + 1, right);
	if (a[left] > max)
		return a[left];
	else
		return max;
}

//Tam giac Pascal (Nhi Phan)
int tinhTGPascal(int i, int j) {
	if (j == 0 || i == j)
		return 1;

	return tinhTGPascal(i - 1, j - 1) + tinhTGPascal(i - 1, j);
}

int main() {
	/*int a[] = { 4,2,3,6,7 };
	int n = sizeof(a)/sizeof(a[0]);*/

	/*cout << "Nhap n: ";
	cin >> n;*/
	
	/*int tong = tinhTong(n);*/

	/*cout << "Tong la: " << tong << endl;*/

	/*cout << "Tong binh phuong: " << tinhTongBP(n) << endl;

	cout << "Tong le: " << tinhTongLe(n) << endl;*/

	//cout << "Tinh tong giai thua: " << tinhTongGT(n) << endl;

	/*cout << "Fibo: " << fibo(n) << endl;*/

	/*cout << "Luy thua: " << tinhLuyThua(2, -2) << endl;*/

	//cout << "So chu so " << n << " la: " << demChuSo(n) << endl;

	//cout << "Tong chu so chan: " << tinhTongCSChan(n) << endl;

	/*cout << "So dao nguoc: " << tinhSDN(n) << endl;*/

	/*cout << "UCLN: " << timUCLN(9, 6) << endl;*/
	
	/*cout << "Tong array: " << tinhTongArr(a, 0, n-1) << endl;*/

	/*cout << "Max array: " << timMax(a, 0, n - 1) << endl;*/

	int h = 5;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++)
			cout << tinhTGPascal(i,j) << " ";
		cout << endl;
	}

	return 1;
}