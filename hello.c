#include <ctype.h>
#include <stdio.h>
#include <string.h>

void hello_world(const char *out)
{
    char msg[64] = {0};
    size_t n = 0;
    int word_start = 1;

    for (const char *c = __func__; *c != '\0' && n + 4 < sizeof(msg); ++c) {
        if (*c == '_') {
            msg[n++] = ',';
            msg[n++] = ' ';
            word_start = 1;
            continue;
        }
        msg[n++] = word_start ? (char)toupper((unsigned char)*c) : *c;
        word_start = 0;
    }
    msg[n++] = '!';
    msg[n++] = '!';

    if (strcmp(out, "printf") == 0) printf("%s\n", msg);
}

int main(void)
{
    hello_world("printf");
    return 0;
}
