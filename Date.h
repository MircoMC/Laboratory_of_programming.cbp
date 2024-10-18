//
// Created by casti on 07/10/2024.
//

#ifndef LABORATORY_OF_PROGRAMMING_DATE_H
#define LABORATORY_OF_PROGRAMMING_DATE_H

#include "iostream"


class Date {
public:
    Date(int d, int m, int y) {
        if (ValidDate(d, y, m)) {
            this->Day = d;
            this->Month = m;
            this->Year = y;
        }

        else{
             throw std::out_of_range("Unvalid Date!");
        }
    }

    int getGiorno() const;

    void setGiorno(int Ngiorno);

    int getMese() const;

    void setMese(int mese);

    int getAnno() const;

    void setAnno(int anno);

    bool IsLeap(int year) const;

    std::string PrintDate() const;

    bool operator ==(const Date &data) const;

    bool ValidDate(int day, int year, int month) const;

private:
    int Day;
    int Month;
    int Year;

    bool ValidYear(int year) const;

    bool ValidMonth(int month) const;

    bool ValidDay(int day, int year, int month) const;

    int getDaysOfMonth(int month, int year) const;

    int MaxDayOfMonth(int month, int year) const;
};



#endif //LABORATORY_OF_PROGRAMMING_DATE_H
