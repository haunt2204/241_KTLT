//Thao tac tren mang 1 chieu (cap phat dong)
#include <iostream>
#include <ctime>
using namespace std; 
#define MAX 100

//Nhap mang
void inputNumElm(int &n) {
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap sai, nhap lai!\n";
	} while (n <= 0 || n > MAX);
}

void inputArr(int *&a, int &n) {
	inputNumElm(n);
	a = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> *(a + i);
	}
}

//Xuat mang
void outputArr(int *a, int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << *(a + i) << "\t";
		}
		cout << endl;
	}
}

//Noi 2 mang
int* concateArr(int *a, int n, int *b, int m) {
	int *c = new int[n+m];
	int l = 0;
	for (int i = 0; i < n; i++)
		c[l++] = a[i];
	for (int k = 0; k < m; k++) {
		c[l++] = b[k];
	}
	return c;
}

//Hoan vi
void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

//Thao tac dao nguoc mang: 1 2 3 4 5 => 5 4 3 2 1
void reverseArr(int *a, int n) {
	int *l = a, *r = (a + n - 1);
	while (l<r) {
		swap(*l++, *r--);
	}
}

//Tim phan tu lon nhat trong mang
int* findMax(int *a, int n) {
	if (a != NULL) {
		int maxIndex = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[maxIndex])
				maxIndex = i;
		}
		return &a[maxIndex];
	}
	return NULL;
}

//Viet ham sinh mang ngau nhien
void randArr(int *&a, int &n) {
	inputNumElm(n);
	a = new int[n];
	for (int i = 0; i < n; i++) {
		*(a + i) = rand()%100+1;
	}
}

//Ham cho phep nguoi dung them tung phan tu vao mang
void pushBackArr(int *&a, int &n, const int x) {
	if (a == NULL) {
		n = 1;
		a = new int[n];
		a[0] = x;
	}else{
		int *aPrev = a;

		a = new int[n + 1];
		int j = 0;
		for (int i = 0; i < n; i++)
			a[j++] = aPrev[i];
		a[n++] = x;

		delete[]aPrev;
		aPrev = NULL;
	}
}

//Sap xep
void sortArr(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

int main(){
	//1. Khai bao
	int *a = NULL, n;
	int *b = NULL, m, *c = NULL, l;
	//2. Cap phat 
	/*inputArr(a, n);*/
	/*srand((int)time(NULL));
	randArr(a, n);*/
	/*inputArr(b, m);*/
	/*int chon;
	do {
		int x;
		cout << "Nhap gia tri can them: ";
		cin >> x;
		pushBackArr(a, n, x);
		cout << "Nhap tiep (0-N/1-Y): "; cin >> chon;
	} while (chon!=0);*/
	
	int x;
	cout << "Nhap x: ";
	while (cin >> x) {
		pushBackArr(a, n, x);
		cout << "Nhap x: ";
	}

	//3. Thao tac
	outputArr(a, n);
	cout << "======DS SAU KHI SAP XEP=====\n";
	sortArr(a, n);
	outputArr(a, n);

	//reverseArr(a, n);
	//cout << "======MANG DAO NGUOC=====\n";
	//outputArr(a, n);
	//cout << "======TIM PHAN TU LON NHAT=====\n";
	//cout << *findMax(a, n) << endl;

	//////Noi mang:
	//l = n + m;//So luong phan tu cua c
	//c = concateArr(a, n, b, m);
	//cout << "Mang sau khi gop: ";
	//outputArr(c, l);
	//4. Giai phong
	delete[]a;
	/*delete[]b;
	delete[]c;*/
	return 1;
}