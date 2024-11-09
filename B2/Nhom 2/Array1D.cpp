//Thao tac tren mang 1 chieu (cap phat dong)
#include <iostream>
#include <ctime>
using namespace std;
#define MAX 50

//Nhap so luong phan tu
void inputNumElm(int &n) {
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n < 1 || n > MAX)
			cout << "Nhap lai n!\n";
	} while (n < 1 || n > MAX);
}

//Nhap mang 1 chieu (cap phat dong)
void inputArr(int *&a, int &n) {
	inputNumElm(n);
	//Xin cap phat vung nho cho mang a
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//Xuat mang 1 chieu
void outputArr(int *a, int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
}

//Tim va tra ve dia chi cua phan tu lon nhat trong mang
int* findMax(int *a, int n) {
	if (a != NULL) {
		int viTriMax = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[viTriMax])
				viTriMax = i;
		}

		return &a[viTriMax];
	}
	return NULL;
}

//Sinh mang ngau nhien
void randArr(int *&a, int &n) {
	inputNumElm(n);
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand()%100 + 1; //tu 1 -> 100
	}
}

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

//Dao nguoc mang, chi su dung con tro
void reverse(int *a, int n) {
	if (a != NULL) {
		int *i = &a[0];
		int *j = &a[n - 1];
		while (i <= j) {
			swap(*i++, *j--);
		}
	}
}

//Noi mang
int* concateArr(int *a, int n, int *b, int m) {
	if (a != NULL && b != NULL) {
		int *c = new int[n + m];
		//Xu ly
		int i = 0, j = 0, k = 0;
		//Doi cac phan tu cua a sang c
		while (i < n) {
			c[k++] = a[i++];
		}
		//Doi cac phan tu cua b sang c
		while (j < m) {
			c[k++] = b[j++];
		}

		return c;
	}
}

//Ham them tung phan tu vao mang
void pushBackArr(int *&a, int &n, int x) {
	if (a == NULL) {
		n = 1;
		a = new int[n];
		a[0] = x;
	}
	else {
		int *aPrev = a;
		a = new int[n + 1];
		//Doi cac phan tu o mang cu sang mang moi
		for (int i = 0; i < n; i++) {
			a[i] = aPrev[i];
		}
		//Dua phan tu x vao mang a
		a[n] = x;
		//Tang kich thuoc cua mang len 1 don vi
		n = n + 1;

		delete[]aPrev;
	}
}

//Sap xep mang
void sortArr(int *a, int n) {
	if (a != NULL) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j])
					swap(a[i], a[j]);
			}
		}
	}
}

int main() {
	//Khai bao 
	int *a = NULL, n;
	/*int *b = NULL, m;
	int *c = NULL, l;*/
	//Xin cap phat vung nho
	//inputArr(a, n);
	/*srand((int)time(NULL));
	cout << "Mang a:\n";
	randArr(a, n);
	cout << "Mang b:\n";
	randArr(b, m);*/
	int x, chon;
	cout << "Nhap x = ";
	while (cin >> x) {
		pushBackArr(a, n, x);
		cout << "Nhap x = ";
	}

	/*do {
		cout << "Nhap x = ";
		cin >> x;
		pushBackArr(a, n, x);
		cout << "Nhap tiep khong (0-No/1-Yes): "; cin >> chon;
	} while (chon!=0);*/
	
	//Thao tac 
	cout << "Mang a:\n";
	outputArr(a, n);
	cout << "=========MANG DA SAP XEP=========\n";
	sortArr(a, n);
	outputArr(a, n);
	/*cout << "Mang b:\n";
	outputArr(b, m);*/
	/*cout << *findMax(a, n) << endl;*/

	/*cout << "=========MANG DAO NGUOC=========\n";
	reverse(a, n);
	outputArr(a, n);*/
	//Gop mang
	//cout << "=========GOP MANG=========\n";
	//l = n + m;
	//c = concateArr(a, n, b, m);//Mang ket qua
	//outputArr(c, l);

	//Giai phong vung nho
	delete[]a;
	//delete[]b;
	//delete[]c;
	return 1;
}