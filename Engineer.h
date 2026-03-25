#pragma once
#include "Personal.h"
#include "Project.h"

class Engineer : public Personal, public ProjectBudget, public Project
{
protected:
	Project* project;
	double contribution;

public:
	Engineer(int id, const string& name, double rate, Project* proj, double contr);
	virtual double calcBudgetPart();
    virtual double calcProAdditions() override;
    virtual void calc() override;
    virtual void printInfo() const override;
    void setProject(Project* proj) { project = proj; }
    void setContribution(double contr) { contribution = contr; }
    virtual string getPosition() const override { return "Engineer"; }
    Project* getProject() const { return project; }
    double getContribution() const { return contribution; }
};


class Programmer : public Engineer
{
    double earlyBonus;

public:
    Programmer(int id, const string& name, double rate, Project* proj, double contr, double bonus);
    virtual double calcProAdditions() override;
    virtual void printInfo() const override;
    virtual string getPosition() const override { return "Programmer"; }
};


class Tester : public Engineer
{
    int bugsFound;
    double bonusPerBug;

public:
    Tester(int id, const string& name, double rate, Project* proj, double contr, int bugs, double perBug);
    virtual double calcProAdditions() override;
    virtual void printInfo() const override;
    virtual string getPosition() const override { return "Tester"; }
};


class TeamLeader : public Engineer, public Heading {
    int subordinatesCount;
public:
    TeamLeader(int id, const string& name, double rate, Project* proj, double contr, int subCount);
    virtual int calcHeads() override;
    virtual void calc() override;
    virtual void printInfo() const override;
    virtual string getPosition() const override { return "TeamLeader"; }
};

