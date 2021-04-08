#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char check_let(char *buf) {
    int i;
    if (strcmp(buf,".....") == 0)
        return '.';
    char arr_en[28] = {'a', 'b', 'w', 'g', 'd', 'e', 'v', 'z', 'i', 'j', 'k', 
    'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'f', 'h', 'c', 'q', 'y', 'x'};
    char dec[28][5] = {".-", "-...", ".--", "--.", "-..", ".", "...-", "--..", 
    "..", ".---","-.-", ".-..", "--", "-.", "---",".--.", ".-.", "...", "-", 
    "..-", "..-.", "....", "-.-.", "--.-", "-.--", "-..-",'1'};
    for (i = 0; dec[i][0] != '1'; i++) {
        if (strcmp(buf,dec[i]) == 0) {
            return arr_en[i];
        }
    }
    return ' ';
}

int main(int argc, char **argv) {
    int i = 0;
    int k = 0;
    char *buf = malloc(sizeof(char) * 5);
    char *full_str = malloc(sizeof(char) * 20);
    int q = 0;

    if (argc < 1) {
        printf("usage: ./morse \"str\"");
        return 1;
    }
    while (argv[1][i] != '\0') {
        if (argv[1][i] == ' ' || argv[1][i] == '\n') {
            full_str[k] = check_let(buf);
            memset(buf,'\0',5);
            k++;
            i++;
            q = 0;
        }
        if (argv[1][i] == ' ' && argv[1][i + 1] == ' ') {
            full_str[k] = ' ';
            k++;
            i += 6;
        }
        else {
        buf[q] = argv[1][i];
        q++;
        i++;
        }
    }
    full_str[k] = check_let(buf);
    for (i = 0; full_str[i] != '\0'; i++) {}
    full_str[i] = '\n';
    printf("%s",full_str);
}