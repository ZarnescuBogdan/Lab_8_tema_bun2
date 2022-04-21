//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include <iostream>
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include "../UI/UI.h"

using namespace std;

void menu() {
    bool ok = true;
    UI ui;
    Service service;
    char option;

    while (ok) {
        ui.Options();
        cout << "Dati optiunea: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                ui.addExpense();
                break;
            }
            case '2': {
                int number;
                cout << "Give apartment number: ";
                cin >> number;
                ui.deleteApartment(number);
                break;
            }
            case '3': {
                int nrStart, nrEnd;
                cout << "Give apartment number to start: ";
                cin >> nrStart;
                cout << "Give apartment number to end: ";
                cin >> nrEnd;
                ui.deleteApartments(nrStart, nrEnd);
                break;
            }
            case '4': {
                char type[100];
                cout << "Give type: ";
                cin >> type;
                ui.deleteApartmentType(type);
                break;
            }
            case '5': {
                char type[100];
                int number, sum;
                cout << "Give apartment number: ";
                cin >> number;
                cout << "Give apartment type: ";
                cin >> type;
                cout << "Give the new sum: ";
                cin >> sum;
                ui.modifySum(number, type, sum);
                break;
            }
            case '6': {
                int number;
                cout << "Give apartment number: ";
                cin >> number;
                ui.showAllApartment(number);
                break;
            }
            case '7': {
                int sum;
                cout << "Give value: ";
                cin >> sum;
                ui.showAllGreaterThanValue(sum);
                break;
            }
            case '8': {
                int sum;
                cout << "Give sum: ";
                cin >> sum;
                ui.showAllGivenSum(sum);
                break;
            }
            case '9': {
                char type[100];
                cout << "Give type: ";
                cin >> type;
                cout << ui.showSum(type);
                break;
            }
            case 's': {
                ui.showAll();
                break;
            }
            case 'a': {
                int number;
                cout << "Give apartment number: ";
                cin >> number;
                Expense expense;
                expense = ui.showBiggestApartment(number);
                cout << expense.getId() << " " << expense.getNumber() << " " << expense.getType() << " " << expense.getSum() << endl;
                break;
            }
            //case 'b': {
            //    char type[100];
            //    cout << "Give type: ";
            //    cin >> type;
            //    vector<Expense> expenses = ui.sortByType(type);
            //    for(auto &exp: expenses) {
            //        cout << exp.getId() << " " << exp.getNumber() << " " << exp.getType() << " " << exp.getSum() << endl;
            //    }
            //    break;
            //}
            case 'c': {
                char type[100];
                cout << "Give type: ";
                cin >> type;
                ui.filterType(type);
                break;
            }
            case 'd': {
                int sum;
                cout << "Give sum: ";
                cin >> sum;
                ui.filterSum(sum);
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}
