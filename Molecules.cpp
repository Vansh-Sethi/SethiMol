#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Atom {
    public:
        string element;
        float position[3];
        string nomenclature;

    Atom() {
        

    }
        
    Atom(string elementChar, float posX, float posY, float posZ, string nomenclatureIdentifier = "Backbone") {
        element = elementChar;
        position[0] = posX;
        position[1] = posY;
        position[2] = posZ;
        nomenclature = nomenclatureIdentifier;
    };    

    friend ostream &operator << (ostream &out, const Atom &c) {
        out << c.element << " " << c.position[0] << " " << c.position[1] << " " << c.position[2];
        return out;
    };
};



class AminoAcid {
    public:
        string aminoAcid;
        string type;
        map<string, Atom> sideChain;
        float psi;
        float phi;
        vector<float> chi;
        map<string,Atom> backbone;

    AminoAcid(string aminoAcidChar, map<string, Atom> givenBackbone, map<string, Atom>  givenSideChain) {
        aminoAcid = aminoAcidChar;
        backbone = givenBackbone;
        sideChain = givenSideChain;
    };


    float TorsionAngle(float p1[3], float p2[3], float p3[3], float p4[3]) {
        return 0.01;
    };


};

class Protein {
    vector<AminoAcid> residues;
    Protein(vector<AminoAcid> givenResidues) {
        residues = givenResidues;
    };
};


// Full Amino Acids

class Histidine: public AminoAcid {
    public:
        
}