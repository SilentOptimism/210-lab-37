#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

int sum_ascii(string);
int sum_total();
void gen_hash_index();
void print();

// (keys) that are integers
// (values) that are std::lists
map<int, list<string>> hash_table;

// The key in the map is an int (THE HASH INDEX)
// The value in the map is an std::list containing our 12- char codes

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

    gen_hash_index();
    print();

    return 0;
}

void print(){



    map<int, list<string>>::iterator start = hash_table.begin();
    map<int, list<string>>::iterator end = hash_table.end();

    int count = 0;
    
    while(count <= 100){
        for(const string& value: (start->second)){
            cout <<"Entry: " << count <<  " key: " << (start->first) << " value: " << value << endl;
            count++;
        }
        start++;
    }


}

/// @brief It reads the codes from the file, Generates a hash index for each code, Inputs the code along with its hash index into the map
/// @return returns the total ascii
void gen_hash_index(){
    ifstream fin;
    fin.open("lab-37-data.txt");

    if(!fin){
        cout << "File opening error" << endl;
    }
    else{
        while (fin){
            int asciiSum = 0;
            string ascii;
            getline(fin, ascii);

            // Checks if there was a file error during pulling the ascii
            if(fin) {asciiSum = sum_ascii(ascii);}
            hash_table[asciiSum].push_back(ascii);
        }
        fin.close();
    }
}

int sum_ascii(string input){
    int sum = 0;

    for(char c: input){
        sum += c; // Implicitely converts char to int value and sums them
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
