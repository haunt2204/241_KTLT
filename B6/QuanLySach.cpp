#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

struct Sach
{
	char maSach[5];
	string tenSach;
	char tenTacGia[50];
	double giaBan;
	int giamGia;//DVT: %
};

struct DSQS
{
	Sach *ds;
	int n;
};

void init(DSQS &l) {
	l.ds = NULL;
	l.n = 0;
}

void nhap1Sach(Sach &s) {
	cout << "======NHAP THONG TIN=====\n";
	cout << "Nhap ID: ";
	cin >> s.maSach;
	cout << "Nhap ten sach: ";
	cin >> s.tenSach;
	cout << "Nhap ten tac gia: ";
	cin >> s.tenTacGia;
	cout << "Nhap gia ban: ";
	cin >> s.giaBan;
	cout << "Nhap giam gia: ";
	cin >> s.giamGia;
}

void xuat1Sach(const Sach s) {
	cout << "======XUAT THONG TIN=====\n";
	cout << "Nhap ID: " << s.maSach << endl;
	cout << "Nhap ten sach: " << s.tenSach <<endl;
	cout << "Nhap ten tac gia: "<<s.tenTacGia << endl;
	cout << "Nhap gia ban: " << s.giaBan << endl;
	cout << "Nhap giam gia: " << s.giamGia << endl;
}

void pushBackArr(Sach *&a, int &n, const Sach x) {
	if (a == NULL) {
		n = 1;
		a = new Sach[n];
		a[0] = x;
	}
	else {
		Sach *aPrev = a;

		a = new Sach[n + 1];
		int j = 0;
		for (int i = 0; i < n; i++)
			a[j++] = aPrev[i];
		a[n++] = x;

		delete[]aPrev;
		aPrev = NULL;
	}
}

void nhapDsTuFile(DSQS &l) {
	ifstream inFile("Sach.txt");
	if (inFile.is_open()) {
		while (inFile.eof()==false) {
			Sach s;

			inFile.getline(s.maSach, 5, '#');
			getline(inFile, s.tenSach, '#');
			inFile.getline(s.tenTacGia, 50, '#');
			inFile >> s.giaBan;
			inFile.ignore();
			inFile >> s.giamGia;
			inFile.ignore();

			pushBackArr(l.ds, l.n, s);
		}
		inFile.close();
	}
}

void xuatDsSach(const DSQS l) {
	for (int i = 0; i < l.n; i++) {
		xuat1Sach(l.ds[i]);
	}
}

int cmpWithId(Sach s1, Sach s2) {
	return strcmp(s1.maSach, s2.maSach);
}

int cmpWithName(Sach s1, Sach s2) {
	return s1.tenSach.compare(s2.tenSach);
}

DSQS timKiem(const DSQS l, Sach key, int comparator(Sach, Sach)) {
	DSQS kq;
	init(kq);

	for (int i = 0; i < l.n; i++) {
		if (comparator(l.ds[i], key) == 0) {
			pushBackArr(kq.ds, kq.n, l.ds[i]);
		}
	}

	return kq;
}

Sach* timKiem(const DSQS l, char maSach[]) {
	for (int i = 0; i < l.n; i++) {
		if (strcmp(l.ds[i].maSach, maSach) == 0) {
			return &l.ds[i];
		}
	}

	return NULL;
}

void xuatHoaDon(DSQS cart, double total_amount) {
	ofstream outFile("HoaDon.txt");
	if (outFile.is_open()) {

		outFile << total_amount << endl;

		for (int i = 0; i < cart.n; i++) {
			outFile << cart.ds[i].maSach << "#";
			outFile << cart.ds[i].tenSach << "#";
			outFile << cart.ds[i].tenTacGia << "#";
			outFile << cart.ds[i].giaBan << "#";
			outFile << cart.ds[i].giamGia << "\n";
		}

		outFile.close();
	}
}

int main(){
	DSQS l;
	init(l);
	
	nhapDsTuFile(l);
	xuatDsSach(l);

	/*Sach key;
	strcpy(key.maSach, "S009");
	key.tenSach = "Dac Nhan Tam";

	DSQS kq = timKiem(l, key, cmpWithName);


	cout << "==============KET QUA TIM KIEM============\n";
	xuatDsSach(kq);*/

	cout << "==============THEM SACH VAO GIO HANG============\n";
	DSQS cart;
	init(cart);
	char id[5];
	int chon;

	double total_amount = 0.0;

	do {
		cout << "Nhap ma sach can them: ";
		cin >> id;
		Sach s = *timKiem(l, id);
		total_amount += (s.giaBan - s.giaBan*(s.giamGia / 100.0));
		pushBackArr(cart.ds, cart.n, s);
		cout << "Co muon them SP vao gio hang (1-Yes, 0-No-XUAT HOA DON): ";
		cin >> chon;
	} while (chon!=0);

	cout << "===========SAN PHAM TRONG GIO HANG=========\n";
	xuatDsSach(cart);
	xuatHoaDon(cart, total_amount);

	delete[]l.ds;
	delete[]cart.ds;
	/*delete[]kq.ds;*/
	return 1;
}