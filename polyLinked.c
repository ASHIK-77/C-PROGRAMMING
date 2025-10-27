#include <stdio.h>
#include <stdlib.h>

// Structure for each term in the polynomial
struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end of a polynomial
void insert(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display the polynomial
void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insert(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insert(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            // Same powers → add coefficients
            insert(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If poly1 has remaining terms
    while (poly1 != NULL) {
        insert(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    // If poly2 has remaining terms
    while (poly2 != NULL) {
        insert(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// ---------- MAIN FUNCTION ----------
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n1, n2, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d%d", &coeff, &pow);
        insert(&poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d%d", &coeff, &pow);
        insert(&poly2, coeff, pow);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}
