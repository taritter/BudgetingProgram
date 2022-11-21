#include <iostream>
#include <vector>
#include <fstream>
#include "monthlyBudget.h"
#include "monthlyBudget.cpp"
//gets user information
struct Info {
    string month;
    string name;
    string year;
    vector<string> months {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};;

    Info(string m, string n, string y){
        month = m;
        name = n;
        year = y;
        //vector<string> months {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    }

    string getMonth(){
        return month;
    }

    string getName(){
        return name;
    }

    void setMonth(string m){
        month = m;
    }

    void setName(string n){
        name = n;
    }

    void setYear(int y){
        year = y;
    }

    void addInfo() {
        string userName;
        string userMonth;
        string year;
        bool mBool = false;
        int count = 0;
        //what month?
        cout << "Hi welcome to budget calculator, what is your name? This is not case sensitive as it is a name" << endl;
        getline(cin, userName);
        setName(userName);
        //method to make sure it's a month
        while (!mBool) {
            cout << "What month is this for? (please use all lowercase)" << endl;
            getline(cin, userMonth);
            for (string m: months) {
                if (userMonth == m) {
                    setMonth(userMonth);
                    mBool = true;
                }
            }
        }

        int y;
        cout << "What year is this for? (between 1900 and 2023)" << endl;
        cin >> y;
        while (y < 1900 or y > 2023) {
            cout << "Please type in a valid year: (between 1900 and 2023)" << endl;
            cin >> y;
        }
        setYear(y);
    }


};

int main() {
    monthlyBudget mBudget;
    string n;
    string m;
    string y;
    struct Info i(m,n,y);
    double setBudget;
    double spentBudget;

    //This monthly log text file saves your expenses

    cout << "Hello, welcome to your monthly budget sheet," << endl;
    cout << "here you can calculate your spending's and see how much you spent!\n" << endl;

    i.addInfo();

    mBudget.setBudget();

    cout << i.getName() << " you have a budget of $" << mBudget.getBudget() << " for the month of " << i.getMonth() << "\n\n" << endl;

    mBudget.setExpenses();

    spentBudget = mBudget.getReport(i.getMonth());

    mBudget.budgetDifference(mBudget.getBudget(),spentBudget);

return 0;
};