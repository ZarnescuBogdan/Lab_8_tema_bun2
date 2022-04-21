//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#ifndef LAB_7_REPO_H
#define LAB_7_REPO_H

#include "../Domain//Expense.h"
#include <vector>

using namespace std;

class Repo {
private:
    Expense entities[100];
    int noEntities;
public:
    Repo();
    ~Repo();
    void addEntity(Expense &entity);
    void modifyEntity(Expense &entity, Expense &newEntity);
    void deleteEntity(int id);
    Expense getEntityById(int id);
    Expense getEntityFromPos(int pos);
    int getSize();
    vector<Expense> getAll();
    Repo &operator=(const Repo &repo);
};


#endif //LAB_7_REPO_H
