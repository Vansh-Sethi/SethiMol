#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Atom {
    public:
        string element;
        float position[3];
        string nomenclature;
    
    Atom(string elementChar, float posX, float posY, float posZ, string nomenclatureIdentifier = "Backbone") {
        element = elementChar;
        position[0] = posX;
        position[1] = posY;
        position[2] = posZ;
        nomenclature = nomenclatureIdentifier;
    };
         
};

struct AminoAcidBackbone {
    Atom n_nitrogen;
    Atom carbon;
    Atom carbon_alpha;
    Atom double_oxygen;
    Atom c_nitrogen;
};

class AminoAcid {
    public:
        char aminoAcid;
        string type;
        vector<Atom> sideChain;
        float psi;
        float phi;
        vector<float> chi;
        vector<Atom> backbone;

    AminoAcid(char aminoAcidChar, vector<Atom> givenBackbone, vector<Atom> givenSideChain) {
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
    }
}