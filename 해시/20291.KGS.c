#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node {
    char name[101];
    int num;
    struct __node *next;
} Node;

typedef struct __ChainHash {
    Node **table;
} ChainHash;

int MapInit(ChainHash *m) {
    m->table = calloc(27, sizeof(Node *)); // �ҹ��� = 26��

    for (int i = 0; i < 27; i++)
        m->table[i] = NULL;

    return 0;
}

char* PassingExtension(char *file) {
    strtok(file, "."); // �� �κ� ����

    return strtok(NULL, ".");
}

int Hash(char* filename) {
    int HashTemp = (int)filename[0] % 97;

    if (HashTemp > 25)
        return 26;

    return HashTemp;
}

int PrintMap(const Node *p) {
    
    // ������ �� ������ ���
    while (p != NULL) {
        printf("%s %d\n", p->name, p->num);
        p = p->next;
    }
        
    return 0;
}

int main() {
    int i, pass;
    char filename[101];
    ChainHash Map;
    Node *NewNode;

    scanf(" %d", &i);
    MapInit(&Map);
    

    while (i--) {
        scanf(" %s", filename);

        pass = 0;
        char *PE = PassingExtension(filename); // Ȯ���� �̸�
        int HP = Hash(PE); //�� ��ġ ����

        NewNode = calloc(1, sizeof(Node));
        strcpy(NewNode->name, PE);
        NewNode->num = 1;
        NewNode->next = NULL;
        
        Node *p = Map.table[HP];

        // ���� ���
        if (p == NULL) {
            Map.table[HP] = NewNode;
            continue;
        }

        // ������ �ֱ�
        while (p != NULL) {
            // ������ ���� ���
            if (strcmp(NewNode->name, p->name) == 0) {
                p->num++;
                pass = 1;
                break;
            }

            p = p->next;
        }

        if (pass == 0)
            p->next = NewNode;
    }

    // ���
    for (int i = 0; i < 26; i++) {
        PrintMap(Map.table[i]); 
    }

    return 0;
}