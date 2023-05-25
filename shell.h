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
#include <unisd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environemnt */
extern char **environm;

char name;

int numb;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/* PROTOTYPES */
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

/*   STRUCTURE */

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
