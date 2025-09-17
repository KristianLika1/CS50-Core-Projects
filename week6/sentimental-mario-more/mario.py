while True:
    height = input("Give me a number between 1 and 8: ")
    try:
        height_int = int(height)
        if height_int > 0 and height_int < 9:
            break
    except ValueError:
        pass


for i in range(height_int - 1, -1, -1):
    if i == 0:
        print("#" * (height_int - i), end="")
    else:
        print(" " * i + "#" * (height_int - i), end="")
    print("  ", end="")
    print("#" * (height_int - i))
