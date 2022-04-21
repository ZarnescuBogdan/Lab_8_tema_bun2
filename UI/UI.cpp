//
// Created by Bogdan Zarnescu on 14.04.2022.
//

#include "UI.h"
#include <iostream>
#include <algorithm>

using namespace std;

UI::UI() = default;

UI::UI(Service &service1) {
    this->service = service1;
}

UI::~UI() = default;

void UI::addExpense() {
    int id, number, sum;
    char type[100];
    cout << "Give id: ";
    cin >> id;
    cout << "Give number: ";
    cin >> number;
    cout << "Give sum: ";
    cin >> sum;
    cout << "Give type: ";
    cin >> type;

    Expense expense(id, type, number, sum);
    this->service.create(expense);
}

void UI::showAll() {
    for(auto &exp: this->service.getAll()) {
        cout << exp.getId() << " " << exp.getType() << " " << exp.getNumber() << " " << exp.getSum() << endl;
    }
}

void UI::deleteApartment(int number) {
    for(auto &exp: this->service.getAll()) {
        if(exp.getNumber() == number) {
            service.delete1(exp);
        }
    }
}

void UI::deleteApartments(int nrStart, int nrEnd) {
    for(auto &exp: this->service.getAll()) {
        if(nrStart <= exp.getNumber() and exp.getNumber() >= nrEnd) {
            service.delete1(exp);
        }
    }
}

void UI::deleteApartmentType(const char *type) {
    for(auto &exp: this->service.getAll()) {
        if(strcmp(exp.getType(), type) == 0) {
            service.delete1(exp);
        }
    }
}

void UI::modifySum(int number, const char *type, int sum) {
    Expense oldExp;
    for(auto &exp: this->service.getAll()) {
        if(strcmp(exp.getType(), type) == 0 and exp.getNumber() == number) {
            oldExp = exp;
        }
    }
    if(oldExp.getNumber() != 0) {
        Expense newExp(oldExp.getId(), type, number, sum);
        this->service.update(oldExp, newExp);
    }
}

void UI::showAllApartment(int number) {
    for(auto &exp: this->service.getAll()) {
        if(exp.getNumber() == number) {
            cout << exp.getId() << " " << exp.getNumber() << " " << exp.getType() << " " << exp.getSum() << endl;
        }
    }
}

void UI::showAllGreaterThanValue(int sum) {
    for(auto &exp: this->service.getAll()) {
        if(exp.getSum() > sum) {
            cout << exp.getId() << " " << exp.getNumber() << " " << exp.getType() << " " << exp.getSum() << endl;
        }
    }
}

void UI::showAllGivenSum(int sum) {
    for(auto &exp: this->service.getAll()) {
        if(exp.getSum() == sum) {
            cout << exp.getId() << " " << exp.getNumber() << " " << exp.getType() << " " << exp.getSum() << endl;
        }
    }
}

int UI::showSum(const char *type) {
    int sum = 0;
    for(auto &exp: this->service.getAll()) {
        if(strcmp(exp.getType(), type) == 0) {
            sum += exp.getSum();
        }
    }
    return sum;
}

Expense UI::showBiggestApartment(int number) {
    int max = 0;
    Expense expense;
    for(auto &exp: this->service.getAll()) {
        if(exp.getNumber() == number and max < exp.getSum()) {
            max = exp.getSum();
            expense = exp;
        }
    }
    if(max != 0) {
        return expense;
    }
}

vector<Expense> UI::sortByType(const char *type) {
    vector<Expense> expenses;
    for(auto &exp: this->service.getAll()) {
        if(strcmp(exp.getType(), type) == 0) {
            expenses.push_back(exp);
        }
    }
    for(int i = 0; i < expenses.size(); i++) {
        for(int j = i + 1; j < expenses.size(); j++) {
            if(expenses[i].getSum() < expenses[j].getSum()) {
                swap(expenses[i], expenses[j]);
            }
        }
    }
    //sort(expenses.begin(), expenses.end());
    return expenses;
}

void UI::filterType(const char *type) {
    for(auto &exp: this->service.getAll()) {
        if(strcmp(exp.getType(), type) == 0) {
            this->service.delete1(exp);
        }
    }
}

void UI::filterSum(int sum) {
    for(auto &exp: this->service.getAll()) {
        if(exp.getSum() > sum) {
            this->service.delete1(exp);
        }
    }
}

vector<Expense> UI::getAll() {
    return this->service.getAll();
}

Expense UI::getExpenseById(int id) {
    for(auto &exp: this->service.getAll()) {
        if(exp.getId() == id) {
            return exp;
        }
    }
}

void UI::Options() {
    cout << endl << "1. Add an expense." << endl;
    cout << "2. Delete expense by number of apartment. " << endl;
    cout << "3. Delete expenses between two numbers of apartments." << endl;
    cout << "4. Delete expense by type {apa, caldura, electricitate, gaz, altele}." << endl;
    cout << "5. Modify sum for the expenses for a given type and number of apartment." << endl;
    cout << "6. Show all the expenses with a given apartment number." << endl;
    cout << "7. Show all the expenses with the sum greater than a given number." << endl;
    cout << "8. Show all the expenses with the sum equal to a given number." << endl;
    cout << "9. Show sum of all expenses that have their type a given type." << endl << endl;
    cout << "a. Show all of the entities" << endl;
    cout << "b. Show the most valuable expense of a given aparment." << endl;
    cout << "c. Sort by sum of expense for a given type of expense. " << endl;
    cout << "d. Filter all the expenses in order to remain just the expenses with a given type." << endl;
    cout << "e. Filter for expenses with a sum lower than a given number." << endl;
    cout << "" << endl;
    cout << "x. Exit." << endl;
}
