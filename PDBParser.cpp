#include <iostream>
#include <fstream>
#include <vector>
#include "Molecules.cpp"
using namespace std;

vector<string> split(string y) {
    vector<string> o;
    vector<string> output;
    int left, right = 0;
    for (int i = 0; i < y.length(); i++) {
        if (y[i] == ' ') {
            o.push_back(string(&y[left], &y[right]));
            left = i+1;
            right = i+1;

        }
        else {
            right++;
        }
    }
    for (int i = 0; i < o.size(); i++) {
        if (!o[i].empty()) {
            output.push_back(o[i]);
        }
    }

    return output;
};



int main() {
    string line;
    ifstream file ("PDBFiles/1yyb.pdb");
    getline(file, line);
    file.close();


    vector<string> stuff = split(line);
    for (int i = 0; i < stuff.size(); i++) {
        cout << stuff[i] << endl;
    }




    
}