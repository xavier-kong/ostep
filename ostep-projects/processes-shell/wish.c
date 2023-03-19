#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>

/*https://stackoverflow.com/a/122721*/
size_t trimwhitespace(char *out, size_t len, const char *str) {
    if(len == 0)
        return 0;

    const char *end;
    size_t out_size;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
    {
        *out = 0;
        return 1;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end++;

    // Set output size to minimum of trimmed string length and buffer size minus 1
    out_size = (end - str) < len-1 ? (end - str) : len-1;

    // Copy trimmed string and add null terminator
    memcpy(out, str, out_size);
    out[out_size] = 0;

    return out_size;
}

char * parseCommands(char buff[99999], int *num_comm_p) {
    size_t len = 16;
    char **commands = malloc(len * sizeof(char *));

    char *mainString;
    int i = 0;

    while((mainString = strsep(&buff, "&")) != NULL) {
        if (i == len) {
            len *= 2;
            commands = realloc(commands, len * sizeof(char *));
        }

        char *subString;
        int j = 0;
        size_t sub_arr_len = 1;

        *num_comm_p += 1;

        char **sub = malloc(sub_arr_len * sizeof(char *));

        while((subString = strsep(&mainString, " ")) != NULL) {
            if (j == sub_arr_len) {
                len += 2;
                sub = realloc(sub, sub_arr_len * sizeof(char *));
            }
                trimwhitespace(sub[j], 99999, subString);
            j++;
        }

        if (j == len) {
            len += 2;
            sub = realloc(sub, sub_arr_len * sizeof(char *));
        }

        sub[j] = NULL;

        commands[i] = *sub;
        i++;
    }

    return *commands;
}

void runCommand(char **argv) {
    int pid = fork();

    /*printf("%s", argv[0]);
      printf("%s", argv[1]);
      printf("%s", argv[2]);*/
    return;

    if (pid < 0) {
        fprintf(stderr, "fork failure\n");
        exit(1);
    } else if (pid == 0) { // child
        execvp(argv[0], argv);
    } else {
        int status = 0;
        waitpid(pid, &status, WUNTRACED);
        if (status < 0) {
            fprintf(stderr, "error with child\n");
            exit(1);
        }
    }
}

int runInteractive() {
    char buff[99999];

    while (1) {
        printf("wish> ");

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            return 0;
        }

        buff[strlen(buff) - 1] = '\0';

        if (strcmp(buff, "exit") == 0) {
            return 0;
        }

        int num_commands = 1;

        char *commands = parseCommands(buff, &num_commands);

        // make parseCommands return an array of arrays
        // iterate through arrays and run command each time

        runCommand(&commands);

        /*if (num_commands == 1) {
          runCommand(&commands[0]);
          }*/
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) { // interactive mode
        int status = runInteractive();
        exit(status);
    } else if (argc == 2) { // batch mode
    }
}

