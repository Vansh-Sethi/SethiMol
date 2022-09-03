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


void PDBFileParser(string pdb) {
    string line;
    ifstream file ("PDBFiles/" + pdb);

    vector<vector<string>> Protein_Information;

    while (getline(file, line)) {
        vector<string> line_info = split(line);
        if (line_info[0] == "ATOM") {
            Protein_Information.push_back(line_info);
        }
        if (line_info[0] == "MODEL" && line_info[1] == "2") {
            file.close();
        }
    }

    for (int i = 0; i < Protein_Information.size(); i++) {
        for (int j = 0; j < Protein_Information[i].size(); j++) {
            cout << Protein_Information[i][j] << " ";
        }
        cout << endl;
    }

   

    // Backbone Parser
    vector<AminoAcid> residues;

    int residue = 1;
    ResidueBackbone currentResidue;
    string currentAminoAcid;
    for (int i = 0; i < Protein_Information.size(); i++) {
        string currentAtom = Protein_Information[i][2];
        if (Protein_Information[i][2] == "N" && stoi(Protein_Information[i][5]) == residue) {
            // Set N terminal Nitrogen
            Atom N_Termnal_Nitrogen = Atom(Protein_Information[i][11], stof(Protein_Information[i][6]), stof(Protein_Information[i][7]), stof(Protein_Information[i][8]));
            currentResidue.N = N_Termnal_Nitrogen;
            currentAminoAcid = Protein_Information[i][3];

        }
        if (Protein_Information[i][2] == "N" && stoi(Protein_Information[i][5]) == residue+1) {
            residue++;
            // Set C terminal Nitrogen and create amino acid
            Atom C_Termnal_Nitrogen = Atom(Protein_Information[i][11], stof(Protein_Information[i][6]), stof(Protein_Information[i][7]), stof(Protein_Information[i][8]));
            currentResidue.NC = C_Termnal_Nitrogen;
            AminoAcid newResidue = AminoAcid(currentAminoAcid, currentResidue, currentResidue);
            residues.push_back(newResidue);

            Atom N_Termnal_Nitrogen = Atom(Protein_Information[i][11], stof(Protein_Information[i][6]), stof(Protein_Information[i][7]), stof(Protein_Information[i][8]));
            currentResidue.N = N_Termnal_Nitrogen;
            currentAminoAcid = Protein_Information[i][3];

        } 
        else {
            try {
            Atom BackboneAtom = Atom(Protein_Information[i][11], stof(Protein_Information[i][6]), stof(Protein_Information[i][7]), stof(Protein_Information[i][8]));
             currentResidue[currentAtom] = BackboneAtom;   
            }
            catch(const std::exception& e)
            {
                cout << "ad";
            }
            
        }
        
    }

    for (int i = 0; i < residues.size(); i++) {
        cout << residues[i].backbone.C.position[0] << endl;
    }
    
    
}


int main() {
    PDBFileParser("1yybFull.pdb");




    
}