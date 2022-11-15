#include "Account.h"

Account::Account() {
    surname = "";
    number = NULL;
    percent = NULL;
}

Account::Account(string surname, long number, int percent) {
    this->surname = surname;
    this->number = number;
    this->percent = percent;
}

void Account::setSurname(string surname) {
    this->surname = surname;
}

void Account::setMoney(Money money) {
    this->money = money;
}

Money Account::getMoney() {
    return money;
}

void Account::withdraw(const Money& money) {
    this->money = this->money - money;
}

void Account::deposit(Money money) {
    this->money = this->money + money;
}

void Account::accrue() {
    this->money = this->money + (this->money * percent) / 100;
}

string Account::getSurname() {
    return this->surname;
}

void Account::setNumber(long number) {
    this->number = number;
}

void Account::setPercent(int percent) {
    this->percent = percent;
}

long Account::getNumber() {
    return this->number;
}

int Account::getPercent() {
    return this->percent;
}

ostream& operator<<(ostream& os, Account& account) {
    return os << "Фамилия: " << account.getSurname() << endl
    << "Номер счета: " << account.getNumber() << endl
    << "Процент: " << account.getPercent() << endl
    << "Сумма денег: " << *(account.getMoney()) << endl;
}

istream& operator>>(istream& in, Account& account)
{
    string surname;
    long num;
    int percent;
    Money* money = new Money;

    in >> surname >> num >> percent >> *money;

    account.setSurname(surname);
    account.setNumber(num);
    account.setPercent(percent);
    account.setMoney(money);

    return in;
}
