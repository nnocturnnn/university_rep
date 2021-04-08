#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char reverse_leter(char let) {
    int i = -1;
    char arr_en[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                       'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z', '1'};
    char rev_al[27] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p',
                       'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e',
                       'd', 'c','b', 'a', '1'};
    
    while (arr_en[i++] != '1') {
        if (arr_en[i] == let)
            return rev_al[i];
        if (arr_en[i] == tolower(let))
            return toupper(rev_al[i]);
    }
    return let;
}

int main(int argc, char **argv) {
    int i = 0;

    if (argc < 1) {
        printf("usage: ./reverse \"str\"");
        return 1;
    }
    while (argv[1][i] != '\0') {
        argv[1][i] = reverse_leter(argv[1][i]);
        i++;
    }
    printf("%s\n",argv[1]);
}