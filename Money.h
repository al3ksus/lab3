#include <iostream>
#include <string>

using namespace std;

using namespace std;

class Money {
private:
    long ruble;
    unsigned char penny;

public:

    Money();

    Money(long ruble);

    Money(long ruble, unsigned char penny);

    Money(const Money &money);

    void setRuble(long ruble);

    void setPenny(unsigned char penny);

    long getRuble();

    int getPenny();

    string toString();

    Money toDollar();

    Money toEuro();

    Money fromDollarToRuble();

    Money fromEuroToRuble();

    Money& operator=(const Money& money);

    Money operator+(const Money& money);

    Money operator-(const Money& money);

    friend double operator/(Money money1, Money money2);

    Money operator/(double digit);

    Money operator*(double digit);

    friend bool operator==(Money money1, Money money2);

    friend ostream& operator<<(ostream& os, const Money& money);

    friend istream& operator>>(istream& in, Money& money);
};

