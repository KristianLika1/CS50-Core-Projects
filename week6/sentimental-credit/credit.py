import cs50

while True:
    number = input("Credit card number: ")
    if number.isdigit() and (len(number) == 16 or len(number) == 15 or len(number) == 13):
        break
    else:
        print("INVALID")
        exit()
#Take every other number starting from second to last digit and create a list then convert the list into a list of integers
list_of_digits1 = [int(digit) for digit in list(number[-2::-2])]

list_of_digits2 = [int(digit) for digit in list(number[-1::-2])]

#multiply every element of the list by 2
list_of_digits1 = [digit * 2 for digit in list_of_digits1]

str_list1 = ''.join(str(digit) for digit in list_of_digits1)
digits1 = [int(char) for char in str_list1]

total = sum(digits1) + sum(list_of_digits2)

last_digit = int(str(total)[-1])

if not last_digit == 0:
    print("INVALID")
    exit()
elif len(number) == 15 and (number[:2] == "34" or number[:2] == "37"):
    print("AMEX")
    exit()
elif len(number) == 16 and number[:2] in ["50", "51", "52", "53", "54", "55"]:
    print("MASTERCARD")
    exit()
elif (len(number) == 13 or len(number) == 16) and number[:1] == "4":
    print("VISA")
    exit()
else:
    print("INVALID")
    exit()

