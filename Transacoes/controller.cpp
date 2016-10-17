#include "controller.h"

Controller::Controller()
{
    number_of_transactions = 0;
}

void Controller::begin(string name)
{
    Transaction t(name);
    started.transactions.push_back(t);
    number_of_transactions++;
}

void Controller::read(Transaction t)
{
    Transaction aux;
    for (unsigned int i=0; i<started.transactions.size(); i++)
    {
        aux = started.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            started.transactions.erase(started.transactions.begin() + i);
            active.transactions.push_back(aux);
        }
    }
}

void Controller::write(Transaction t)
{
    Transaction aux;
    for (unsigned int i=0; i<started.transactions.size(); i++)
    {
        aux = started.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            started.transactions.erase(started.transactions.begin() + i);
            active.transactions.push_back(aux);
        }
    }
}

void Controller::terminate(Transaction t)
{
    Transaction aux;
    for (unsigned int i=0; i<active.transactions.size(); i++)
    {
        aux = active.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            active.transactions.erase(active.transactions.begin() + i);
            execution_process.transactions.push_back(aux);
        }
    }
}

void Controller::rollback(Transaction t)
{
    Transaction aux;
    for (unsigned int i=0; i<active.transactions.size(); i++)
    {
        aux = active.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            active.transactions.erase(active.transactions.begin() + i);
            cancel_process.transactions.push_back(aux);
        }
    }

    for (unsigned int i=0; i<execution_process.transactions.size(); i++)
    {
        aux = execution_process.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            execution_process.transactions.erase(execution_process.transactions.begin() + i);
            cancel_process.transactions.push_back(aux);
        }
    }
}

void Controller::commit(Transaction t)
{
    Transaction aux;
    for (unsigned int i=0; i<execution_process.transactions.size(); i++)
    {
        aux = execution_process.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            execution_process.transactions.erase(execution_process.transactions.begin() + i);
            executed.transactions.push_back(aux);
        }
    }
}

void Controller::finish(Transaction t)
{
    Transaction aux;
    for (unsigned int i=0; i<executed.transactions.size(); i++)
    {
        aux = executed.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            executed.transactions.erase(executed.transactions.begin() + i);
            finished.transactions.push_back(aux);
        }
    }

    for (unsigned int i=0; i<cancel_process.transactions.size(); i++)
    {
        aux = cancel_process.transactions.at(i);
        if (aux.getName() == t.getName())
        {
            cancel_process.transactions.erase(cancel_process.transactions.begin() + i);
            finished.transactions.push_back(aux);
        }
    }
}

void Controller::print_states()
{
    for (unsigned int i=0; i<started.transactions.size(); i++)
    {
        cout << started.transactions.at(i).getName() << ": Iniciada" << endl;
    }

    for (unsigned int i=0; i<active.transactions.size(); i++)
    {
        cout << active.transactions.at(i).getName() << ": Ativa" << endl;
    }

    for (unsigned int i=0; i<cancel_process.transactions.size(); i++)
    {
        cout << cancel_process.transactions.at(i).getName() << ": Processo_Cancelamento" << endl;
    }

    for (unsigned int i=0; i<execution_process.transactions.size(); i++)
    {
        cout << execution_process.transactions.at(i).getName() << ": Processo_Efetivacao" << endl;
    }

    for (unsigned int i=0; i<executed.transactions.size(); i++)
    {
        cout << executed.transactions.at(i).getName() << ": Efetivada" << endl;
    }

    for (unsigned int i=0; i<finished.transactions.size(); i++)
    {
        cout << finished.transactions.at(i).getName() << ": Finalizada" << endl;
    }

    cout << endl << endl;
}
