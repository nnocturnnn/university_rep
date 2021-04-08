#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *mx_strnew(const int size) {
    if (size < 0) return NULL;
    char *new = malloc(size + 1);
    if (!new) return NULL;
    for (int i = 0; i <= size; i++)
        new[i] = '\0';
    return new;
}

char bacon_letter(char *bac_l) {
    int i;
    char *bacon_str[27] = {"AAAAA","AAAAB","AAABA","AAABB","AABAA","AABAB",
    "AABBA","AABBB","ABAAA","ABAAB","ABABA","ABABB","ABBAA","ABBAB","ABBBA",
    "ABBBB","BAAAA","BAAAB","BAABA","BAABB","BABAA","BABAB","BABBA", "BABBB",
    "BBAAA", "BBAAB","11111"};
    char arr_en[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                       'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z'};
    for (i = 0; bacon_str[i][0] != '1'; i++) {
        if (strcmp(bac_l,bacon_str[i]) == 0) {
            return arr_en[i];
        }
    }
    return ' ';
}

int main(int argc, char **argv) {
    int i = 0;
    int i_buf = 0;
    int i_need = 0;
    char *bac_str;
    char *need_str;
    char *buf_let = mx_strnew(5);

    if (argc < 2) {
        printf("usage: ./reverse \"str\"");
        return 1;
    }
    bac_str = malloc(sizeof(char) * strlen(argv[1]));
    need_str = malloc(sizeof(char) * (strlen(argv[1]) / 5));
    while (argv[1][i] != '\0') {
        if (isupper(argv[1][i]))
            bac_str[i] = 'B';
        else if (islower(argv[1][i]))
            bac_str[i] = 'A';
        else
            bac_str[i] = argv[1][i];
        i++;
    }
    
    // for(i = 0; bac_str[i] != '\0'; i++) {
    //     if (bac_str[i] != ' ') {
    //         buf_let[i_buf] = bac_str[i];
    //         i_buf++;
    //     }
    //     // else
    //     //     need_str[i] = bac_str[i];
    //     if (i_buf == 5) {
    //         printf("%s\n",buf_let);
    //         need_str[i_need] = bacon_letter(buf_let);
    //         i_need++;
    //         i_buf = 0;
    //     }
    // }
    printf("%s\n",bac_str);
    // printf("%s\n",need_str);
}