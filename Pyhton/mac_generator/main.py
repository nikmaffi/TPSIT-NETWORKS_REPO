import random


def MACGenerator():
    MAC = "";

    MACLen = 12
    validChars = "0123456789ABCDEF"

    for k in range(0, MACLen):
        MAC += random.choice(validChars)

    for k in range(0, MACLen + 1, 3):
        MAC = MAC[:k + 2] + ":" + MAC[k + 2:]

    return MAC


def main():
    print(f"M.A.C. address: {MACGenerator()}")

    return 0


if __name__ == "__main__":
    main();