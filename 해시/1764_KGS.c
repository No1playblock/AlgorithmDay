#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node {
    char name[21];
    int num;
    struct __node *next;
} Node;

typedef struct __ChainHash {
    Node **table;
} ChainHash;

int MapInit(ChainHash *m) {
    m->table = calloc(100, sizeof(Node *)); // �ҹ��� = 26��

    for (int i = 0; i < 27; i++)
        m->table[i] = NULL;

    return 0;
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
        if (p->num == 1)
            printf("%s\n", p->name);
        
        p = p->next;
    }
        
    return 0;
}

int main() {
    int i, l, pass;
    char name[21];
    ChainHash Map;
    Node *NewNode;

    MapInit(&Map);


    scanf(" %d %d", &i, &l);

    // ��
    while (i--) {
        scanf(" %s", name);

        pass = 0;
        int HP = Hash(name); // �ؽ� -> ��ġ ����

        NewNode = calloc(1, sizeof(Node));
        strcpy(NewNode->name, name);
        NewNode->num = 0;
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
                pass = 1;
                break;
            }

            p = p->next;
        }

        if (pass == 0) {
            p->next = NewNode;
        }
    }

    // �˻�
    while (l--) {
        scanf(" %s", name);

        int HP = Hash(name);
        Node *p = Map.table[HP];

        // ���� ã��
        while (p != NULL) {
            // ������ ���� ���
            if (strcmp(name, p->name) == 0) {
                p->num = 1;
                pass = 1;
                break;
            }

            p = p->next;
        }
    }


    // ���
    for (int i = 0; i < 26; i++) {
        PrintMap(Map.table[i]); 
    }

    return 0;
}