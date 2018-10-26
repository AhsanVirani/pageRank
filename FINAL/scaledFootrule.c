#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "listoflist.h"

int numurls(char *file);
void geturls(Array A ,char *file);
void swap(int array[] ,int i, int j);
void permute(int array[], int start, int end, List L, int C);
float SFD(List L, int Parray[], int C);
int sizeoflist(List L);
int findC(List L);

float finalRank;
int arrayP[10000];

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Usage ./scaledFootrule 'rankfiles'\n");
    }
    else {
        char* files[100];
        int i = 1;
        int p = 0;
        for (i = 1; i < argc; i++) {
            files[p] = (char*) malloc(sizeof(argv[i]) + 1);
            strcpy(files[p], argv[i]);
            p++;
        }
        List L = newlist();
        for (i = 0; i < p; i++) {
            Array A = newarray(L);
            geturls(A, files[i]);
        }
        int C; 
        C = findC(L);
        int P[C];
        p = 1;
        for (i = 0; i < C; i++) {
            P[i] = p;
            p++;   
        }
        int u = 0;
        char seen[1000];
        memset(seen, '\0', 1000);
        struct rep *curr = L->head;
        char* unique[findC(L)];
        while (curr != NULL) {
            struct node *ptr = curr->first;
            while (ptr != NULL) {
                if (seen[0] == '\0') {
                    strcpy(seen, ptr->value);
                    unique[u] = (char*) malloc(sizeof(ptr->value));
                    strcpy(unique[u], ptr->value);
                    u++;
                }
                else {
                    if (strstr(seen, ptr->value) == NULL) {
                        unique[u] = (char*) malloc(sizeof(ptr->value));
                        strcpy(unique[u], ptr->value);
                        strcat(seen, ptr->value);
                        u++;
                    }
                }
                ptr = ptr->next;
            }
            curr = curr->iterate;
        }
        finalRank = 100;
        permute(P, 0, i, L, C);
        printf("%6f\n", finalRank); 
        for (p = 0; p < i; p++) {
            printf("%s\n", unique[arrayP[p] - 1]);
        } 
    }
}

void geturls(Array A ,char *file) {
    FILE *fp;
    fp = fopen(file,"r");
    if (fp == NULL) {
        printf("No such file exits\n");
        fclose(fp);
    }
    else {
        char temp[1000];
        static char* urls[100];
        int x = 0;
        //collecting all the urls and placing them into an array of strings
        while(fgets(temp,1000,fp) != NULL){  
            int p = 0;
            for (p = 0; temp[p] != '\0'; p++) {
            }        
            urls[x] = (char*) malloc(p);
            strcpy(urls[x], temp);
            urls[x][sizeof(urls[x])] = '\0';
            x++;
        }
        fclose(fp);
        int i = 0;
        for (i = 0; i < x; i++) {
            newnode(A, urls[i]);
        }
    }
}

void swap(int array[] ,int i, int j) {
    int hold = array[i];
    array[i] = array[j];
    array[j] = hold;
}

void permute(int array[], int start, int end, List L, int C) {
    if(start == end) {
        float hold = SFD(L, array, C);
        if (finalRank > hold) {
            finalRank = hold;
            int k;
            for (k = 0; k < end; k++) {
                arrayP[k] = array[k];
            }
        }
        return;
    }
    permute(array, start + 1, end, L, C);
    int i;
    for(i = start + 1; i < end; i++)
    {
        if(array[start] == array[i]) {
            continue;
        }
        swap(array, start, i);
        permute(array, start + 1, end, L, C);
        swap(array, start, i);
    }
}

float SFD(List L, int Parray[], int C) {
    float value = 0;
    struct rep *curr = L->head;
    if (curr == NULL) {
        return 0;
    }
    else {
        int x = 0;
        int index = 0;
        int n = curr->nitems;
        float array[sizeoflist(L)];
        while (curr != NULL) {
            struct node *ptr = curr->first;
            x = 0;
            while (ptr != NULL) {
                float T1 = (float)ptr->pos/n;
                float T2 = (float)Parray[x]/C;
                array[index] = fabs(T1 - T2);
                index++;
                x++;
                ptr = ptr->next;
            }
            curr = curr->iterate;
        }
        for (x = 0; x < index; x++) {
            value += array[x];
        }
        if (value == 0) {
            return 99;
        }
        else {
            return value;
        }
    }
}

int sizeoflist(List L) {
    int count = 0;
    struct rep *curr = L->head;
    while (curr != NULL) {
        struct node *ptr = curr->first;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        curr = curr->iterate;
    }
    return count;
}

int findC(List L) {
    int count = 0;
    struct rep *curr = L->head;
    char string[1000];
    memset(string, '\0', 1000);
    while (curr != NULL) {
        struct node *ptr = curr->first;
        while (ptr != NULL) {
            if (string[0] == '\0') {
                strcpy(string, ptr->value);
                count++;
            }
            else {
                if (strstr(string, ptr->value) == NULL) {
                    count++;
                    strcat(string, ptr->value);
                }
            }
            ptr = ptr->next;
        }
        curr = curr->iterate;
    }
    return count;
}

