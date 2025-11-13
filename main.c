#include <stdio.h>
#include <stdlib.h>

struct node {
    int co, po;
    struct node *addr;
};
typedef struct node* NODE;

NODE insertend(NODE head, int co, int po)
{
    NODE temp, cur;
    temp = (NODE) malloc (sizeof(struct node));
    if (!temp) { perror("malloc"); exit(EXIT_FAILURE); }
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if (head == NULL)
        return temp;
    cur = head;
    while (cur->addr != NULL)
        cur = cur->addr;
    cur->addr = temp;
    return head;
}

void display(NODE head)
{
    NODE cur = head;
    if (cur == NULL) {
        printf("0\n");
        return;
    }
    while (cur != NULL)
    {
        printf("%d*x^%d", cur->co, cur->po);
        cur = cur->addr;
        if (cur != NULL)
            printf(" + ");
    }
    printf("\n");
}

NODE addterm(NODE res, int co, int po)
{
    NODE temp, cur;
    temp = (NODE) malloc (sizeof(struct node));
    if (!temp) { perror("malloc"); exit(EXIT_FAILURE); }
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if (res == NULL)
        return temp;

    cur = res;
    while (cur != NULL)
    {
        if (cur->po == po)
        {
            cur->co += co;
            return res;
        }
        cur = cur->addr;
    }
    res = insertend(res, co, po);
    return res;
}

NODE multiply(NODE poly1, NODE poly2)
{
    NODE P1, P2, res = NULL;
    for (P1 = poly1; P1 != NULL; P1 = P1->addr)
    {
        for (P2 = poly2; P2 != NULL; P2 = P2->addr)
        {
            res = addterm(res, P1->co * P2->co, P1->po + P2->po);
        }
    }
    return res;
}

int main()
{
    NODE poly1 = NULL, poly2 = NULL, poly = NULL;
    int co, po, i, n;

    printf("Enter no of terms of 1st polynomial: ");
    if (scanf("%d", &n) != 1) return 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient & power of term %d: ", i + 1);
        if (scanf("%d%d", &co, &po) != 2) return 0;
        poly1 = insertend(poly1, co, po);
    }
    printf("First Polynomial: ");
    display(poly1);

    printf("Enter no of terms of 2nd Polynomial: ");
    if (scanf("%d", &n) != 1) return 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient & power of term %d: ", i + 1);
        if (scanf("%d%d", &co, &po) != 2) return 0;
        poly2 = insertend(poly2, co, po);
    }
    printf("Second Polynomial: ");
    display(poly2);

    poly = multiply(poly1, poly2);
    printf("Resultant Polynomial after multiplication is:\n");
    display(poly);

    return 0;
}
