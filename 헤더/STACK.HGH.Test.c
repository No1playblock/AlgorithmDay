#include <stdio.h>
#include <stdlib.h>
#include "STACK_HGH.h"

enum menu {
    PUSH = 1,
    POP,
    PEEK,
    PRINT,
    EXIT
};

void printMenu();
void inputData(Data *data);
void printData(Data data);

char dataType = FLOAT;

int main()
{
    Stack stk;

    StackInit(&stk, dataType);

    while (1) {
        int n;
        Data data;
        
        printMenu();
        scanf("%d", &n);

        switch (n) {
            case PUSH:
                printf("���� �Է��ϼ���: ");
                inputData(&data);
                Push(&stk, data);
                break;
            case POP:
                data = Pop(&stk);
                printData(&data);
                break;
            case PEEK:
                data = Peek(&stk);
                printData(&data);
                break;
            case PRINT:
                PrintStack(&stk);
                break;
            case EXIT:
                exit(0);
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
    puts("5. Exit");
    puts("===================");

    printf("�޴��� �����ϼ���: ");
}

void inputData(Data *data)
{
    if (dataType == CHAR) scanf("%s", data);
    else if (dataType == SHORT) scanf("%hd", data);
    else if (dataType == INT) scanf("%d", data);
    else if (dataType == FLOAT) scanf("%f", data);
    else scanf("%lf", data);
}

void printData(Data data)
{
    if (dataType == CHAR) printf("Returned data: %s\n", (char*)data);
    else if (dataType == SHORT) printf("Returned data: %hd\n", *(short*)data);
    else if (dataType == INT) printf("Returned data: %d\n", *(int*)data);
    else if (dataType == FLOAT) printf("Returned data: %f\n", *(float*)data);
    else printf("Returned data: %lf\n", *(double*)data);
}