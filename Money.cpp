#include "Money.h"
#include <iostream>
#include <vector>

using namespace std;

Money::Money() {
    ruble = 0;
    penny = 0;
}

Money::Money(long ruble) {

    if (ruble >= 0) {
        this->ruble = ruble;
    } else {
        this->ruble = 0;
    }
    penny = 0;
}

Money::Money(long ruble, unsigned char penny) {
    if (ruble >= 0) {
        this->ruble = ruble;
    } else {
        this->ruble = 0;
    }

    if (penny >= 0) {
        if (penny >= 100) {
            this->ruble += penny / 100;
        }
        this->penny = penny % 100;
    } else {
        this->penny = 0;
    }
}

Money::Money(const Money &money) {
    this->ruble = money.ruble;
    this->penny = money.penny;
}

void Money::setRuble(long ruble) {
    if (ruble >= 0) {
        this->ruble = ruble;
    }
}

void Money::setPenny(unsigned char penny) {

    if (penny >= 0) {
        if (penny >= 100) {
            this->ruble = penny / 100;
        }
        this->penny = penny % 100;
    }
}

long Money::getRuble() {
    return ruble;
}

int Money::getPenny() {
    return (int) penny;
}

Money Money::toDollar() {
    Money money = *this / 60;
    setRuble(money.getRuble());
    setPenny(money.getPenny());
}

Money Money::toEuro() {
    Money money = *this / 70;
    setRuble(money.getRuble());
    setPenny(money.getPenny());
}

Money Money::fromDollarToRuble() {
    Money money = *this * 60;
    setRuble(money.getRuble());
    setPenny(money.getPenny());
}

Money Money::fromEuroToRuble() {
    Money money = *this * 70;
    setRuble(money.getRuble());
    setPenny(money.getPenny());
}

string Money::toString() {
    string* units = new string [10] {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
    string* unitsFem = new string [10] {"ноль", "одна", "две", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
    string* teens = new string[10] {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать","восемнадцать", "девятнадцать"};
    string* dozens = new string[8] {"двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят","девяносто"};
    string* hundreds = new string[9] {"сто", "двести", "триста", "четыресто", "пятьсот", "шестьсот", "семьсот", "восемьсот","девятьсот"};
    string** matrix = new string*[5] {units, unitsFem, teens, dozens, hundreds};

    string strRuble = "";
    string strPenny = "";

    long ruble = this->getRuble();
    long tempRuble;
    unsigned char penny = this->getPenny();
    unsigned char tempPenny;
    int size;

    vector<long> digits;

    do {
        tempRuble = ruble % 10;
        digits.insert(digits.begin(), tempRuble);
        ruble /= 10;
    } while (ruble > 0);

    size = digits.size();

    for (int i = 0; i < digits.size(); i++) {

        if (size == 4) {
            strRuble += matrix[1][digits[i]];

            if (digits[i] == 1) {
                strRuble += " тысяча";
            }
            else if (digits[i] >= 2 && digits[i] <= 4) {
                strRuble += " тысячи";
            }
            else if (digits[i] >= 5 && digits[i] <= 9) {
                strRuble += " тысяч";
            }
        }
        else if (size == 3 || size == 6) {
            if (digits[i] != 0) {
                strRuble += matrix[4][digits[i] - 1];
            }
        }
        else if (size == 2 || size == 5) {
            if (digits[i] >=2) {
                strRuble += matrix[3][digits[i] - 2];
            }
            else if (digits[i] == 1) {
                i++;
                strRuble += matrix[2][digits[i]];

                if (size == 5) {
                    strRuble += " тысяч";
                    size--;
                }
                else {
                    strRuble += " рублей,";
                }
            }
        }
        else if (size == 1) {
            if (!(digits[i] == 0 && !strRuble.empty())) {
                strRuble += matrix[0][digits[i]];
            }
            if (digits[i] == 1) {
                strRuble += " рубль,";
            }
            else if (digits[i] >= 2 && digits[i] <= 4) {
                strRuble += " рубля,";
            }
            else {
                strRuble += " рублей,";
            }
        }
        strRuble += " ";
        size--;
    }

    digits.clear();

    do {
        tempPenny = penny % 10;
        digits.insert(digits.begin(), tempPenny);
        penny /= 10;
    } while (penny > 0);

    size = digits.size();

    for (int i = 0; i < digits.size(); i++) {

        if (size == 2) {
            if (digits[i] >=2) {
                strPenny += matrix[3][digits[i] - 2];
            }
            else if (digits[i] == 1) {
                i++;
                strPenny += matrix[2][digits[i]];

                strPenny += " копеек";
            }
        }
        else if (size == 1) {
            if (!(digits[i] == 0 && !strPenny.empty())) {
                strPenny += matrix[1][digits[i]];
            }
            if (digits[i] == 1) {
                strPenny += " копейка";
            }
            else if (digits[i] >= 2 && digits[i] <= 4) {
                strPenny += " копейки";
            }
            else {
                strPenny += " копеек";
            }
        }
        strPenny += " ";
        size--;
    }
    return strRuble + strPenny;
}

Money& Money::operator=(const Money& money) {
    setRuble(money.ruble));
    setPenny(money.penny);
}

Money Money::operator+(const Money& money) {
    Money money1(this->ruble + money.ruble, this->penny + money.penny);

    if (money1.getPenny() >= 100) {
        money1.setRuble(money1.getRuble() + 1);
        money1.setPenny(money1.getPenny() - 100);
    }

    return money1;
}

Money Money::operator-(const Money& money) {
    Money money1;
    long tempMoney;

    tempMoney = (this->getRuble() * 100 + this->getPenny()) - (money.ruble * 100 + money.penny);

    if (tempMoney > 0) {
        money1.setRuble(tempMoney / 100);
        money1.setPenny(tempMoney % 100);
    }
    else {
        money1.setRuble(0);
        money1.setPenny(0);
    }

    return money1;
}

double operator/(Money money1, Money money2) {
    double ruble = money1.getRuble() * 100 + money1.getPenny();
    double penny = money2.getRuble() * 100 + money2.getPenny();
    return ruble / penny;
}

Money Money::operator/(double digit) {
    Money money;
    long tempMoney = (this->ruble * 100 + this->penny) / digit;

    money.setRuble(tempMoney / 100);
    money.setPenny(tempMoney % 100);

    return money;
}

Money Money::operator*(double digit) {
    Money money;
    long tempMoney = (this->ruble * 100 + this->penny) * digit;

    money.setRuble(tempMoney / 100);
    money.setPenny(tempMoney % 100);

    return money;
}

bool operator==(Money money1, Money money2) {
    if (money1.getRuble() == money2.getRuble() && money1.getPenny() == money2.getPenny()) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream& os, const Money& money) {
    return os << money.ruble << ',' << money.penny;
}

istream& operator>>(istream& in, Money& money)
{
    long ruble;
    int penny;

    in >> ruble >> penny;

    money.setRuble(ruble);
    money.setPenny(penny);

    return in;
}