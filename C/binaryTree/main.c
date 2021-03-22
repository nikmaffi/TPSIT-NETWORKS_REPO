#include <stdio.h>
#include <stdlib.h>

//Struttura dati che indica un singolo nodo di un albero
typedef struct TNode {
    struct TNode* left; //Puntatore al nodo figlio sinistro
    struct TNode* right; //Puntatore al nodo figlio destro
    int key; //Chiave univoca
    int value; //Valore del nodo
} Node;

typedef Node* BinaryTree; //definizione Tipo BinaryTree

short newNode(BinaryTree* bt, int key, int value) {
    //Funzione che inserisce un nuovo nodo nell'albero binario

    //Se il nodo in esame non esiste viene allocato e vengono settati i parametri
    if(!(*bt)) {
        (*bt) = (Node*) calloc(1, sizeof(Node));
        (*bt)->left = NULL;
        (*bt)->right = NULL;
        (*bt)->key = key;
        (*bt)->value = value;

        return 1;
    }

    if(key > (*bt)->key) {
        //Se la chiave è maggiore della chiave del nodo in esame il nuovo nodo nascerà a destra
        newNode(&(*bt)->right, key, value);
    } else if(key < (*bt)->key) {
        //Se la chiave è minore della chiave del nodo in esame il nuovo nodo nascerà a sinistra
        newNode(&(*bt)->left, key, value);
    } else {
        //Se la chiave è uguale della chiave del nodo in esame non verrà creato il nuovo nodo (errore)
        return 0;
    }

    return 1;
}

void printTree(BinaryTree bt, int tabs) {
    //Funzione che stampa l'albero binario dalla cima

    //Se il nodo in esame non esiste allora la ricorsione viene saltata
    if(!bt) {
        return;
    }

    //Stampa di un numero di tab pari al valore del parametro tabs
    for(int k = 0; k < tabs; k++) {
        printf("\t");
    }
    //Stampa dei valori del nodo
    printf("Key: %d; Value: %d\n", bt->key, bt->value);

    //Stampa dei valori dei nodi figli utilizzando la ricorsione
    //(viene passato tabs + 1 per aggiungere un livello d'indentazione per rendere comprensibile la stampa)
    printTree(bt->left, tabs + 1);
    printTree(bt->right, tabs + 1);

    return;
}

int main() {
    BinaryTree bt = NULL;
    int num = 0, key = 0;

    //Input dei valori e creazione dell'albero binario
    printf("Insert the values like this: key value\n(Press a char to end)\n");
    while(scanf("%d %d", &key, &num)) {
        if(!newNode(&bt, key, num)) {
            //Errore di duplicazione della chiave
            printf("Error: Duplicated key %d!\n", key);
            return -1;
        }
    }

    printf("\n\nBinary tree:\n\n");
    printTree(bt, 0); //Stampa dell'albero binario
    printf("\n\n");

    return 0;
}