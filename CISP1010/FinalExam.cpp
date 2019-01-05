// Brian Flatt
// CISP 1010
// Final Exam: This program will calculate monthly car payment options based upon user
// inputted loan details.

#include <iostream> // needed for cin and cout
#include <iomanip> // needed for setw() and setprecision()
#include <cmath>  // needed for pow function

using namespace std;

// Function definitions
float getPrice();
float getTradeIn(float price);
float getDownPayment(float price, float trade);
float getIntRate();
float calcMonPayment(float annualIntRate, float loanAmt, int noMonths);
void displayLoanSchedule(float payments[], float price, float trade, float downPayment, float annualIntRate, float loanAmt);


int main()
{
    // variable declarations
    float price;
    float trade;
    float downPayment;
    float annualIntRate;
    int noMonths = 12;
    float monPayment[5]; // array
    
    // Displays instructions to the user
    cout << "This program will calculate several monthly payment options on a vehicle" << endl;
    cout << "based upon user inputted loan details." << endl;
    cout << endl;
    cout << "Enter all data without $ signs." << endl;
    cout << endl;
    
    // function calls
    price = getPrice(); // gets user inputted price of vehicle
    
    trade = getTradeIn(price); // gets user inputted trade in value
    
    downPayment = getDownPayment(price, trade); // gets user inputted down payments
    
    annualIntRate = getIntRate(); // gets user inputted annual intererest rate
    
    // calculates loan amount
    float loanAmt = price - trade - downPayment;
    
    // function call to get the loan schedule and store the monthly payments in an array
    for (int i = 0; i < 5; i++)
    {
        monPayment[i] = calcMonPayment(annualIntRate, loanAmt, noMonths);
        noMonths = noMonths + 12;
    }
    
    // function call to display the loan schedule
    displayLoanSchedule(monPayment, price, trade, downPayment, annualIntRate, loanAmt);
    
    return 0;
}

// function that returns user inputted price of vehicle
float getPrice()
{
    // variable declaration
    float price;
    
    // user prompt
    cout << "Please enter a vehicle price." << endl;
    
    // prompts for valid input
    do {
    cout << "Price must be between $75.00 and $48,500.00" << endl;
    cin >> price;
    }
    while (price < 75.00 || price > 48500.00);
    
    return price;
}

// function that returns user inputted trade in value
float getTradeIn(float price)
{
    // variable declaration
    float trade;
    
    // user prompt
    cout << "Please enter a trade in value." << endl;
    
    // prompts for valid input
    do {
    cout << "Trade in Value must be between 0 and the price of the vehicle." << endl;
    cin >> trade;
    } while (trade < 0 || trade >= price);
    
    return trade;
}

// function that returns user inputted downpayment
float getDownPayment(float price, float trade)
{
    // variable declaration
    float downPayment;
    
    // user prompt
    cout << "Please enter a downpayment." << endl;
    
    // prompts for valid input
    do {
    cout << "Downpayment must be between 0 and the (Price - Trade In Value)." << endl;
    cin >> downPayment;
    }  while (downPayment < 0 || downPayment >= (price - trade));
    
    return downPayment;
}

// function that returns user inputted annual interest rate as a decimal
float getIntRate()
{
    // variable declaration
    float annualIntRate;
    
    // user prompt
    cout << "Please enter an annual interest rate as a decimal number."<< endl;
    
    // prompts for valid input
    do {
    cout << "Annual Interest rate must be between 0 and 0.19" << endl;
        cin >> annualIntRate;
    } while (annualIntRate < 0 || annualIntRate > .19);
    
    return annualIntRate;
}

// function that returns by value monthly loan payment.  Called 5 times.
float calcMonPayment(float annualIntRate, float loanAmt, int noMonths)
{
    float payment;
    
    // calculates monthly interest rate
    float monIntRate = annualIntRate / float(12.0);
    
    // calculates monthly payment
    payment = (loanAmt * monIntRate) / float(1.0 - pow(1.0 + monIntRate, -noMonths));

    return payment;
}

// function that displays the loan schedule
void displayLoanSchedule(float monPayment[], float price, float trade, float downPayment, float annualIntRate, float loanAmt)
{
    // calculates annual interest rate as a percent
    float annualIntPercent = annualIntRate * float(100.0);
    // variable declaration
    int noMonths = 12;
    
    // Output the user inputs
    cout << fixed << setprecision(2) << endl;
    cout << "Vehicle price "<< setw(5)<< "$" << price << endl;
    cout << "Trade in Value" << setw(5) << "$" << trade << endl;
    cout << "Down Payment" << setw(7) << "$" <<  downPayment << endl;
    cout << setw(27) << "--------" << endl;
    
    //Output the calculated loan amount and annual interest rate as a percent
    cout << "Loan Amount" << setw(8) << "$" << loanAmt << endl;
    cout << endl;
    cout << "Annual Interest Rate" << setw(6) << annualIntPercent << "%" << endl << endl;
    
    //Output the loan schedule headings
    cout << "Monthly payment options." << endl << endl;
    cout << "Number" << endl;
    cout << "of Months" << setw(8) << "Payment" << endl;
    cout << "---------" << setw(8) << "-------" << endl;
    
    // for loop that outputs the loan schedule from the array
    for (int i = 0; i < 5; i++)
    {
        cout << noMonths;
        cout << setw(9)<< "$" << monPayment[i] << endl;
        noMonths = noMonths + 12;
    }
    
    return;
}

