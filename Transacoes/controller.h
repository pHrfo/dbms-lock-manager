#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "general.h"
#include "state.h"

class Controller
{
private:
    State started;
    State active;
    State cancel_process;
    State execution_process;
    State executed;
    State finished;
public:
    int number_of_transactions;
    Controller();
    void begin(string);
    void read(Transaction);
    void write(Transaction);
    void terminate(Transaction);
    void rollback(Transaction);
    void commit(Transaction);
    void finish(Transaction);
    void print_states();
};

#endif // CONTROLLER_H
