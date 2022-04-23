// compiler for Introspective-C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test() {
    printf("Testing Token");
}

void remove_char(char *str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

// function for outputting a string
const char *__out(char *string) {
    const char *token_err = "I regret to inform you, but some command you used was invalid";

    if(string[0] == '(' && string[strlen(string)-1] == ')'){
        if(string[1] == '"' && string[strlen(string)-2] == '"'){
            // strcpy(str, string);
            remove_char(string, '(');
            remove_char(string, ')');
            remove_char(string, '"');
            // free(str);
            return string;
        }
        return token_err;
    }
    return token_err;
}

// this main function includes all main compiler stuff
int compiler(char fileName[]) {

        // err code 1 means token does not exist
        typedef struct ERR {
            int err_code;
            char *error;
        } err_singular;

        // opening and compiling the file
        FILE * file;
        file = fopen(fileName, "r");
        char line[256];

        int count = 0;
        while(fgets(line, sizeof(line), file)){
            // checking if someone uses the print function anywhere in the program
            printf("%s", __out(line));

        }


        fclose(file);
    return 0;
}

int main() {
    // get config data... only filename because that's the only needed config data
    FILE * cfgFile;
    cfgFile = fopen("config/compiler.cnf", "r");
    char line[256];

    while(fgets(line, sizeof(line), cfgFile)) {
        compiler(line);
    }
    return 0;
}