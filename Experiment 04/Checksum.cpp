#include <iostream>
#include <string>
using namespace std;

int str_to_int(char num) {
    return num == '1' ? 1 : 0;
}

string binary_addition(string num1, string num2) {
    int intsum, bitsum, carry = 0;
    string sum = "";
    for(int i=num1.length()-1; i>=0; i--) {
        intsum = str_to_int(num1[i]) + str_to_int(num2[i]) + carry;
        bitsum = intsum == 1 || intsum == 3 ? 1 : 0;
        carry = intsum == 2 || intsum == 3 ? 1 : 0;
        sum = to_string(bitsum) + sum;

        if(i==0 && carry == 1) {
            string strcarry = "1";
            for (int i = 0; i < num1.length() - 1; i++) {
                strcarry = "0" + strcarry;
            }
            sum = binary_addition(sum, strcarry);
        }
    }
    return sum;
}

int main() {
    cout << binary_addition("1011", "0111");
    return 0;
}