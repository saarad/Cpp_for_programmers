//
// Created by Ilia on 14.11.2019.
//
template <class type, class type2>
class Pair {
public:
    type first;
    type2 second;
    Pair(type f, type2 s) {
        first = f;
        second = s;
    }

    Pair operator+(const Pair &other) {
        Pair par = *this;
        par.first += other.first;
        par.second += other.second;
        return par;
    }

    bool operator>(const Pair &other) {
        return isEqual(other) == 1;
    }

    int isEqual(const Pair &other) {
        type sumThis = first + second;
        type sumOther = other.first + other.second;
        type difference = sumThis - sumOther;

        if (difference > 0) {
            return 1;
        } else if (difference == 0) {
            return 0;
        }
        return -1;
    }
};
