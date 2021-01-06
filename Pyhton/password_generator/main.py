import random
import string


def passwdGenerator(length, digs, syms):
    passwd = ""
    strChc = ""
    
    if length < 0:
        return passwd

    strChc += string.ascii_letters
    strChc += string.digits if digs in ['y', 'Y'] else ""
    strChc += string.punctuation if syms in ['y', 'Y'] else ""

    for k in range(0, length):
        passwd += random.choice(strChc)

    return passwd


def main():
    digs = 0
    syms = 0
    length = 0

    while digs not in ['y', 'Y', 'n', 'N'] or syms not in ['y', 'Y', 'n', 'N'] or length < 8 or length > 64:
        digs = str(input("Do you want digits? [y/n] "))
        syms = str(input("Do you want symbols? [y/n] "))
        length = int(input("Insert the password length (8 - 64): "))
        print()

    print(f"Password: {passwdGenerator(length, digs, syms)}")

    return 0


if __name__ == "__main__":
    main()
