//
// Created by Bogdan Zarnescu on 14.04.2022.
//

#ifndef LAB_7_UI_H
#define LAB_7_UI_H

#include "../Service/Service.h"

class UI {
private:
    Service service;
public:
    UI();
    UI(Service &service1);
    ~UI();
    void Options();
    void addExpense();
    void showAll();
    void deleteApartment(int number);
    void deleteApartments(int nrStart, int nrEnd);
    void deleteApartmentType(const char *type);
    void modifySum(int number, const char *type, int sum);
    void showAllApartment(int number);
    void showAllGreaterThanValue(int sum);
    void showAllGivenSum(int sum);
    int showSum(const char *type);
    Expense showBiggestApartment(int number);
    vector<Expense> sortByType(const char *type);
    void filterType(const char *type);
    void filterSum(int sum);
    vector<Expense> getAll();
    Expense getExpenseById(int id);
};


#endif //LAB_7_UI_H
