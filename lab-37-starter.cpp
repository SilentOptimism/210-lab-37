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


    gen_hash_index();
    menu();

    return 0;
}

void menu(){
    bool exit = false;

    while(!exit){
        char input;

        cout << "Hash Table 2" << endl;
        cout << endl;
        cout << "1) Print first 100 entries" << endl;
        cout << "2) Search for a key" << endl;
        cout << "3) Add a key" << endl;
        cout << "4) Remove a key" << endl;
        cout << "5) Modify a key" << endl;
        cout << "6) Exit" << endl;
        cout << endl;
        cout << "Input (1-6) for a valid choice: ";
        cin >> input;

        switch (input)
        {
        case '1':
            print();
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            /* code */
            break;
        case '5':
            /* code */
            break;
        case '6':
            exit = true;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}

void addKey(){
    string value;
    cout << "Input Key to add:";
    cin >> value;

    int valueSum = sum_ascii(value);


}

/// @brief Prints first 100 entries
void print(){
    map<int, list<string>>::iterator start = hash_table.begin();
    map<int, list<string>>::iterator end = hash_table.end();

    int count = 0;
    
    while(count <= 100){
        for(const string& value: (start->second)){
            cout << "key: " << (start->first) << " value: " << value << endl;
        }
        start++;
        count++;
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
    fin.close();

    return total;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
