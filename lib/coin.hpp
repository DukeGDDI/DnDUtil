#include <iostream>
using namespace std;

#ifndef COIN_HPP
#define COIN_HPP
// Coin class to express a monetary amount in various denominations
// e.g. 10 copper, 5 silver, 2 gold, 1 platinum
class Coin {
public: 
    int copper;
    int silver;
    int gold;
    int platinum;

    Coin() : copper(0), silver(0), gold(0), platinum(0) {}
    Coin(int copper, int silver, int gold, int platinum) :
        copper(copper), 
        silver(silver), 
        gold(gold), 
        platinum(platinum) {}
    // Copy constructor
    Coin(const Coin& other) : 
        copper(other.copper), 
        silver(other.silver), 
        gold(other.gold), 
        platinum(other.platinum) 
{ }

    ~Coin() = default;

    // Overload the + operator to add two Coin objects
    Coin operator+(const Coin& other) const;
    // Overload the - operator to subtract two Coin objects
    Coin operator-(const Coin& other) const;
    // Overload the += operator to add and assign two Coin objects
    Coin& operator+=(const Coin& other);
    // Overload the -= operator to subtract and assign two Coin objects
    Coin& operator-=(const Coin& other);
    // Overload the == operator to compare two Coin objects
    bool operator==(const Coin& other) const;
    // Overload the != operator to compare two Coin objects
    bool operator!=(const Coin& other) const;
    // Overload the < operator to compare two Coin objects
    bool operator<(const Coin& other) const;
    // Overload the <= operator to compare two Coin objects
    bool operator<=(const Coin& other) const;
    // Overload the >= operator to compare two Coin objects
    bool operator>=(const Coin& other) const;
    // Overload the > operator to compare two Coin objects
    bool operator>(const Coin& other) const;
    // Overload the assignment operator
    Coin& operator=(const Coin& other);
    // Overload the << operator for easy printing of Coin objects
    friend ostream& operator<<(ostream& os, const Coin& coin);

    // compute total weight of coins in pounds
    double totalWeight() const;
    // compute total value of coins in copper
    int totalValueInCopper() const;
protected:
    Coin normalize() const;
    static Coin fromCopper(int copper);

};
#endif // COIN_HPP