#include <iostream>
#include <fstream>

using namespace std;

int sum_ascii(string);
int sum_total();

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
    cout << "65+66 = 131" << endl;
    cout << "Sum: "<< sum_ascii("AB") << endl;

    cout << endl;

    cout << "ABCDEFG" << endl;
    cout << "Sum: "<< sum_ascii("ABCDEFG") << endl;

    cout << endl;

    cout << "The sum of all ASCII values in the entire file" << endl;
    cout << sum_total() << endl;
    

    return 0;
}

int gen_hash_index(){

}

int sum_ascii(string input){
    int sum = 0;

    for(char c: input){
        sum += c; // Implicitely converts char to int value and sums them
    }

    return sum;
}

int sum_total(){
    ifstream fin;
    fin.open("lab-37-data.txt");

    if(!fin){
        cout << "File opening error" << endl;
        return -1;
    }

    int total = 0;

    while (fin){
        string ascii;
        getline(fin, ascii);

        // Checks if there was a file error during pulling the ascii
        if(fin)  {total += sum_ascii(ascii);}
    }

    return total;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
