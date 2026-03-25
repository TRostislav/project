#pragma once
class Project
{
	string id;
	double budget;
public:
    Project() : id{ "null" }, budget{ 0 } {}
    Project(const string& id, double b) : id{ id }, budget{ b } {}
    string getId() const { return id; }
    double getBudget() const { return budget; }
    void setBudget(double b) { budget = b; }
};

