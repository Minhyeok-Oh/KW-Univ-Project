#include <iostream>
using namespace std;

char * my_strstr(char *str, char* strSearch, char* strChange);
int my_strlen(char* str); // for calculating str length

int main() 
{
	char str[100];
	memset(str, 0, 100);
	char strSearch[100];
	memset(strSearch, 0, 100);
	char strChange[100];
	memset(strChange, 0, 100);
	cout << "원본 문자열을 입력하세요." << endl;
	cin.getline(str, 100);
	if (!str) { // exception handling
		cout << "error" << endl;
		return 0;
	}
	cout << "변경 전 문자열을 입력하세요." << endl;
	cin.getline(strSearch, 100);
	if (!strSearch) { // exception handling
		cout << "error" << endl;
		return 0;
	}
	cout << "변경 후 문자열을 입력하세요." << endl;
	cin.getline(strChange, 100);
	if (!strChange) { // exception handling
		cout << "error" << endl;
		return 0;
	}
	
	cout << "변경 된 결과는 다음과 같습니다." << endl << endl;
	
	if (my_strstr(str, strSearch, strChange) == NULL) // exception handling
		return 0;
	
}
int my_strlen(char* str) 
{
	char* tmp = (char*)str;
	int i = 0;
	while (tmp[i]) {
		i++;
	}
	return i;
}

char* my_strstr(char* str, char* strSearch, char* strChange)
{
	char* CurrentPos = (char*)str;
	char * posS = NULL, * posO = NULL;
	char* tmp = NULL;
	char* tmp1;
	//str Search//
	int count = 0;
	while (*str!=NULL) {
		posS = str;
		posO = (char *)strSearch;
		while (*posS && *posO && !(*posS - *posO)) {
			posS++; // str position
			posO++; // strSearch position
		}
		if (*posO == NULL) {
			tmp = posS; // after strSearch
			break;
		}
		count++; // length before strSearch
		str++; // increase address
	}
	
	tmp1 = str; // address strSearch
	
	
	if (*tmp1 == NULL) {
		cout << "일치하는 문자열이 없습니다." << endl; // exception handling
		return NULL;
	}
	
	char result[100]; // result
	memset(result, 0, 100);
	int i = 0, j = 0;
	
	for (; i < count; i++) {
		result[i] = CurrentPos[i]; // input before strSearch to result
	}
	char* tmp3 = (char*)strChange; // strChange pointer
	
	int p = my_strlen(strChange); // strChange length
	int m = i; // position before strSearch to result
	for (int k = 0; k < p; k++) {
		result[i] = strChange[k]; // input strChange to result
		i++;
	}
	
	int o = my_strlen(tmp); // length of tmp
	
	for (int q = 0; q < o; q++) {
		result[i] = tmp[q];// input after strChange to result
		
		i++;
	}
	char* ret = &result[m]; // return address
	cout << "변경된 문자열:" << endl;
	cout << result << endl;
	return ret;
}