#include <iostream>
#include <string>
using namespace std;
//function f(x)
string f(string S) {
    string str;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '0')
            S[i] = '1';
        else
            S[i] = '0';
    }
    str = S;
    return str;
    
}
//function g(x)
string g(string S) {
    string str;
    char tmp;
    for (int i = 0; i < S.length() / 2; i++) {
        tmp = S[i];
        S[i] = S[S.length() - i-1];
        S[S.length() - i-1] = tmp;
    }

    str = S;
    return str;
}

unsigned int BintoDec(string S) { // convert binary to decimal
    unsigned int dec = 0;
    int pos = 0;
    int con = 0;
    if(S.length()>32)
        con = 31;
    else
        con = S.length() - 1;
    
    for (int i = con; i >= 0; i--) {
        if (S[i] == '1')
            dec += 1 << pos;

        pos++;
    }

    return dec;
}

int main()
{
    int n;
    string S;
    cout << "Input N:"; // input
    cin >> n;
    cout << "Input Bitstream:";
    cin >> S;
    if (n <= 0) { // exception handling
        cout << "error";
        return 0;
    }
    int len = S.length();
    
    for (int i = 0; i < len; i++) {
        if (S[i] != '0' && S[i] != '1') {
            cout << "invalid input"; // exception handling
            return 0;
        }
    }
    // n times
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            S = f(g(S)) + '1';
            cout << i << ":" << S << endl;
            cout << BintoDec(S) << endl;
        }
        else {
            S = f(g(S)) + '0';
            cout << i << ":" << S << endl;
            cout << BintoDec(S) << endl;
        }
    }


    

}