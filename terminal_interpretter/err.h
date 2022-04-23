// mityawastaken
// err.h
// friday april 22 2022


#include <stdio.h>

// different errors
//      type error      | code: 1
//      token error     | code: 2 
//      attribute error | :code 3


// all of the different data alluding to errors and how they are displayed
const char *__attr__ = "Attribute error | include an attribute";
const char *__token__ = "Token error | no token provided";
const char *__type__ = "Type Error | datatype unprovided/unsupported";

struct ERR {
    int err_code;
    const char *err_msg;
} type, token, attr;


// attribute error handler
void attribute_error_handler() {
    struct ERR attr = {3, __attr__};
    printf("------\n error code: %d\n", attr.err_code);
    printf("%s\n------\n", attr.err_msg);
}

// 2
void token_error_handler() {
    struct ERR token = {2, __token__};
    printf("------\n error code: %d\n", token.err_code);
    printf("%s\n------\n", token.err_msg); 
}

// 1
void type_error_handler() {
    struct ERR type = {1, __type__};
    printf("------\n error code: %d\n", type.err_code);
    printf("%s\n------\n", type.err_msg); 
}
