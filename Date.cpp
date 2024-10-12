//
// Created by casti on 07/10/2024.
//

#include "Date.h"
#include "stdexcept"


void Date::setGiorno(int Ngiorno) {
    if (ValidDate(Ngiorno,this->Year,this->Month))
        Day = Ngiorno;
    else {
        throw std::out_of_range("Unvalid Day");
    }
}

int Date::getGiorno() const {
    return Day;
}

void Date::setMese(int mese) {
    if (ValidDate(this->Day,this->Year,mese)) {
            Month = mese;
    } else {
        throw std::out_of_range("Unvalid Month");
    }
}

int Date::getMese() const {
    return Month;
}

int Date::getAnno() const {
    return Year;
}

void Date::setAnno(int anno) {
    if (ValidDate(this->Day,anno,this->Month))
        Year = anno;
   else{
        throw std::out_of_range("Unvalid Year");
    }
}

bool Date::IsLeap(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int Date::MaxDayOfMonth(int month, int year) const {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return IsLeap(year) ? 29 : 28;
        default:
            return 0;  // Mese non valido
    }
}

int Date::getDaysOfMonth(int month, int year) const {
    int max = MaxDayOfMonth(month, year);
    return max;
}

bool Date::ValidMonth(int month) const {
    if (month < 1 || month > 12)
        return false;
    return true;
}

bool Date::ValidYear(int year) const {
    if (year < 2000 || year > 2100)
        return false;
    return true;
}

bool Date::ValidDay(int day, int year, int month) const {
    int d = MaxDayOfMonth(month, year);
    if (day < d)
        return true;
    return false;

}

bool Date::ValidDate(int day, int year, int month) const {


    if (!ValidMonth(month))
        return false;


    if (!ValidYear(year))
        return false;


    if (!ValidDay(day, year, month))
        return false;


    return true;
}

std::string Date::PrintDate() const {
    return "Adding date->" + std::to_string(Day) + "/" + std::to_string(Month) + "/" + std::to_string(Year);

}

bool Date::operator==(const Date &data) const {
    if(this->Day == data.Day && this->Year == data.Year && this->Month == Month)
        return true;
    return false;
}


