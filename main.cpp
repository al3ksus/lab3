#include <iostream>
#include "Account.h"

using namespace std;

int main() {

    Account account;

    cout << "Введите данные счета" << endl;
    cin >> account;
    cout << account << endl;

    Money money = account.getMoney();

    cout << "Сумма денег прописью" << endl;
    cout << account.getMoney().toString() << endl;

    cout << "деньги в долларах" << endl;
    account.getMoney().toDollar();
    cout << account.getMoney() << endl;

    cout << "деньги в евро" << endl;
    account.getMoney().fromDollarToRuble();
    account.getMoney().toEuro();
    cout << account.getMoney() << endl;

    cout << "с процентами" << endl;
    account.getMoney().fromEuroToRuble();
    account.accrue();
    cout << account.getMoney() << endl;

    cout << "начислить деньги" << endl;
    cin >> money;
    account.deposit(money);
    cout << account.getMoney() << endl;

    cout << "снять деньги" << endl;
    cin >> money;
    account.withdraw(money);
    cout << account.getMoney() << endl;

    return 0;
}
