#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int findOccurence(char *in, char *term);

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
        int occurences[y];
        x = 0;
        for (x = 0; x < y; x++) {
            char pre[] = "./Sample1/";
            char post[] = ".txt";
            char line[1000];
            strcpy(line, pre);
            strcat(line, urls[x]);
            strcat(line, post);
            occurences[x] = findOccurence(line, term);
        }
    }
}
int wordcount(char *in) {
    FILE *fp;
    int count = 1;
    char c;
    filp = fopen(in, "r");
    if(fp == NULL) {
        return -1;
    }
    while((c = fgetc(fp)) != EOF) {
        if(c == ' ')
            count++;
    }
    return count;
}
int findOccurence(char *in, char *term) {
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


