#ifndef SHELL_H
#define SHELL_H
/*     MOOD      */
void interaction_mood(void);
void nor_interaction_mood(void);

/*     SIZE     */
extern char **environ;
#define MAX_NUM 10
#define MAX_LENGHT 256
#define BUFFER_SIZE 1024

/*  HEADERFILE  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*---PROTOTYPES---*/
char *read_stdin(void);
char *read_stream(void);
char **tokenis(char *num);
int excutcmd(char **code);
void errors(char *s);
char *_sridup(char *sri);
int _strine(const char *c);
int _strncode(const char *sri1, const char *sri2, int n);
char *_netenvir(const char *form);
void error(int statiss, char **s, int j);
void _item(int sum, char *sri);
char *_strcmds(char *test, char *snc);
int end(char **code);
char *_strcopy(char *test, char *src);
int env(char **code);
char *_strike(char *sri, char *decline);

/*---STRUCTRES---*/
/**
 * struct built - structure for builtins.
 * @name: name of the builtin.
 * @f: function prntotype.
 */
typedef struct built
{
	char *form;
	int (*f)(char **);
} built_in;

#endif
