#pragma once
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, WorkBaseTime
{
protected:
	double salary;

public:
	Personal(int id, const string& name, double salary);
	virtual double calcBonus() const override;
	virtual double calcBase(double salary, double wtime) const override;
	virtual void calc() override;
	virtual void printInfo() const override;
	virtual string getPosition() const override { return "Personal"; }
};


class Cleaner : public Personal
{
public:
	Cleaner(int id, const string& name, double rate);
	virtual void printInfo() const override;
	virtual string getPosition() const override { return "Cleaner"; }
};


class Driver : public Personal {
	double nightHours;
public:
	Driver(int id, const string& name, double rate);
	void setNightHours(double hours);
	virtual double calcBonus() const override;
	virtual void printInfo() const override;
	virtual string getPosition() const override { return "Driver"; }
};
