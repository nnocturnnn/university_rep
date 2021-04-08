#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char cheaser_letter(char let, int key) {
    int i = -1;
    char arr_en[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                       'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z', '1'};
    while (arr_en[i++] != '1') {
        if (arr_en[i] == let) {
            if (i - key >= 0)
                return arr_en[i - key];
            else
                return arr_en[(26 + (i - key))];
        }
        if (arr_en[i] == tolower(let)) {
            if (i - key >= 0)
                return toupper(arr_en[i - key]);
            else
                return toupper(arr_en[(26 + (i - key))]);
        }
    }
    return let;
}


int main(int argc, char **argv) {
    int i = 0;

    if (argc < 2) {
        printf("usage: ./reverse \"str\"");
        return 1;
    }
    while (argv[1][i] != '\0') {
        argv[1][i] = cheaser_letter(argv[1][i], 3);
        i++;
    }
    printf("%s\n",argv[1]);
}