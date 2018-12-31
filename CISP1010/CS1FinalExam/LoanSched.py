from math import *


def get_price():
    while True:
        price = input("Please enter a vehicle price\n")
        price = float(price)
        if price > 75.00 or price < 48500.00:
            break
    return price


def get_trade(price):
    while True:
        trade = input("Please enter a trade in value\n")
        trade = float(trade)
        if trade > 0 or trade <= price:
            break
    return trade


def get_down_payment(price, trade):
    while True:
        down_payment = input("Please enter a downpayment\n")
        down_payment = float(down_payment)
        if down_payment > 0 or down_payment <= (price - trade):
            break
    return down_payment


def get_annual_int_rate():
    while True:
        annual_int_rate = input("Please enter an annual interest rate\n")
        annual_int_rate = float(annual_int_rate)
        if annual_int_rate > 0 or annual_int_rate <= .19:
            break
    return annual_int_rate


def calc_mon_payment(annual_int_rate, loan_amt, no_months):
    mon_int_rate = annual_int_rate / 12.0
    payment = (loan_amt * mon_int_rate) / (1.0 - pow(1.0 + mon_int_rate, -no_months))
    return payment


def display_loan_schedule(payments, price, trade, down_payment, annual_int_rate, loan_amt):
    annual_int_percent = annual_int_rate * 100.0

    print("Vehicle Price:  ${:<.2f}".format(price))
    print("Trade in Value: ${:<.2f}".format(trade))
    print("Down Payment:   ${:<.2f}\n".format(down_payment))
    print("              -------------")

    print("Loan Amount:    ${:5.2f}".format(loan_amt))
    print("Ann. Int. Rate:  {:.2f}%\n".format(annual_int_percent))

    print("Monthly Payment options\n")
    print("Number")
    print("of Months      Payment")
    print("---------      --------")

    no_months = 12
    for payment in payments:
        print("{:<12d}  ${:<.2f}".format(no_months, payment))
        no_months += 12


def main():
    print("This program will calculate several monthly payment options on a vehicle")
    print("based on user inputted loan details\n")
    print("Enter all data without $ signs\n")

    price = get_price()
    trade = get_trade(price)
    down_payment = get_down_payment(price, trade)
    annual_int_rate = get_annual_int_rate()

    loan_amt = price - down_payment - trade

    payments = []
    no_months = 12

    for i in range(4):
        payments.append(calc_mon_payment(annual_int_rate, loan_amt, no_months))
        no_months += 12

    display_loan_schedule(payments, price, trade, down_payment, annual_int_rate, loan_amt)


if __name__ == '__main__':
    main()
