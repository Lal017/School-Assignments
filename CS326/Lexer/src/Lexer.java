import java.io.*;
import java.util.Hashtable;

public class Lexer {
    public static BufferedReader buffer;                                                // Reads in a character
    public static boolean EOF = false;                                                  // Check if reached End of file
    public static int curr_token;                                                       // Sets the status of the current char (NUMBER, LETTER, WHITESPACE, OTHER)
    public static final int NUMBER = 0, LETTER = 1, WHITESPACE = 2, OTHER = 3;          // Values to set the status of curr_token
    public static final int IDENTIFIER_CHANNEL = 0, WHITESPACE_CHANNEL = 1, COMMENTS_CHANNEL = 2;  // Used to set the current channel
    public static int curr_channel;                                                     // determines what channel we are currently on
    public static StringBuilder lex_string = new StringBuilder();                       // holds the current string
    public static char curr_char;                                                       // Holds the current char read in from buffer
    static Hashtable<String, Integer> keywords = new Hashtable<>();                     // Stores keywords and category number

    public static void fill_map()                                                       // Used to fill the hashmap with keywords
    {
        String[] keyword_arr = {"class", "output", "on", "create", "constant", "elseif", "me", "until", "public",
                            "private", "alert", "detect", "always", "check", "parent", "blueprint", "system",
                            "is", "cast", "input", "say", "now", "while", "package", "times", "repeat", "else",
                            "returns", "return", "and", "or", "undefined", "shared", "action", "integer", "number",
                            "text", "boolean", "use", "not", "Not", "mod", "if", "end", "true", "false"};
        int size1 = keyword_arr.length;
        for(int i = 0; i < size1; i++)
        {
            keywords.put(keyword_arr[i],i+2);
        }
    }

