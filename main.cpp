#include <iostream>
#include <string>
using namespace std;

double carPayment, ccPayment, monthlyDebt, grossIncome, mortgagePayment;
bool decision1, boolvalue, boolStatement, potential;
int creditScore, dti_percent;
double loan, downPayment, HomeValue, ltv, fedti, studentloan;
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
    cout << "Enter your student loan per month: ";
    cin >> mortgagePayment;

    // calculting debt
    monthlyDebt = carPayment + ccPayment + mortgagePayment + studentloan;
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
            potential = false; 
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
    potential = false; 

    return decision2;
}

void unPotential(){
    cout << "You are not eligible to purchase a house. " << endl;
    
    if (DTI() == false){
        cout << "\nYour DTI score is high. You must bring it down to at least 43."; 
        cout << "A DTI score of under 28 is ideal, while a score under 36 is good." << endl;
        cout << "Here are a couple steps you can take to improve your score: " << endl; 
        cout << "1: Secure a higher income. " << endl; 
        cout << "2. Pay off loans early. " << endl; 
        cout << "3. Secure longer loan terms. " << endl; 
        cout << "4. Shift high interest loans to low interest loans. " << endl; 
        cout << "5. Reduce monthly spendings. " << endl; 
        cout << "6. Avoid taking out new loans and making huge spendings. " << endl; 
        cout << "7. Pay off loans early. " << endl; 
        
    }
    
    if (FEDTI() == false){
        cout << "\nYour FEDTI score is high. You must bring it to atleast 28. " <<  endl; 
        cout << "Here are a couple steps you can take to improve your score: " << endl; 
        cout << "1. Decrease your mortgage payment by negotaitng longer loan periods. " << endl; 
        cout << "2. Secure higher income. Look for additional jobs. " << endl; 
        
    }
    
    if (creditScore < 640){
        cout << "\nYour credit score is low. A good credit score is above 640. " << endl; 
        cout << "Here are some steps you can take to improve your credit score. " << endl; 
        cout << "1. Complete payments within deadlines. " << endl; 
        cout << "2. Dispute any errors founds in credit report.  " <<  endl; 
        cout << "3. Limit the number of credit cards you open. " << endl; 
        cout << "4. Keep all credit card accounts open. " << endl; 
        cout << "5. Pay off debts as soon as possible. " << endl; 
        
    }
    
    if (ltv == false){
        cout << "\nYour LTV score is low. An average LTV score should be at least 80. " << endl; 
        cout << "Here are a couple steps you can take to improve your LTV score. " << endl; 
        cout << "1. Increase your down payment. " << endl; 
        cout << "2. Purchase a less expensive home/property. " << endl; 
        cout << "3. Secure a short loan term. " << endl; 
    }
}

int main()
{

    cout << "Hello there! This program will help you identify whether you are "
            "eligible to purchase a home.";

    cout << " You will be asked to provide some financial information to "
            "understand your financial standing.";

    cout << " Please click any key to continue. ";

    cin >> contProgram;

    cout << "Enter your credit score: ";
    cin >> creditScore;
    cout << "Enter your home appraisal value: ";
    cin >> HomeValue;
    cout << "Enter how much you anticipate your down payment to be: ";
    cin >> downPayment;

    cout << "Enter your loan: ";
    cin >> loan;

    ltv = (loan / HomeValue) * 100;

    if (creditScore >= 640)
    {
        boolStatement = true;
    }
    else if (creditScore < 640)
    {
        boolStatement = false;
        potential = false; 
    }

    if (ltv >= 80.0)
    {
        boolvalue = true;
    }
    else if (ltv < 80.0)
    {
        boolvalue = false;
        potential = false; 
    }

    if (potential == false)
    {
        cout << "\nYou're FEDTI is " << fedti << "." << endl;
        unPotential();
        
    }
    else
    {
        cout << "\nYou're FEDTI is " << fedti << "." << endl;
        cout << "You are eligible!!";
    }
    
    

    return 0;
}

