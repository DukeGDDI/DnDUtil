#include "coin.hpp"



// Total weight of coins
double Coin::totalWeight() const { 
    return (copper + silver + gold + platinum) * 0.02; 
}

int Coin::totalValueInCopper() const {
    return (copper + silver * 10 + gold * 100 + platinum * 1000);
}

// Overload the << operator for Coin
std::ostream& operator<<(std::ostream& os, const Coin& coin) {
    os << coin.platinum << " pp, "
       << coin.gold << " gp, "
       << coin.silver << " sp, "
       << coin.copper << " cp";
    return os;
}

// Overload the + operator to add two Coin objects
Coin Coin::operator+(const Coin& other) const {
    return Coin(copper + other.copper,
                silver + other.silver,
                gold + other.gold,
                platinum + other.platinum);
}

// Overload the - operator to subtract two Coin objects
// Will check that total value does not go negative and that no denomination goes negative
Coin Coin::operator-(const Coin& other) const {
    if (totalValueInCopper() < other.totalValueInCopper()) {
        cerr << "Error: Insufficient funds" << endl;
        return *this;  // Return original object if insufficient funds
    }
  
    return fromCopper(totalValueInCopper() - other.totalValueInCopper());
}

// Overload the += operator to add and assign two Coin objects
Coin& Coin::operator+=(const Coin& other) {
    copper += other.copper;
    silver += other.silver;
    gold += other.gold;
    platinum += other.platinum;
    return *this;
}

// Overload the -= operator to subtract and assign two Coin objects
Coin& Coin::operator-=(const Coin& other) {
    if (totalValueInCopper() < other.totalValueInCopper()) {
        cerr << "Error: Insufficient funds" << endl;
        return *this;  // Return original object if insufficient funds
    }
    Coin result = fromCopper(totalValueInCopper() - other.totalValueInCopper());
    copper = result.copper;
    silver = result.silver;
    gold = result.gold;
    platinum = result.platinum;
    return *this;
}

// Overload the == operator to compare two Coin objects
bool Coin::operator==(const Coin& other) const {
    return (copper == other.copper &&
            silver == other.silver &&
            gold == other.gold &&
            platinum == other.platinum);
}

// Overload the != operator to compare two Coin objects
bool Coin::operator!=(const Coin& other) const {
    return !(*this == other);
}   

// Overload the < operator to compare two Coin objects
bool Coin::operator<(const Coin& other) const {
    return this->totalValueInCopper() < other.totalValueInCopper();
}

// Overload the <= operator to compare two Coin objects
bool Coin::operator<=(const Coin& other) const {
    return this->totalValueInCopper() <= other.totalValueInCopper();
}   

// Overload the >= operator to compare two Coin objects
bool Coin::operator>=(const Coin& other) const {
    return this->totalValueInCopper() >= other.totalValueInCopper();
}

// Overload the > operator to compare two Coin objects
bool Coin::operator>(const Coin& other) const {
    return this->totalValueInCopper() > other.totalValueInCopper();
}

// Overload the assignment operator
Coin& Coin::operator=(const Coin& other) {
    if (this != &other) {
        copper = other.copper;
        silver = other.silver;
        gold = other.gold;
        platinum = other.platinum;
    }
    return *this;
}

// Private helper to normalize coin denominations
Coin Coin::normalize() const {
    Coin result = *this;

    // Normalize copper to silver
    if (result.copper >= 10) {
        result.silver += result.copper / 10;
        result.copper = result.copper % 10;
    }

    // Normalize silver to gold
    if (result.silver >= 10) {
        result.gold += result.silver / 10;
        result.silver = result.silver % 10;
    }

    // Normalize gold to platinum
    if (result.gold >= 10) {
        result.platinum += result.gold / 10;
        result.gold = result.gold % 10;
    }

    return result;
}

// Create a normalized Coin object given a copper value
Coin Coin::fromCopper(int copper) {
    Coin result;
    result.copper = copper;
    return result.normalize();
}
