//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#include "Expense.h"
#include <cstring>
#include <vector>

using namespace std;

/**
 * Constructor.
 */
Expense::Expense() {
    this->id = 0;
    this->type = nullptr;
    this->number = 0;
    this->sum = 0;
}

/**
 * Copy-constructor.
 * @param expense
 */
Expense::Expense(const Expense &expense) {
    this->id = expense.id;
    this->type = new char[strlen(expense.type) + 1];
    strlcpy(this->type, expense.type, size_t(this->type));
    this->number = expense.number;
    this->sum = expense.sum;
}

/**
 * Constructor with parameters.
 * @param id id of expense
 * @param type type of expense
 * @param number number of expense
 * @param sum sum of expense
 */
Expense::Expense(int id, const char *type, int number, int sum) {
    this->id = id;
    this->type = new char[strlen(type) + 1];
    strlcpy(this->type, type, size_t(this->type));
    this->number = number;
    this->sum = sum;
}

/**
 * Set id of expense.
 * @param id id of expense
 */
void Expense::setId(int id1) {
    this->id = id1;
}

/**
 * Set number of expense.
 * @param number number of expense
 */
void Expense::setNumber(int number1) {
    this->number = number1;
}

/**
 * Set sum of expense.
 * @param sum sum of expense
 */
void Expense::setSum(int sum1) {
    this->sum = sum1;
}

/**
 * Set type of expense.
 * @param type type of expense
 */
void Expense::setType(const char *type1) {
    if(this->type) {
        delete[] this->type;
    }
    this->type = new char[strlen(type1) + 1];
    strlcpy(this->type, type1, size_t(this->type));
}

/**
 * Get id of expense.
 * @return id of expense
 */
int Expense::getId() {
    return this->id;
}

/**
 * Get number of expense.
 * @return number of expense
 */
int Expense::getNumber() {
    return this->number;
}

/**
 * sum of expense.
 * @return sum of expense
 */
int Expense::getSum() {
    return this->sum;
}

/**
 * type of expense.
 * @return type of expense
 */
char* Expense::getType() {
    return this->type;
}

/**
 * Destructor.
 */
Expense::~Expense() {
    if(this->type) {
        delete[] this->type;
        this->id = 0;
        this->type = nullptr;
        this->number = 0;
        this->sum = 0;
    }
}

/**
 * Assignment operator.
 * @param e e to be assigned
 * @return the e assigned
 */
Expense& Expense::operator=(const Expense &e) {
    this->setId(e.id);
    this->setType(e.type);
    this->setNumber(e.number);
    this->setSum(e.sum);
    return *this;
}

/**
 * Equal operator.
 * @param expense expense to be compared
 * @return true or false
 */
bool Expense::operator==(const Expense &expense) {
    return (this->sum == expense.sum) and (this->number == expense.number) and (strcmp(this->type, expense.type) == 0);
}

/**
 * Validator.
 * @return true or false
 */
bool Expense::isValid() {
    const char *s1 = "apa";
    const char *s2 = "caldura";
    const char *s3 = "electricitate";
    const char *s4 = "gaz";
    const char *s5 = "altele";
    vector<const char*>types = {s1, s2, s3, s4, s5};
    for(auto &s: types) {
        if(strcmp(s, type) == 0) {
            return true;
        }
    }
    return false;
}

bool Expense::operator<=(const Expense &expense) {
    return this->sum >= expense.sum;
}

bool Expense::operator<(const Expense &expense) {
    return this->sum > expense.sum;
}

bool Expense::operator>=(const Expense &expense) {
    return this->sum <= expense.sum;
}

bool Expense::operator>(const Expense &expense) {
    return this->sum < expense.sum;
}
