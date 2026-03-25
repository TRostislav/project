#include "Personal.h"
#include <iostream>

// Personal
Personal::Personal(int id, const string& name, double rate) : Employee{ id, name}, salary{ rate } {}

double Personal::calcBase(double salary, double wtime) const
{
    return salary * wtime;
}

double Personal::calcBonus() const
{
    return 0;
}

void Personal::calc()
{
    payment = calcBase(salary, worktime) + calcBonus();
}

void Personal::printInfo() const
{
    cout << Id << "\t" << name << "\tPersonal\t" << worktime << "\t" << payment << endl;
}


// Cleaner
Cleaner::Cleaner(int id, const string& name, double rate) : Personal{ id, name, rate } {}

void Cleaner::printInfo() const
{
    cout << Id << "\t" << name << "\tCleaner\t" << worktime << "\t" << payment << endl;
}

// Driver
Driver::Driver(int id, const string& name, double rate) : Personal{ id, name, rate } {}

void Driver::setNightHours(double hours)
{
    nightHours = hours;
}

double Driver::calcBonus() const
{
    return nightHours * salary * 0.5;
}

void Driver::printInfo() const
{
    cout << Id << "\t" << name << "\tDriver\t" << worktime << "\t" << payment << endl;
}


