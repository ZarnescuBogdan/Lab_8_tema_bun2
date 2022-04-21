//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#ifndef LAB_7_EXPENSE_H
#define LAB_7_EXPENSE_H


class Expense {
private:
    int id;
    int number;
    int sum;
    char* type;
public:
    Expense();
    Expense(const Expense& expense);
    Expense(int id, const char* type, int number, int sum);
    int getId();
    int getNumber();
    int getSum();
    char* getType();
    void setId(int id);
    void setNumber(int number);
    void setSum(int sum);
    void setType(const char* name);
    Expense &operator=(const Expense& expense);
    bool operator==(const Expense& expense);
    bool operator<=(const Expense& expense);
    bool operator<(const Expense& expense);
    bool operator>=(const Expense& expense);
    bool operator>(const Expense& expense);
    ~Expense();
    bool isValid();
};


#endif //LAB_7_EXPENSE_H
