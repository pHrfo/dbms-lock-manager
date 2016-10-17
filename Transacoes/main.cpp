#include "general.h"
#include "state.h"
#include "transaction.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    int opc;
    Controller c;
    string name;
    Transaction t;
    while (opc != 8)
    {
        system("clear");
        if (c.number_of_transactions > 0)
        {
            c.print_states();
        }
        cout << "MENU - Digite a opção desejada:" << endl;
        cout << "1 - TR_Begin" << endl;
        cout << "2 - Read" << endl;
        cout << "3 - Write" << endl;
        cout << "4 - TR_Terminate" << endl;
        cout << "5 - TR_Rollback" << endl;
        cout << "6 - TR_Commit" << endl;
        cout << "7 - TR_Finish" << endl;
        cout << "8 - Sair" << endl;

        cin >> opc;

        switch(opc)
        {
            case 1:
                cout << "Digite o nome da nova transacao" << endl;
                cin >> name;
                c.begin(name);
            break;

            case 2:
                cout << "Digite o nome da transacao" << endl;
                cin >> name;
                t.setName(name);
                c.read(t);
            break;

            case 3:
                cout << "Digite o nome da transacao" << endl;
                cin >> name;
                t.setName(name);
                c.write(t);
            break;

            case 4:
                cout << "Digite o nome da transacao" << endl;
                cin >> name;
                t.setName(name);
                c.terminate(t);
            break;

            case 5:
                cout << "Digite o nome da transacao" << endl;
                cin >> name;
                t.setName(name);
                c.rollback(t);
            break;

            case 6:
                cout << "Digite o nome da transacao" << endl;
                cin >> name;
                t.setName(name);
                c.commit(t);
            break;

            case 7:
                cout << "Digite o nome da transacao" << endl;
                cin >> name;
                t.setName(name);
                c.finish(t);
            break;
        }
    }
}
