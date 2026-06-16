#include "class.hpp"

int menu()
{
    int opcao;

    cout <<"1.Codificar um texto por importacao de arquivo" << endl;
    cout <<"2.Decodificar um texto por importacao de arquivo" <<endl;
    cout <<"3.Codificar frase" <<endl;
    cout <<"4.Decodificar frase" <<endl;
    cout <<"5.Exibir tabela ASCII e Tabela de Conversao" <<endl;
    cout <<"0.Encerrar" <<endl;
    cin >> opcao;
    getchar();

    return opcao;
}

Cifrador::Cifrador()
{
    size_t i;

    for(i=0; i<256; i++)
    {
        m_ascii.push_back(i);
    }

    m_encodingTable.resize(m_ascii.size());
    for(i=0; i<m_ascii.size(); i++)
    {
        m_encodingTable.at(i).first = m_ascii.at(i);
        m_encodingTable.at(i).second = m_ascii.at(i)+5;
    }

}

string Cifrador::Encode(string input)
{
    size_t i ,j;
    string aux = "";

    for( i=0; i<input.size(); i++)
    {
        char ch = input.at(i);

        for(j=0; j<m_encodingTable.size(); j++)
        {

            if(ch == m_encodingTable.at(j).first)
            {
                aux+= m_encodingTable.at(j).second;
                break;
            }
        }
    }

    return aux;
}
string Cifrador::Decode(string input)
{
    size_t i, j;
    string aux="";

    for( i=0; i<input.size(); i++)
    {
        char ch = input.at(i);

        for(j=0; j<m_encodingTable.size(); j++)
        {

            if(ch == m_encodingTable.at(j).second)
            {
                aux+= m_encodingTable.at(j).first;
                break;
            }
        }
    }

    return aux;

}

string Cifrador::ToString()
{
    string aux;
    stringstream sst;
    size_t i;

    sst << "Tabela ASCII: " <<endl;

    for(i=0;i<m_ascii.size();i++)
    {
        sst << (int)m_ascii.at(i) << " -> " << (char)m_ascii.at(i) << endl;


    }
    sst << "Tabela de conversao:"<<endl << "-------------------------------"<<endl;

    for(i=0;i<m_encodingTable.size();i++)
    {
        sst << (int)m_encodingTable.at(i).first << " -> " << (char)m_encodingTable.at(i).first << " -> " << m_encodingTable.at(i).second << endl;

    }

    aux+=sst.str();
    return aux;

}


string TextFile(string filepath)
{

    ifstream filereader(filepath);
    if(!filereader.is_open())
    {
        cout << "Erro, arquivo nao encontrado !" << endl;
        exit(1);
    }

    char ch;
    stringstream sst;
    while(filereader.get(ch))
    {
        sst << ch;

    }
    string text = sst.str();

    return text;

}
