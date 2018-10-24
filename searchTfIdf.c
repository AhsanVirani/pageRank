#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int findOccurrence(char *in, char *term);
int wordcount(char *in);
void bubbleSort(float arr[], char **strings, int n);
void swap(float *x, float *y);

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Usage ./searchTfldf 'term/word'\n");
    }
    else {
        char *term = argv[1];
        FILE *fp;
        fp = fopen("./Sample1/collection.txt","r");
        if (fp == NULL) {
            printf("No such file exits");
        }
        char temp[1000];
        char buf[1000];
        memset(buf, '\0', 1000);
        int x = 0;
        int i = 0;
        int y = 0;
        char* urls[100];
        while(fgets(temp,1000,fp) != NULL){           
            for (i = 0; temp[i] != '\0' && temp[i] != '\n'; i++) {
                if (temp[i] != ' ') {
                    buf[x] = temp[i];
                    x++;
                }
                else if (temp[i] == ' ' && buf[0] != '\0') {
                    urls[y] = (char*) malloc(sizeof(buf));
                    strcpy(urls[y], buf);
                    y++;
                    x = 0;
                    memset(buf, '\0', 1000);
                }
            }
            
        }
        fclose(fp);
        int occurrences[y];
        int words[y];
        float termFreq[y];
        int urlsWithTerm = 0;
        x = 0;
        for (x = 0; x < y; x++) {
            char pre[] = "./Sample1/";
            char post[] = ".txt";
            char line[1000];
            strcpy(line, pre);
            strcat(line, urls[x]);
            strcat(line, post);
            words[x] = wordcount(line);
            occurrences[x] = findOccurrence(line, term);
            if (occurrences[x] > 0) {
                urlsWithTerm++;
            }
            termFreq[x] = (float)occurrences[x]/words[x];
        }
        float hold = (float)y/urlsWithTerm;
        float invDocFreq = log10(hold);
        float tFidf[y];
        for (x = 0; x < y; x++) {
            tFidf[x] = termFreq[x] * invDocFreq;
        }
        bubbleSort(tFidf, urls, y);
        for (x = 0; x < y; x++) {
            if (tFidf[x] == 0) continue;
            printf("%s %6f\n",urls[x], tFidf[x]);
        }
    }
}

void swap(float *x, float *y) { 
    float temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void bubbleSort(float arr[], char **strings, int n) { 
   int i, j; 
    for (i = 0; i < n-1; i++) {       
        for (j = 0; j < n-i-1; j++) {     
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j + 1]);
                char temp[1000];
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], temp);
            }
        }
    }
} 

int wordcount(char *in) {
    FILE *fp;
    int count = -2;
    int flag = 0;
    int start = 0;
    char c;
    int hash = 0;
    fp = fopen(in, "r");
    if(fp == NULL) {
        return -1;
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c == '#') {
            hash ++;
            if (hash == 3 && start == 0) {
                start = 1;
            }
            else if (hash > 3 && start == 1) {
                start = 0;
                break;
            }
        }
        else if ((c == ' ' || c == '\n') && flag == 1 && start == 1) {
            count++;
            flag = 0;
        }
        else if (c != '\n' && c != ' ' && start == 1) {
            flag = 1;
        }
    }
    return count;
}
int findOccurrence(char *in, char *term) {
    int count = 0;
    FILE *fp;
    fp = fopen(in,"r");
    if (fp == NULL) {
        return -1;
    }
    char temp[1000];
    while(fgets(temp,1000,fp) != NULL){
        char *p = temp;
        while((p=(strstr(p,term)))!= NULL){
            count++;
            ++p;
        }
    }
    fclose(fp);
    return count;
}


