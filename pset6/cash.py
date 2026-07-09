from cs50 import get_float

input = None
change = 0
cents = None
quarters = 0
nickels = 0
dimes = 0
pennies = 0


def CalcQuarters(Cents):
    Quarters = 0
    while Cents >= 0.25:
        Quarters += 1
        Cents -= 0.25
    return Quarters


def CalcNickels(Cents):
    Nickels = 0
    while Cents >= 0.05:
        Nickels += 1
        Cents -= 0.05
    return Nickels


def CalcDimes(Cents):
    Dimes = 0
    while Cents >= 0.10:
        Dimes += 1
        Cents -= 0.10
    return Dimes


def CalcPennies(Cents):
    Penny = 0
    while Cents >= 0.01:
        Penny += 1
        Cents -= 0.01
    return Penny


input = get_float("Change: ")

while input < 0:
    input = get_float("Change: ")

cents = input

quarters = CalcQuarters(cents)

change += quarters

cents -= quarters * 0.25

cents = round(cents, 2)

if (quarters == 0 or cents > 0):
    dimes = CalcDimes(cents)
    change += dimes
    cents -= dimes * 0.10
    cents = round(cents, 2)

if (dimes == 0 or cents > 0):
    nickels = CalcNickels(cents)
    change += nickels
    cents -= nickels * 0.05
    cents = round(cents, 2)

if (nickels == 0 or cents > 0):
    pennies = CalcPennies(cents)
    change += pennies
    cents -= pennies * 0.01
    cents = round(cents, 2)

print(change)
