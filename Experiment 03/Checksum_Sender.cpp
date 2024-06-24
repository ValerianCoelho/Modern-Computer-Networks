#include <iostream>
#include <string>
using namespace std;

// Function to convert a character representing a binary digit to an integer
int str_to_int(char num) {
    return num == '1' ? 1 : 0;
}

// Function to compute the 1's complement of a binary number
string compliment(string num) {
    string num_compliment = "";
    for(int i=0; i<num.length(); i++) {
        num_compliment = num[i] == '0' ? num_compliment + "1" : num_compliment + "0";
    }
    return num_compliment;
}

// Function to perform binary addition of two binary numbers
string binary_addition(string num1, string num2) {
    int intsum, bitsum, carry = 0;
    string sum = "";
    for(int i=num1.length()-1; i>=0; i--) {
        intsum = str_to_int(num1[i]) + str_to_int(num2[i]) + carry;
        bitsum = intsum == 1 || intsum == 3 ? 1 : 0;
        carry = intsum == 2 || intsum == 3 ? 1 : 0;
        sum = to_string(bitsum) + sum;

        if(i==0 && carry == 1) {
            // Handling carry for the most significant bit
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
    int segment_size;
    string data;
    cout << "Enter the Data : ";
    cin >> data;

    cout << "Enter the segment size : ";
    cin >> segment_size;

    // Split the data into segments
    int n = data.length() / segment_size;
    string segments[n+1];
    for(int i=0; i<n; i++) {
        segments[i] = data.substr(i*segment_size, segment_size);
    }

    // Perform binary addition on all the segments to calculate checksum
    string sum = segments[0];
    for(int i=1; i<n; i++) {
        sum = binary_addition(sum, segments[i]);
    }

    cout << "Sum : " << sum << endl;

    // Calculate 1's complement of the sum to get the checksum
    string sum_compliment = compliment(sum);
    segments[n] = sum_compliment;

    cout << "checksum : " << sum_compliment << endl;

    // Output the segments including the checksum
    cout << "codeword : " ;
    for(int i=0; i<n+1; i++) {
        cout << segments[i] << " ";
    }
    return 0;
}

// 10110011 10101011 01011010 11010101
// 10110011101010110101101011010101