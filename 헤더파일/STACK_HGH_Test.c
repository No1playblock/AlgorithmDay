#include <stdio.h>
#include "STACK_HGH.h"

enum menu {
    PUSH = 1,
    POP,
    PEEK,
    PRINT
};

void printMenu();

int main()
{
    Stack stk;

    StackInit(&stk);

    while (1) {
        int n;
        Data data;
        
        printMenu();
        scanf("%d", &n);
        if (n == -9999) break;

        switch (n) {
            case PUSH:
                printf("���� �Է��ϼ���: ");
                scanf("%d", &data);
                Push(&stk, data);
                break;
            case POP:
                data = Pop(&stk);
                printf("Returned data: %d\n", data);
                break;
            case PEEK:
                data = Peek(&stk);
                printf("Returned data: %d\n", data);
                break;
            case PRINT:
                PrintStack(&stk);
                break;
        }
    }
    
    return 0;
}

void printMenu()
{
    putchar('\n');
    puts("===================");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Peek");
    puts("4. Print");
    puts("===================");

    printf("�޴��� �����ϼ���(����: -9999): ");
}