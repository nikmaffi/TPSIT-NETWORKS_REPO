def fibonacci(length):
    if length <= 0:
        return 0
    elif length == 1:
        return 1
    else:
        return fibonacci(length - 1) + fibonacci(length - 2)


def main():
    n = int(input("Insert a number: "))

    if n <= 0 or n > 30:
        print("Insert a number between 1 and 30!")
        return -1

    print("\nFibonacci sequence: ", end="")
    for k in range(1, n + 1):
        print(f"{fibonacci(k)} ", end="")

    return 0


if __name__ == "__main__":
    main()