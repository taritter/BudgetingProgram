//
// Created by ritte on 9/18/2022.
//

#ifndef M1OP_TARITTER1_MONTHLYBUDGET_H
#define M1OP_TARITTER1_MONTHLYBUDGET_H

    /*
     * Tess Ritter CS120 M1OP
     * This program calculates your monthly budget and reports how much you spent
     * It uses getters and setters
     * Has a struct that contains basic info about the person
     * Has a static void method that calculates the difference between set budget and spent budget
     * gets the final amount spent
     * Has an overloaded operator that subtracts month set budget from spent budget
     */

#include <iostream>
#include <vector>
using namespace std;


class monthlyBudget {
private:
    vector<double> expenses;
    double budget;
    vector<string> months;


public:
    /*
     * Default Constructor
     * Requires: vector of expenses, budget, and vector of months
     * Modifies: nothing
     * Effects: calls the variables needed for the class
     */
    monthlyBudget();

    //getter
    vector<double> getExpenses()const;
    double getBudget()const;
    vector<string> getMonths()const;

    //setter
    void setExpenses();
    void setBudget();


    //my struct info that contains the month, name, and year
    struct info{
        string month;
        string name;
        string year;
    };


    /*
     * This method gets the difference between the users set budget and actual spent during that month
     * Requires: set budget and total spent for the month
     * Modifies: nothing
     * Effects: prints out how much you went over or under
     */
    static void budgetDifference (double, double);

    /*
     * This method returns how much was spent and  much is left or over budget.
     * Requires: a string which is the month
     * Modifies: nothing
     * Effects: adds up all the values in the vector
     */
    double getReport (string);


    //unary overloaded operator
    double operator < (string month){
        return getBudget() - getReport(month);
    }

};

#endif //M1OP_TARITTER1_MONTHLYBUDGET_H
