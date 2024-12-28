#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int *a, *p, n;
string *khachHang;
int *nhuCau, *khaNang;


void print() {
	ofstream outFile("ket_qua.txt", ios::app);

	if (outFile.is_open()) {
		for (int i = 0; i < n; i++) {
			outFile << khachHang[i] << "-" << a[i] << " ";
		}
		outFile << endl;
		outFile.close();
	}
}

void hoanVi(int i) {
	for (int j = 1; j <n+1; j++) {
		if (p[j] == -1 && nhuCau[i] <= khaNang[j-1]) {
			a[i] = j;
			p[j] = 1;
			if (i == n - 1) {
				print();
			}
			else
				hoanVi(i + 1);
			p[j] = -1;
		}
	}
}


int main() {
	ifstream inFile("data_net.txt");

	if (inFile.is_open()) {
		inFile >> n;

		a = new int[n];
		p = new int[n+1];
		khachHang = new string[n];
		nhuCau = new int[n];
		khaNang = new int[n];

		for (int i = 1; i < n+1; i++) {
			p[i] = -1;
		}

		for (int i = 0; i < n; i++) {
			inFile >> khachHang[i];
		}

		for (int i = 0; i < n; i++) {
			inFile >> nhuCau[i];
		}

		for (int i = 0; i < n; i++) {
			inFile >> khaNang[i];
		}

		hoanVi(0);

		delete[]a;
		delete[]p;
		delete[]khachHang;
		delete[]nhuCau;
		delete[]khaNang;
		inFile.close();
	}
	return 0;
}