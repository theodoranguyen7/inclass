#define SCAN_TOKEN_LEN 32
#define SCAN_TOKEN_TABLE_LEN 1024

enum scan_token_enum {
    TK_INTLIT, /* -123, 415 */
    TK_BINLIT, /* 0b10, 0b1001 */
    TK_HEXLIT, /* 0x7f, 0x12ce */
    TK_LPAREN, /* ( */
    TK_RPAREN, /* ) */
    TK_PLUS,   /* + */
    TK_MINUS,  /* - */
    TK_MULT,   /* * */
    TK_DIV,    /* / */
    TK_EOT,    /* end of text */
};

#define SCAN_STRINGS {\
    "TK_INTLIT",\
    "TK_BINLIT",\
    "TK_HEXLIT",\
    "TK_LPAREN",\
    "TK_RPAREN",\
    "TK_PLUS",\
    "TK_MINUS",\
    "TK_MULT",\
    "TK_DIV",\
    "TK_EOT"\
};

struct scan_token_st {
    enum scan_token_enum id;
    char name[SCAN_TOKEN_LEN];
};

struct scan_table_st {
    struct scan_token_st table[SCAN_TOKEN_TABLE_LEN];
    int len;
};
