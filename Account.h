#include <string>
#include "Money.h"

using namespace std;

class Account {
private:
    string surname;

    long number;

    int percent;

    Money money;

public:
    Account();

    Account(string surname, long number, int percent);

    void setSurname(string surname);

    void setNumber(long number);

    void setPercent(int percent);

    void setMoney(Money money);

    string getSurname();

    long getNumber();

    int getPercent();

    Money getMoney();

    void withdraw(const Money& money);

    void deposit(Money money);

    void accrue();

    friend ostream& operator<<(ostream& os, Account& account);

    friend istream& operator>>(istream& in, Account& account);
};