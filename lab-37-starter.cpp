#include <iostream>
using namespace std;

int sum_ascii(string);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    cout << "sum: "<< sum_ascii("A") << endl;

    cout << endl;

    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    cout << "sum: "<< sum_ascii("B") << endl;

    cout << endl;

    cout << "AB" << endl;
    cout << "Sum: "<< sum_ascii("AB") << endl;
    

    return 0;
}

int sum_ascii(string input){
    int sum = 0;

    for(char c: input){
        sum += c;

    }

    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