    public static void other_print() throws IOException                                 // If current token is OTHER, prints to console
    {
        switch (curr_char)                                                              // Switch to locate correct token
        {
            case '/' -> {
                buffer.mark(2);
                next_char();
                if (curr_char == '/') {
                    curr_channel = COMMENTS_CHANNEL;
                    while (curr_char != '\r') {
                        next_char();
                        if (EOF)
                            break;
                        if (curr_char != '\r')
                            lex_string.append(curr_char);
                    }
                    System.out.println("Token Category: 48, comment, value \"" + lex_string + '"');
                } else if (curr_char == '*') {
                    curr_channel = COMMENTS_CHANNEL;
                    while (!EOF) {
                        next_char();
                        if (curr_char == '*') {
                            next_char();
                            if (curr_char == '/') {
                                System.out.println("Token Category: 68, multi-line comment, value \"" + lex_string + '"');
                                return;
                            } else
                                lex_string.append('*');
                        }
                        lex_string.append(curr_char);
                    }
                    System.out.println("Error: expected end (*/) not found.");
                } else {
                    curr_channel = IDENTIFIER_CHANNEL;
                    buffer.reset();
                    System.out.println("Token Category: 49, division, value \"/\"");
                }
            }
            case ':' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 50, colon, value \"" + curr_char + '"');
            }
            case '.' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 51, period, value \"" + curr_char + '"');
            }
            case ',' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 52, comma, value \"" + curr_char + '"');
            }
            case '=' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 53, equals, value \"" + curr_char + '"');
            }
            case '>' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                buffer.mark(2);
                next_char();
                if (curr_char == '=')
                    System.out.println("Token Category: 54, greater than or equal to, value \">=\"");
                else {
                    buffer.reset();
                    System.out.println("Token Category: 55, greater than, value \">\"");
                }
            }
            case '<' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                buffer.mark(2);
                next_char();
                if (curr_char == '=')
                    System.out.println("Token Category: 56, less than or equal to, value \"<=\"");
                else {
                    buffer.reset();
                    System.out.println("Token Category: 57, less than, value \"<\"");
                }
            }
            case '+' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 58, plus, value \"" + curr_char + '"');
            }
            case '-' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 59, minus, value \"" + curr_char + '"');
            }
            case '*' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 60, multiply, value \"" + curr_char + '"');
            }
            case '[' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 61, left bracket, value \"" + curr_char + '"');
            }
            case ']' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 62, right bracket, value \"" + curr_char + '"');
            }
            case '(' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 63, left parenthesis, value \"" + curr_char + '"');
            }
            case ')' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                System.out.println("Token Category: 64, right parenthesis, value \"" + curr_char + '"');
            }
            case '"' -> {
                curr_channel = IDENTIFIER_CHANNEL;
                next_char();
                while (curr_char != '"') {
                    if (curr_char == '\n' || curr_char == '\r') {
                        System.out.println("Error: Expected end quote (\") not found.");
                        return;
                    }
                    lex_string.append(curr_char);
                    next_char();
                }
                System.out.println("Token Category: 65, Double Quote, value \"" + lex_string + '"');
            }
            default -> System.out.println("Error: Invalid Token");
        }
    }

    public static void keyword_print() throws IOException                                                          // Determines if token is a Keyword or Identifier and prints to console
    {
        if(keywords.containsKey(lex_string.toString()))
        {
            if(lex_string.toString().equals("not") && curr_char == '=')
            {
                System.out.println("Token Category: 69, not equals, value \"" + lex_string + "=\"");
                next_char();
            }
            else
                System.out.println("Token Category: " + keywords.get(lex_string.toString()) + ", " + lex_string + " keyword, value \"" + lex_string + '"');
        }
        else
        {
            System.out.println("Token Category: 1, identifier, value \"" + lex_string + '"');
        }
    }

    public static void next_char() throws IOException                                          // Read in a char from buffer and determine its state (NUMBER, LETTER, WHITESPACE, OTHER)
    {
        int ASCII_char = buffer.read();
        curr_char = (char) ASCII_char;
        if(ASCII_char == -1)
        {
            EOF = true;
            return;
        }

        if(curr_char >= '0' && curr_char <= '9')
        {
            curr_token = NUMBER;
            curr_channel = IDENTIFIER_CHANNEL;
        }
        else if(curr_char >= 'a' && curr_char <= 'z' || curr_char >= 'A' && curr_char <= 'Z' || curr_char == '_')
        {
            curr_token = LETTER;
            curr_channel = IDENTIFIER_CHANNEL;
        }
        else if(curr_char == ' ' || curr_char == '\n' || curr_char == '\t' || curr_char == '\r')
        {
            curr_token = WHITESPACE;
            curr_channel = WHITESPACE_CHANNEL;
        }
        else
        {
            curr_token = OTHER;
        }
    }

    public static void lexing() throws IOException                                          // Determines what kind of token you are reading
    {
        switch (curr_token) {
            case NUMBER -> {
                boolean has_decimal = false;
                while (curr_token == NUMBER || curr_char == '.') {
                    if (EOF)
                        break;
                    if (curr_char == '.')
                        has_decimal = true;
                    lex_string.append(curr_char);
                    next_char();
                }
                if (has_decimal)
                    System.out.println("Token Category: 66, number, value \"" + lex_string + '"');
                else
                    System.out.println("Token Category: 67, integer, value \"" + lex_string + '"');
            }
            case LETTER -> {
                while (curr_token == LETTER || curr_token == NUMBER) {
                    if (EOF)
                        break;
                    lex_string.append(curr_char);
                    next_char();
                }
                if(lex_string.charAt(lex_string.length()-1) == '_')
                    System.out.println("Error: Identifier may not end with (_) character value");
                else
                    keyword_print();
            }
            case WHITESPACE -> {
                curr_channel = WHITESPACE_CHANNEL;
                next_char();
                if (!EOF)
                    lexing();
            }
            case OTHER -> {
                other_print();
                next_char();
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        if(args.length < 1)                                     // if no argument is entered
        {
            System.out.println("Error, Must enter a folder");
            return;
        }


        fill_map();                                             // fill hashmap with keywords
        File folder = new File(args[0]);
        File[] file_list = folder.listFiles();
        assert file_list != null;
        for(File curr_file : file_list) {
            FileReader file = new FileReader(curr_file);
            buffer = new BufferedReader(file);
            System.out.println("\nInput: " + curr_file.getName() + "\nOutput: ");
            next_char();
            EOF = false;
            do {                                                    // loop until reaches end of file
                lexing();
                lex_string.delete(0,lex_string.length());           // resets string value
            } while (!EOF);
        }
    }
}
