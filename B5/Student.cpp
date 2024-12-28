#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define SOMH 3

struct SinhVien {
	long long mssv;
	char hoTen[100];
	string queQuan;
	char ngaySinh[11];
	double diem[SOMH];
};


void pushBackArr(SinhVien *&a, int &n, const SinhVien x) {
	if (a == NULL) {
		n = 1;
		a = new SinhVien[n];
		a[0] = x;
	}
	else {
		SinhVien *aPrev = a;

		a = new SinhVien[n + 1];
		int j = 0;
		for (int i = 0; i < n; i++)
			a[j++] = aPrev[i];
		a[n++] = x;

		delete[]aPrev;
		aPrev = NULL;
	}
}

void xuat1Sv(SinhVien sv) {
	cout << "=============================\n";
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ho Ten: " << sv.hoTen << endl;
	cout << "Que quan: " << sv.queQuan << endl;
	cout << "Ngay Sinh: " << sv.ngaySinh << endl;
	cout << "Diem: ";
	for (int j = 0; j < SOMH; j++) {
		cout << sv.diem[j] << " ";
	}
	cout << "\n=============================\n";
}

void xuatDsSv(const SinhVien *dsSv, const int n) {
	if (dsSv != NULL) {
		for (int i = 0; i < n; i++) {
			xuat1Sv(dsSv[i]);
		}
	}
	else
		cout << "Danh sach rong!\n";
}

SinhVien* find(SinhVien *dsSv, const int n, const long long id) {
	SinhVien* res = NULL;

	for (int i = 0; i < n; i++) {
		if (dsSv[i].mssv == id) {
			res = &dsSv[i];
			break;
		}
	}

	return res;
}


int cmpWithIdAsc(const SinhVien sv1, const SinhVien sv2) {
	return sv1.mssv - sv2.mssv;
}

int cmpWithIdDesc(const SinhVien sv1, const SinhVien sv2) {
	return -(sv1.mssv - sv2.mssv);
}

int cmpWithAdressAsc(const SinhVien sv1, const SinhVien sv2) {
	return sv1.queQuan.compare(sv2.queQuan);
}

int cmpWithNameAsc(const SinhVien sv1, const SinhVien sv2) {
	return strcmp(sv1.hoTen, sv2.hoTen);
}

void sort(SinhVien *dsSv, int n, int comparator(SinhVien, SinhVien)) {
	for (int i = 0; i < n - 1; i++) {
		for(int j=i+1; j<n; j++)
			if (comparator(dsSv[j], dsSv[i])<0) {
				swap(dsSv[i], dsSv[j]);
			}
	}
}

int main() {
	ifstream inFile("data_sv.txt");
	SinhVien *dsSv = NULL;
	int n = 0;
	if (inFile.is_open()) {
		
		while (inFile.eof()==false) {
			SinhVien sv;
			inFile >> sv.mssv;
			inFile.ignore();
			inFile.getline(sv.hoTen, 100);
			getline(inFile, sv.queQuan);
			inFile.getline(sv.ngaySinh, 11);
			for (int i = 0; i < SOMH; i++) {
				inFile >> sv.diem[i];
			}
			pushBackArr(dsSv, n, sv);
		}

		inFile.close();
	}
	
	xuatDsSv(dsSv, n);

	/*cout << "==============TIM KIEM=================\n";
	SinhVien* res = find(dsSv, n, 2151010005);
	if (res != NULL)
		xuat1Sv(*res);
	else
		cout << "Khong tim thay!\n";*/

	cout << "==============SAP XEP=================\n";
	sort(dsSv, n, cmpWithNameAsc);
	xuatDsSv(dsSv, n);

	delete[]dsSv;
	return 0;
}