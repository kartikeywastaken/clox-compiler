#include <stdio.h>   // for FILE, fopen, fclose, printf, fgetc
#include <stdlib.h>  // for general utilities (not really used here, but fine to include)
#include <ctype.h>   // for isspace(), isalpha(), isdigit()

// ---------------- ENUMS ----------------

// Keywords for your language (right now, only EXIT)
typedef enum {
    EXIT, // enum starts at 0 by default
} TypeKeyword; 

// Literals like int, float, string
typedef enum {
    INT,    // 0
    FLOAT,  // 1
    STRING, // 2
} TypeLiteral;

// Separators like ; (semicolon), ( (open paren), ) (close paren)
typedef enum {
    SEMI,        // 0
    OPEN_PARAN,  // 1
    CLOSE_PARAN, // 2
} TypeSeparator;

// ---------------- TOKEN STRUCTS ----------------

// Represents a literal token (like a number)
typedef struct {
    TypeLiteral type; // type of literal (INT, FLOAT, STRING)
    int value;        // numeric value (for now only int is stored)
} TokenLiteral;

// Represents a keyword token (like EXIT)
typedef struct {
    TypeKeyword type; // type of keyword
} TokenKeyword;

// Represents a separator token (like ;, (, ))
typedef struct {
    TypeSeparator type; // type of separator
} TokenSeparator;

// ---------------- HELPER FUNCTION ----------------

// Skips over whitespace characters (spaces, tabs, newlines) in the file
void whiteSpace(FILE *file, char *current) {
    while (isspace(*current)) {
        // overwrite the variable at *current with the next character from file
        *current = fgetc(file);
    }

    // NOTES ABOUT POINTERS:
    // When you pass a plain char, the function gets a copy of the value.
    // That copy lives in a different memory location inside the function.
    // If you change it, you’re only changing the copy — the original variable in the caller’s memory is untouched.
    // When you pass a char *, the function gets the address of the original variable.
    // Inside the function, *current directly refers to the caller’s variable.
    // If you change *current, you are changing the caller’s variable at its actual memory location.
}

// ---------------- LEXER FUNCTION ----------------

// Reads through the file character by character and identifies tokens
void lexer(FILE *file) {
    char current = fgetc(file);  // read first character from file

    // keep looping until end of file (EOF is -1)
    while (current != EOF) {

        // skip whitespace characters (space, tab, newline, etc.)
        whiteSpace(file, &current);

        // check for separators
        if (current == ';') {
            printf("SEMICOLON located!\n");
            current = fgetc(file);

        } else if (current == '(') {
            printf("OPEN PARENTHESIS located!\n");
            current = fgetc(file);

        } else if (current == ')') {
            printf("CLOSE PARENTHESIS located!\n");
            current = fgetc(file);

        // check for alphabetic characters (keywords, identifiers)
        } else if (isalpha(current)) {
            printf("CHARACTER FOUND: %c\n", current);
            current = fgetc(file);

        // check for numbers (digits)
        } else if (isdigit(current)) {
            int value = 0;

            // loop through multi-digit numbers (e.g., 123)
            while (isdigit(current)) {
                // build the integer value
                value = value * 10 + (current - '0');
                current = fgetc(file);
            }

            printf("INTEGER FOUND: %d\n", value);
            // current is already the first non-digit after the loop
        }

        // If it's not whitespace, not alpha, not digit, not separators,
        // the loop just continues — you might want to handle errors later
    }
}

// ---------------- MAIN FUNCTION ----------------

int main() {
    FILE *file;
    file = fopen("test.my", "r");  // open test file for reading
    if (!file) {
        printf("Error: could not open file.\n");
        return 1; // exit if file doesn't exist
    }

    lexer(file);   // call lexer to process tokens
    fclose(file);  // close the file when done
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    TokenKeyword,
    TokenLiteral,
    TokenSeparator,
}TokenType;

typedef struct {
    TokenType type;
}TokenValue;

typedef enum {
    EXIT, // has value 0 assigned to it 
} TypeKeyword; 

typedef enum {
    INT,
    FLOAT,
    STRING,
} TypeLiteral;

typedef enum {
    SEMI,
    OPEN_PARAN,
    CLOSE_PARAN,
} TypeSeparator;

typedef struct
{
    TypeLiteral type;
    int value;
}TokenLiteral;

typedef struct
{
    TypeKeyword type;
}TokenKeyword;

typedef struct
{
    TypeSeparator type;
}TokenSeparator;

void whiteSpace(FILE*file,char* current ){
    while (isspace(*current))
    { // simply put to overwrite the current varaible we must directly access its memory location
        *current = fgetc(file);
    }
    // When you pass a plain char, the function gets a copy of the value.
    // That copy lives in a different memory location inside the function.
    // If you change it, you’re only changing the copy — the original variable in the caller’s memory is untouched.
    // When you pass a char *, the function gets the address of the original variable.
    // Inside the function, *current directly refers to the caller’s variable.
    // If you change *current, you are changing the caller’s variable at its actual memory location.
}

void lexer(FILE * file){
    char current = fgetc(file);
    whiteSpace(file, &current);
    while (current != EOF)
    {
        // printf("%c", current); //prints the character present in the file line by line 
        // current = fgetc(file);
        if (current == ';')
        {
            printf("SEMICOLON located!\n");
            current = fgetc(file);
        } else if (current == '(')
        {
            printf("OPEN PARANTHESIS located!\n");
            current = fgetc(file);
        } else if (current == ')')
        {
            printf("CLOSE PARANTHESIS located!\n");
            current = fgetc(file);
        }
        else if (isalpha(current))
        {
            printf("CHARACTER FOUND: %c\n", current);
            current = fgetc(file);
        } else if((isdigit(current)))
        {int value = 0;
         while(isdigit(current))
        {
            // printf("INTEGER FOUND: %d\n", current - '0');
            // printing a double digit number
            value = value*10 + (current-'0');
            current = fgetc(file);
        } 
        printf("INTEGER FOUND: %d\n", value);
        current = fgetc(file);
        }
    }
}

int main(){
    FILE *file;
    file = fopen("test.my", "r");
    lexer(file);
    fclose(file);
    return 0;
}
