grammar Interpreter;

start   :
    expression EOF
    ;

expression
    :   control
    |   INT
    |   FLOAT
    |   BOOL
    |   COMMENT
    |   whitespace
    |   expression (MUL | DIV ) expression
    |   expression (PLUS | MINUS ) expression
    |   OPENPAR expression CLOSEPAR
    ;

control
    :   'if' '(' compare ')' expression+ '}' ('else' expression+ '}')?     // if else
    |   'repeat' '(' (INT | compare) ')' expression+ '}'                   // "while" loop equivalent.
    ;

whitespace
    :   NEWLINE
    |   SPACE
    ;

compare
    :   BOOL
    |   INT (LESS | LESSEQUAL | GREATER | GREATEQUAL | EQUAL) INT
    ;

    MUL     :   '*';
    DIV     :   '/';
    PLUS    :   '+';
    MINUS   :   '-';
    INT     :   '0'..'9'+;
    FLOAT   :   INT '.' INT;
    BOOL    :   'true' | 'false';
    CHAR    :   'a'..'z'+ | 'A'..'Z'+;
    COMMENT :   '//' (~'\n')*;
    OPENPAR :   '(';
    CLOSEPAR:   ')';
    LESS:       '<';
    LESSEQUAL:  '<=' | '=<';
    GREATER:    '>';
    GREATEQUAL: '>=' | '=>';
    EQUAL:      '=';

    NEWLINE: [ \n]+ -> channel(HIDDEN);
    SPACE:  [ \t]+ -> channel(HIDDEN);