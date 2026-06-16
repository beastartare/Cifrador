#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Cifrador
{
private:
    vector<unsigned char> m_ascii;
    vector< pair<unsigned char, unsigned char> > m_encodingTable;
public:
    Cifrador();
    string Encode(string input);
    string Decode(string input);
    string ToString();
};

int menu();
string TextFile(string filepath);
