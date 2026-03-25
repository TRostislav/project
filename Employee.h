#pragma once
#include <string>
using namespace std;

class Employee
{
protected:
	int Id;
	string name;
	string position;
	double worktime;
	double payment;

public:
	Employee(int id, const string& name);
	virtual ~Employee();
	void setWorkTime(double hours);
	virtual void calc() = 0;
	virtual void printInfo() const = 0;
	void setId(int newId) { Id = newId; }
	virtual string getPosition() const = 0;
	int getId() const;
	string getName() const;
	double getPayment() const;
};

