#include <iostream>
#include <string>
using namespace std;

double carPayment, ccPayment, monthlyDebt, grossIncome, mortgagePayment;
bool decision1, boolvalue, potential, boolStatement;
int creditScore, dti_percent;
double loan, downPayment, HomeValue, ltv, fedti;
char contProgram;

bool DTI()
{
    // getting user financial values
    cout << "Enter your gross income per month: ";
    cin >> grossIncome;
    cout << "Enter your car payment per month: ";
    cin >> carPayment;
    cout << "Enter your credit card payment per month: ";
    cin >> ccPayment;
    cout << "Enter your mortgage payment per month: ";
    cin >> mortgagePayment;

    // calculting debt
    monthlyDebt = carPayment + ccPayment + mortgagePayment;
    dti_percent = (monthlyDebt / grossIncome) * 100;

    // displaying DTI
    cout << "Your debt income ratio is " << dti_percent << " percent. " << endl;

    if (dti_percent <= 43 && dti_percent >= 0)
    {

        decision1 = true;
        // dont forget to put this into js file
        //    if (dti_percent > 36 && dti_percent <= 43){
        //        cout << "While there are lenders who accept a " << dti_percent << "
        //        ratio, "; cout << "there is a risk associated as lender's prefer
        //        DTI scores lower than 36. ";
        //    }

        if (dti_percent > 43)
        {
            string advice;
            decision1 = false;
            advice = "It is advisable to lower your DTI score. One way to do so "
                     "would be to\nshift your high interest loans to a low interest "
                     "credit card.\nBe aware that having many credit cards can also "
                     "impact your ability to purchase a home negatively.";
            cout << advice;
        }
    }

    return decision1;
}

bool FEDTI()
{
    bool decision2;

    fedti = (mortgagePayment / grossIncome) * 100;

    if (fedti <= 28)
    {
        decision2 = true;
    }

    else
    {
        decision2 = false;
    }

    return decision2;
}

int main()
{

    cout << "Hello there! This program will help you identify whether you are "
            "eligible to purchase a home.";

    cout << " You will be asked to provide some financial information to "
            "understand your financial standing.";

    cout << "Please click any key to continue. ";

    cin >> contProgram;

    cout << "Enter your credit score: ";
    cin >> creditScore;
    cout << "Enter your home appraisal value: ";
    cin >> HomeValue;
    cout << "Enter how much you anticipate your down payment to be: ";
    cin >> downPayment;

    loan = HomeValue - downPayment;
    ltv = (loan / HomeValue) * 100;

    if (creditScore >= 640)
    {
        boolStatement = true;
    }
    else if (creditScore < 640)
    {
        boolStatement = false;
    }

    if (ltv >= 80.0)
    {
        boolvalue = true;
    }
    else if (ltv < 80.0)
    {
        boolvalue = false;
    }

    if (DTI() == false || FEDTI() == false || ltv == false || creditScore < 640)
    {
        potential = false;
        cout << "You're FEDTI is " << fedti << "." << endl;
        cout << "You are not eligible to purchase a house. " << endl;
    }
    else
    {
        cout << "You're FEDTI is " << fedti << "." << endl;
        cout << "You are eligible!!";
    }

    return 0;
}