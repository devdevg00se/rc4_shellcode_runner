#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define S_LENGTH 256

// Key-scheduling algorithm 
unsigned char* KSA(unsigned char key[]){

    static unsigned char S[S_LENGTH];
    int j = 0;
    int key_length = strlen(key);

    // Initialize S
    for(int i=0; i<S_LENGTH; i++){
        S[i] = i;
    }

    for(int i=0; i<S_LENGTH; i++){
        j = (j + S[i] + key[i % key_length]) % S_LENGTH;

        // Swap values for S[i] and S[j]
        int i_val = S[i];
        S[i] = S[j];
        S[j] = i_val;
    }

    return S;
}

// Pseudo-random generation algorithm
unsigned char* PRGA(int input_length, unsigned char* S){

    unsigned char* K = (unsigned char*) malloc(input_length);  
    int i = 0;
    int j = 0;


    for (int l=0; l < input_length; l++){
        
        i = (i + 1) % S_LENGTH;
        j = (j + S[i]) % S_LENGTH;
        
        // Swap values for S[i] and S[j]
        int i_val = S[i];
        S[i] = S[j];
        S[j] = i_val;

        int t = (S[i] + S[j]) % S_LENGTH;

        K[l] = S[t];

    }

    return K;

}

// Performs rc4 encryption / decryption on a given input with a given key
unsigned char* rc4_encrypt_decrypt(unsigned char input[], int input_length, unsigned char key[], bool print_to_stdout) {

    unsigned char* res = (unsigned char*) malloc(input_length);
    unsigned char* S = KSA(key);
    unsigned char* K = PRGA(input_length, S);

    for (int i=0; i<input_length; i++){
            res[i] = input[i]^K[i];
        }


    // prints result to stdout so that it can be copied
    if (print_to_stdout) {

        printf("%s", "\"");

        for (int i=0; i<input_length; i++){
            
            printf("\\x%02x", res[i]);
            
            if( (i+1) % 14 == 0 || i == input_length-1){
                printf("%s", "\"");
                if (i != input_length-1) {
                    printf("%s", "\n\"");
                } 
            }
        }
    }

    free(K);

    return res;
}