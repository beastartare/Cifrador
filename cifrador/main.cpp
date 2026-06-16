#include "class.cpp"

int main()
{
    int opcao, op;
    Cifrador C;
    size_t i;
    string aux, phrase, arquivo;
    string filepath;

    do
    {
        opcao = menu();

        if(opcao==1)
        {

            cout << "Entre com um arquivo para leitura: ";
            cin >> filepath;
            aux = TextFile(filepath);
            cout << "Texto codificado: " <<endl;
            cout << C.Encode(aux) <<endl;

            cout <<"Deseja guardar o texto codificado em um arquivo?\n 1.SIM \n 2.NAO: " <<endl;
            cin >> op;

            if(op==1)
            {
                cout<<"Digite o nome do arquivo: " <<endl;
                cin >>arquivo;
                ofstream arq(arquivo);

                if(arq.is_open())
                {
                    arq << C.Encode(aux);
                }
            }

            continue;
        }
        if(opcao==2)
        {

            cout << "Entre com um arquivo para leitura: ";
            cin >> filepath;
            aux = TextFile(filepath);
            cout << "Texto decodificado: " <<endl;
            cout << C.Decode(aux) <<endl;

            continue;

        }
        if(opcao==3)
        {

            cout << "Entre com uma frase:  ";
            getline(cin,aux);
            cout << "Texto codificado: " <<endl;
            cout << C.Encode(aux) <<endl;

            continue;
        }
        if(opcao==4)
        {

            cout << "Entre com uma frase: ";
            getline(cin,aux);
            cout << "Texto decodificado: " <<endl;
            cout << C.Decode(aux) <<endl;

            continue;
        }
        if(opcao==5)
        {

            cout << C.ToString() <<endl;

            continue;
        }
        if(opcao==0)
        {
            cout << "Programa finalizado!!";
            break;
        }
        else
        {
            cout << "opcao invalida, digite novamente"<< endl;
        }

    }while(opcao!=0);


    return 0;

}
