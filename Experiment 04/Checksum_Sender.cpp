#include <iostream>
#include <string>
using namespace std;

int str_to_int(char num) {
    return num == '1' ? 1 : 0;
}

string compliment(string num) {
    string num_compliment = "";
    for(int i=0; i<num.length(); i++) {
        num_compliment = num[i] == '0' ? num_compliment + "1" : num_compliment + "0";
    }
    return num_compliment;
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
    int n;
    string data;
    cout << "Enter the Data : ";
    cin >> data;

    cout << "Enter the no of Segments : ";
    cin >> n;

    string segments[n+1];
    int segment_size = data.length() / n;
    for(int i=0; i<n; i++) {
        segments[i] = data.substr(i*segment_size, segment_size);
    }

    string sum = segments[0];
    for(int i=1; i<n; i++) {
        sum = binary_addition(sum, segments[i]);
    }
    string sum_compliment = compliment(sum);
    segments[n] = sum_compliment;

    for(int i=0; i<5; i++) {
        cout << segments[i] << " ";
    }
    return 0;
}

// 10110011 10101011 01011010 11010101
// 10110011101010110101101011010101