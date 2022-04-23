#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function deletes a character
void kill_char(char *string, char *garbage){
    char *src, *dst;
    for (src = dst = string; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != *garbage) dst++;
    }
    *dst = '\0';
}

int main() {
    char input[255];
    // main user input

    while(1) {
        printf("ic > ");
        scanf("%s", input);

        char deletable_terminal[2] = {'[', ']'};
        char deletable[3] = {'(', ')', '"'};


        if(input[0] == deletable_terminal[0] && input[strlen(input)-1] == deletable_terminal[1]){
            for(int i=0; i<sizeof(deletable_terminal); i++){
                kill_char(input, &deletable_terminal[i]);
            }
            system(input);
        }
        else if(input[0] == '(' && input[strlen(input)-1] == ')'){
            if(input[1] == '"' && input[strlen(input)-2] == '"'){
                for(int i=0; i<sizeof(deletable); i++){
                    kill_char(input, &deletable[i]);
                }
                printf("%s\n", input);
            }
        }

    }
}