#include "Manager.h"
#include <iostream>

//ProjectManager
ProjectManager::ProjectManager(int id, const string& name, Project* proj, double contr, int subCount) : Employee(id, name), project(proj), contribution(contr), subordinatesCount(subCount) {}

double ProjectManager::calcBudgetPart()
{
    if (project)
    {
        return contribution * project->getBudget();
    }
    return 0;
}

int ProjectManager::calcHeads()
{
    return subordinatesCount * 200;
}

double ProjectManager::calcProAdditions()
{
    return 0;
}

void ProjectManager::calc()
{
    payment = calcBudgetPart() + calcHeads();
}

void ProjectManager::printInfo() const
{
    cout << Id << "\t" << name << "\tProjectManager\t" << worktime << "\t" << payment << endl;
}


//SeniorManager
SeniorManager::SeniorManager(int id, const string& name, int subCount) : Employee(id, name), subordinatesCount(subCount) {}

void SeniorManager::addProject(Project* proj, double contr)
{
    projects.push_back({ proj, contr });
}

int SeniorManager::calcHeads()
{
    return subordinatesCount * 300;
}

void SeniorManager::calc()
{
    payment = calcHeads();
    for (auto& p : projects)
    {
        if (p.first) payment += p.second * p.first->getBudget();
    }
}

void SeniorManager::printInfo() const
{
    cout << Id << "\t" << name << "\tSeniorManager\t" << worktime << "\t" << payment << endl;
}
