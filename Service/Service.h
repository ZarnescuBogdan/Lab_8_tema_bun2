//
// Created by Bogdan Zarnescu on 14.04.2022.
//

#ifndef LAB_7_SERVICE_H
#define LAB_7_SERVICE_H

#include "../Repo/Repo.h"

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo &repo);
    void create(Expense &entity);
    void update(Expense entity, Expense newEntity);
    void delete1(Expense entity);
    Expense getById(int id);
    Expense getEntityFromPos(int pos);
    vector<Expense> getAll();
    ~Service();
    int getSize();
};


#endif //LAB_7_SERVICE_H
