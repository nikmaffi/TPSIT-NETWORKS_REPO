import string


def rot15Encoder(s):
    letters = string.ascii_letters + " " + string.digits + string.punctuation
    encodeString = ""

    for i, c in enumerate(s):
        encodeString += letters[letters.index(c) + 15 if letters.index(c) + 15 < len(letters) else letters.index(c) + 15 - len(letters)]

    return encodeString


def rot15Decoder(s):
    letters = string.ascii_letters + " " + string.digits + string.punctuation
    decodeString = ""

    for i, c in enumerate(s):
        decodeString += letters[letters.index(c) - 15 if letters.index(c) - 15 >= 0 else letters.index(c) - 15 + len(letters)]

    return decodeString


def main():
    encDec = 0
    s = str(input("Enter the string: "))

    while not encDec in ['e', 'E', 'd', 'D']:
        encDec = str(input("Encoding or decoding? [e/d] "))

    print()
    if encDec in ['e', 'E']:
        print(f"Encoded string: {rot15Encoder(s)}")
    elif encDec in ['d', 'D']:
        print(f"Decoded string: {rot15Decoder(s)}")


if __name__ == "__main__":
    main()