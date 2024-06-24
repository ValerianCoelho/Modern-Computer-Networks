#include <iostream>
#include <string>
using namespace std;

string XOR(string num1, string num2) {
    string result = "";
    for (int i = 0; i < num1.length(); i++) {
        result += num1[i] == num2[i] ? '0' : '1';
    }
    return result;
}

int main() {
    string data, gox;
    cout << "Sender Side" << endl;
    cout << "Enter the data : ";
    cin >> data;

    cout << "Enter the key : ";
    cin >> gox;

    for (int i = 0; i < gox.length() - 1; i++) {
        data += '0';
    }

    string temp = data.substr(0, gox.length());
    int i = gox.length() - 1;
    while (i < data.length()) {
        temp = temp[0] == '1'
              ? XOR(temp, gox) // XOR temp and g(x)
              : temp.substr(1, temp.length()) + data[++i]; // remove fist leading zero and add one bit from data
    }
    cout << "CRC : " << temp << endl;
    data = data.substr(0, data.length() - temp.length() + 1) + temp; // replace added zero bits with temp
    cout << "Code Word : " << data;
    return 0;
}