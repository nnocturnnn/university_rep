#include<stdio.h>
#include<string.h>
#include <ctype.h>
 
int main(int argc, char **argv){
    char *msg = argv[1];
    char *key = argv[2];
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    int q  = 0;
    for (int i = 0; msg[i] != '\0'; i++) {
        if (msg[i] != ' ') {
            encryptedMsg[q] = toupper(msg[i]);
            q++;
        }
    }
    encryptedMsg[q] = '\0';
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
    printf("\nEncrypted Message: %s", encryptedMsg);
    newKey[i] = '\0';

    // for(i = 0; i < msgLen; ++i)
    //     encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';

 
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[q] = '\0';

    // printf("Original Message: %s", msg);
    // printf("\nKey: %s", key);
    // printf("\nNew Generated Key: %s", newKey);
    // printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
	return 0;
}