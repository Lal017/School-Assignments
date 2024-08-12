grammar Interpreter;

start   :
    expression EOF
    ;

expression
    :
    |   INT
    |   FLOAT
    |   DOUBLE
    |   BOOL
    |   COMMENT
    |   WHITESPACE
    |   expression (MUL | DIV ) expression
    |   expression (PLUS | MINUS ) expression
    |   OPENPAR expression CLOSEPAR
    ;

    MUL     :   '*';
    DIV     :   '/';
    PLUS    :   '+';
    MINUS   :   '-';
    INT     :   '0'..'9'+;
    FLOAT   :   INT '.' INT;
    DOUBLE  :   INT '.' INT;
    BOOL    :   'true' | 'false';
    WHITESPACE  :   ' ';
    CHAR    :   'a'..'z'+ | 'A'..'Z'+;
    COMMENT :   '//' (~'\n')*;
    OPENPAR :   '(';
    CLOSEPAR:   ')';