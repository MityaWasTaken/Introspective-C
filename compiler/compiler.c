// Interpretter for Introspective-C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ping() {
    while(1) {
        int png = system("ping 127.0.0.1");
        printf("%d", png);
    }
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
            count += 1;
            char *function;
            char *ping_token = "ping_home";
            function = strstr(line, ping_token);

            if(function){
                ping();
            } 
            else if(!function){
                break;
                struct ERR err_singular = {1, "The token you tried to use does not exist"};
                printf("error code %d \n", err_singular.err_code);
                printf("%s", err_singular.error);
            }
            else{
                printf("something went wrong :(");
            }

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