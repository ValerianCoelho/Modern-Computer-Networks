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

int find(string text, char ch) {
    for(int i=0; i < text.length(); i++) {
        if(text[i] == ch) {
            return i;
        }
    }
    return -1;
}

int main() {
    string data, gox;
    cout << "Receiver Side" << endl;
    cout << "Enter the Recieved Data : ";
    cin >> data;

    cout << "Enter the key : ";
    cin >> gox;

    string temp = data.substr(0, gox.length());
    int i = gox.length() - 1;
    while (i < data.length()) {
        temp = temp[0] == '1'
              ? XOR(temp, gox) // XOR temp and g(x)
              : temp.substr(1, temp.length()) + data[++i]; // remove fist leading zero and add one bit from data
    }
    if(find(temp, '1') == -1) {
        cout << "There is no Error in the Data Received";
    } else {
        cout << "There is an Error in the Data Received";
    }
    return 0;
}