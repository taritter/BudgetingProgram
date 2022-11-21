//
// Created by ritte on 9/18/2022.
//

#include <iostream>
#include <vector>

using namespace std;

monthlyBudget::monthlyBudget() {
    vector<double> expenses;
    double budget = 0.0;
    vector<string> months {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
}

vector<double> monthlyBudget::getExpenses() const {
    return expenses;
}

double monthlyBudget::getBudget() const {
    return budget;
}

vector<string> monthlyBudget::getMonths() const {
    return months;
}

void monthlyBudget::setExpenses() {
    string ex;
    double exp;
    int decimalCount = 0;

    cout << "You can now start entering in your expenses!\n" << endl;
    cout << "Please enter in your expenses, press 'e' when you are finished" << endl;
    getline(cin,ex);

    while(ex != "e") {

        decimalCount = 0;
        while (decimalCount != 1) {
            if(ex == "e"){
                decimalCount = 1;
            }
            for (int i = 0; i < ex.length(); i++) {
                if ((isdigit(ex[i]) != true and ex[i] != '.') or ex.empty()) {
                    i = -1;
                    decimalCount = 0;
                    cout << "Input was not a float number, try again" << endl;
                    cin.clear();
                    getline(cin, ex);
                    if(ex == "e"){
                        i = -1;
                        decimalCount = 1;
                    }
                }
                if (ex[i] == '.') {
                    decimalCount++;
                }
                if (decimalCount > 1) {
                    i = -1;
                    decimalCount = 0;
                    cout << "Input was not a float number, try again" << endl;
                    cin.clear();
                    getline(cin, ex);
                    if(ex == "e"){
                        decimalCount = 1;
                    }
                }
            }
            if (decimalCount == 0) {
                cout << "Input was not a float number, try again" << endl;
                cin.clear();
                getline(cin, ex);
                if(ex == "e"){
                    decimalCount = 1;
                }
            }
        }
        exp = stod(ex);
        expenses.push_back(exp);
        cout << "Please enter in your expenses, press 'e' when you are finished" << endl;
        getline(cin, ex);

    }
    cout << "You've entered all your expenses for the month!" << endl;
}

void monthlyBudget::setBudget() {
    int decimalCount = 0;
    string f;
    char floater;
    double inputBudget;

    cout << "What is your monthly budget? (ex. 5.00)" << endl;
    cin >> f;

    while(decimalCount != 1 ){
        for (int i = 0; i < f.length(); i++) {
            if ((isdigit(f[i]) != true and f[i] != '.') or f.empty() ) {
                i = -1;
                decimalCount = 0;
                cout << "Input was not correct, try again" << endl;
                cin.clear();
                getline(cin, f);
            }
            if (f[i] == '.') {
                decimalCount++;
            }
            if (decimalCount > 1) {
                i = -1;
                decimalCount = 0;
                cout << "Input was not a float number, try again" << endl;
                cin.clear();
                getline(cin, f);
            }
        }
        if(decimalCount == 0){
            cout << "Input was not a float number, try again" << endl;
            cin.clear();
            getline(cin, f);
        }
    }
    inputBudget = stod(f);
    budget = inputBudget;
}


void monthlyBudget::budgetDifference(double setBudget, double spentBudget) {
    double difference = setBudget - spentBudget;
    if(difference > 0){
        cout << "You spent " << difference << " less than you set for yourself" << endl;
    }
    else if(difference < 0){
        difference = difference * -1;
        cout << "You spent " << difference << " more than you set for yourself" << endl;
    }
}

double monthlyBudget::getReport(string m) {
    cout << "For the month of " << m << endl;
    cout << "You spent: ";

    double dub = 0;

    for(double c: expenses){
        dub += c;
    }
    cout << dub << endl;
    return dub;
}
