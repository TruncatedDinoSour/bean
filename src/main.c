#include <stdio.h>
#include <curl/curl.h>

#include "commands.c"

int cmd_install(char **);

static const Command cmds[] = {
    {"install", cmd_install},
    {NULL, NULL},
};

int cmd_install(char *argv[]) {
    puts(argv[0]);
    return 0;
}

int main(int argc, char *argv[]) {
    find_command("install", cmds)->cmd(argv);

    return 0;
}
