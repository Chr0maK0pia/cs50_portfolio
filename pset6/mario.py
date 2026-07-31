from cs50 import get_int

Height = 0
space_amt = 0
hasRun = False



while(Height < 1 or Height > 8):
    Height = get_int("How many blocks tall? ")
    space_amt = Height*2

for i in range(1,Height + 1):
    for y in range(space_amt - 2, 0, -2):
        print(" ", end = "")

    hasRun = False

    for j in range(2):
        for a in range(i):
            print("#", end = "")
        if(hasRun == False):
            print("  ", end = "")
            hasRun = True
    print()
    space_amt -= 2


