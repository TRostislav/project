#include "Engineer.h"
#include <iostream>

// Engineer
Engineer::Engineer(int id, const string& name, double rate, Project* proj, double contr) : Personal{ id, name, rate }, project{ proj }, contribution{ contr } {}

double Engineer::calcBudgetPart()
{
    if (project)
    {
        return contribution * project->getBudget();
    }
    return 0;
}

double Engineer::calcProAdditions()
{ 
    return 0; 
}

void Engineer::calc()
{
    Personal::calc();
    payment += calcBudgetPart() + calcProAdditions();
}

void Engineer::printInfo() const
{
    cout << Id << "\t" << name << "\tEngineer\t" << worktime << "\t" << payment << endl;
}


//Programmer
Programmer::Programmer(int id, const string& name, double rate, Project* proj, double contr, double bonus) : Engineer(id, name, rate, proj, contr), earlyBonus(bonus) {}

double Programmer::calcProAdditions()
{
    return earlyBonus;
}

void Programmer::printInfo() const
{
    cout << Id << "\t" << name << "\tProgrammer\t" << worktime << "\t" << payment << endl;
}

string Programmer::toFileLine() const
{
    string projName = project ? project->getId() : "";
    return to_string(Id) + ";" + name + ";" + getPosition() + ";" +
        to_string(salary) + ";" + projName + ";" + to_string(contribution) + ";" +
        to_string(earlyBonus);
}

//Tester
Tester::Tester(int id, const string& name, double rate, Project* proj, double contr, int bugs, double perBug) : Engineer(id, name, rate, proj, contr), bugsFound(bugs), bonusPerBug(perBug) {}

double Tester::calcProAdditions()
{
    return bugsFound * bonusPerBug;
}

void Tester::printInfo() const
{
    cout << Id << "\t" << name << "\tTester\t" << worktime << "\t" << payment << endl;
}


//TeamLeader
TeamLeader::TeamLeader(int id, const string& name, double rate, Project* proj, double contr, int subCount) : Engineer(id, name, rate, proj, contr), subordinatesCount(subCount) {}

int TeamLeader::calcHeads()
{
    return subordinatesCount * 100;
}
void TeamLeader::calc()
{
    Engineer::calc();
    payment += calcHeads();
}
void TeamLeader::printInfo() const
{
    cout << Id << "\t" << name << "\tTeamLeader\t" << worktime << "\t" << payment << endl;
}
