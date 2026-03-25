#include <iostream>
#include "Employee.h"

Employee::Employee(int id, const string& name) : Id{ id }, name{ name }, worktime{ 0 }, payment{ 0 } {}
Employee::~Employee() {}

void Employee::setWorkTime(double hours)
{
	worktime = hours;
}

int Employee::getId() const
{
	return Id;
}

string Employee::getName() const
{
	return name;
}

double Employee::getPayment() const
{
	return payment;
}

