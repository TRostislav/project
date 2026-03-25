#pragma once
#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"
#include <vector>

class ProjectManager : public Employee, public ProjectBudget, public Heading
{
    Project* project;
    double contribution;
    int subordinatesCount;
public:
    ProjectManager(int id, const string& name, Project* proj, double contr, int subCount);
    virtual double calcBudgetPart() override;
    virtual int calcHeads() override;
    virtual double calcProAdditions() override;
    virtual void calc() override;
    virtual void printInfo() const override;
    void setProject(Project* proj) { project = proj; }
    void setContribution(double contr) { contribution = contr; }
    void setSubordinatesCount(int count) { subordinatesCount = count; }
    virtual string getPosition() const override { return "ProjectManager"; }
    Project* getProject() const { return project; }
    double getContribution() const { return contribution; }
    int getSubordinatesCount() const { return subordinatesCount; }
};


class SeniorManager : public Employee, public Heading
{
    vector<pair<Project*, double>> projects;
    int subordinatesCount;
public:
    SeniorManager(int id, const string& name, int subCount);
    void addProject(Project* proj, double contr);
    virtual int calcHeads() override;
    virtual void calc() override;
    virtual void printInfo() const override;
    void setSubordinatesCount(int count) { subordinatesCount = count; }
    virtual string getPosition() const override { return "SeniorManager"; }
    const vector<pair<Project*, double>>& getProjects() const { return projects; }
    int getSubordinatesCount() const { return subordinatesCount; }
};


