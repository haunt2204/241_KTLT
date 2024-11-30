#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
using namespace std;


void delSpace(char *str) {
	int len = strlen(str);
	//Xoa khoang trang o dau
	while (isspace(str[0])) {
		for (int i = 0; i < len; i++) {
			str[i] = str[i + 1];
		}
		len--;
	}

	//Xoa khoang trang o cuoi
	while (isspace(str[len - 1])) {
		str[len - 1] = '\0';
		len--;
	}

	//Xoa khoang trang o giua
	for (int i = 0; i < len; i++) {
		if (isspace(str[i]) && isspace(str[i+1])) {
			for (int j = i; j < len; j++) {
				str[j] = str[j + 1];
			}
			i = i - 1;
		}
	}
}

char* delSpaceNew(char *str) {
	char *res = new char[strlen(str)];
	res[0] = '\0';
	char *token = strtok(str, " ");
	while (token != NULL) {
		strcat(res, token);
		token = strtok(NULL, " ");
		if(token!=NULL)
			strcat(res, " ");
	}
	return res;
}

void capital(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (i == 0 || isspace(str[i - 1])) {
			if (!isupper(str[i]))
				str[i] = toupper(str[i]);
		}
		else
			if (!islower(str[i]))
				str[i] = tolower(str[i]);
	}
}

int main() {
	//str = "  tRuong dAi    hOC   Mo     "
	char str[] = "  tRuong dAi    hOC   Mo     ";
	//delSpace(str);
	char *res = delSpaceNew(str);
	capital(res);
	cout << res << endl;

	delete[]res;
	return 1;
}