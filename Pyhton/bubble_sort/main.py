"""
Data una lista di numeri interi inserita dall'utente implementare la funzione di bubble sort
"""

def bubbleSort(vector = []):
    for k in vector:
        for j in range(len(vector) - 1):
            if(vector[j] > vector[j + 1]):
                vector[j], vector[j + 1] = vector[j + 1], vector[j]

def main():
    dim = int(input("\nInserire la dimensione dell'array: "))
    lista = []

    print()
    for k in range(abs(dim)):
        lista.append(input(f"Inserire l'elemento {k}: "))

    print(f"\n array: {lista}")
    bubbleSort(lista)
    print(f"\n array dopo BS: {lista}\n\n")

if __name__ == "__main__":
    main()