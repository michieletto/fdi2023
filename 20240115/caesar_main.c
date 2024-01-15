// caesar_main.c
// Include le librerie necessarie
#include "caesar.h"         // Libreria con le funzioni

#define NUM_CHARS 4096

/**
 * Visita di ogni nodo all'interno della lista
 * per stampare il contenuto a schermo
 * @param [in] head puntatore alla testa della lista
*/
static void print_list(struct CharNode *head) {
    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL) {
        // Stampo a schermo il contenuto del nodo
        printf("%c -> ", head->value);
        // e mi sposto al nodo successivo
        head = head->next;
    }
    // Stampo a schermo che sono arrivato alla fine della lista
    printf("NULL\n");
}

/**
 * Alloca un nuovo nodo da inserire nella lista usando la memoria dinamica
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore al nodo creato
**/
static struct CharNode* new_node(char value) {
    // Allocazione dinamica del nodo
    struct CharNode* node = (struct CharNode*)malloc(sizeof(struct CharNode));
    // Se l'allocazione è andata a buon fine
    if (node != NULL) {      // Imposto
        node->value = value; // valore
        node->next = NULL;   // e link
    }
    return node;
}

static struct CharNode* insert_after(struct CharNode* prev, double value) {
    struct CharNode* temp = new_node(value);

    if (temp == NULL)
        return NULL;
    
    if (prev != NULL) {
        temp->next = prev->next;
        prev->next = temp;
    }

    return temp;
}

int main(int argc, char *argv[]){
    bool check = (argc > 1) && (strcmp("-v", argv[1]) == 0);

    char str[NUM_CHARS] = {0};

    if(!check)
        printf("Insert the initial list (in the form of a string):\n");
    fgets(str, NUM_CHARS, stdin);
    str[strcspn(str, "\n")] = '\0';

    struct CharNode* head = NULL;
    struct CharNode* last = head;

    for (size_t i = 0; i < strlen(str); i++) {
        last = insert_after(last, str[i]);
        if (head == NULL)
            head = last;
    }

    if(!check) {
        printf("Initial list: ");
        print_list(head);
    }

    int key = 0;
    if(!check) {
        printf("Insert the cipher key:\n");
    }
    scanf("%d", &key);

    struct CharNode* cipher_head = caesar_cipher(head, key);

    if(!check) {
        printf("Cipher list: ");
    }
    print_list(cipher_head);

    return 0;   
}