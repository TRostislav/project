#pragma once
class WorkBaseTime
{
	virtual double calcBase(double salary, double wtime) const = 0;
	virtual double calcBonus() const = 0;
};

class Heading
{
	virtual int calcHeads() = 0;
};

class ProjectBudget
{
	virtual double calcBudgetPart() = 0;
	virtual double calcProAdditions() = 0;
};
