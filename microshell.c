# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>

# define FATAL_ERROR "error: fatal"

typedef struct token_s {
    char **commands;
    int out;
    int in;
    struct token_s *next;
}               token_t;

size_t
_strlen(char * str)
{
    int count = 0;
    for (size_t i = 0; str[i]; i++) {
        count ++;
    }
    return (count);
}

void
_error(char *msg, char *spec, int i) {
    write(2, msg, _strlen(msg));
    if (spec) {
        write(2, spec, _strlen(spec));
    }
    write(2, "\n", 1);
    if (i) {
        exit(1);
    }
}

token_t *
_token_create(
    void )
{
    token_t *tmp;

    tmp = malloc(sizeof(token_t));
    if (!tmp) {
        _error(FATAL_ERROR, NULL, 1);
    }
    tmp->commands = malloc(sizeof(char *) * 1024);
    if (!tmp->commands) {
        _error(FATAL_ERROR, NULL, 1);
    }
    tmp->in = 0;
    tmp->out = 1;
    return (tmp);
}

void
_pipe(
    token_t *token )
{
    int fd[2];

    pipe(fd);
    token->next = _token_create();
    token->out = fd[1];
    token->next->in = fd[0];
}

int
_add(token_t *token, char **av, int i)
{
    int j = 0;

    while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|")) {
        token->commands[j] = av[i];
        i++;
        j++;
    }

    i++;
    token->commands[j] = NULL;

    return (i);
}

void
_exec(token_t *token, int *start, int i, char **env)
{
    int pid;

    if (!strcmp(token->commands[0], "cd")) {
        if (!token->commands[1] || token->commands[2]) {
            _error("error: cd: bad arguments", NULL, 0);
        } else if (chdir(token->commands[1])) {
            _error("error: cd: cannot change ", token->commands[1], 0);
        }
        *start = i;
        return ;
    }

    pid = fork();

    if (pid < 0) {
        _error(FATAL_ERROR, NULL, 1);
    }

    if (pid == 0) {
        if (token->out != 1) {
            close(token->next->in);
            if (dup2(token->out, 1) == -1) {
                _error(FATAL_ERROR, NULL, 1);
            }
        }
        if (token->in != 0) {
            if (dup2(token->in, 0) == -1) {
                _error(FATAL_ERROR, NULL, 1);
            }
        }
        execve(token->commands[0], token->commands, env);
        _error("error: cannot execute ", token->commands[0], 1);
    }
    if (token->in != 0) {
        close(token->in);
    }
    if (token->out != 1) {
        close(token->out);
    } else {
        while (*start < i) {
            waitpid(0, NULL, 0);
            (*start)++;
        }
    }
}

int
main(
    int ac, char **av, char **env )
{
    token_t *token;

    int i = 1, start = 1;
    token_t *last_token;

    while (i < ac) {

        if (!token || start == i) {
            token = _token_create();
        }

        if (!strcmp(av[i], ";")) {
            i++;
            continue ;
        }

        i = _add(token, av, i);

        if (av[i - 1] && !(strcmp(av[i - 1], "|"))) {
            _pipe(token);
        }

        _exec(token, &start, i, env);

        last_token = token;

        if (token->out != 1) {
            token = token->next;
        }
        
        free(last_token->commands); last_token->commands = NULL;
        free(last_token); last_token = NULL;
    }

    return (EXIT_SUCCESS);
}
