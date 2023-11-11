#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFF_FLUSH -1
#define BUFF_SIZE 1024
#define LOWERCASE_CONVERT	1
#define UNSIGNED_CONVERT	2

#define HISTORY_FILE	".simple_shell_history"
#define HISTORY_MAXIMUM	4096
/**
 * struct stringlist - singly linked list
 *
 * @n: the number field
 *
 * @s: a string
 *
 * @next: points to the next node
*/
typedef struct stringlist
{
	int n;
	char *s;
	struct stringlist *next;

} list_type;


/**
 * struct info - contain paseudo args
 *
 * @argument:  arguements
 * @argv: array of strings
 * @p: a string path
 * @argc: argument count
 * @err_count: error count
 * @errn: error code for exits
 * @linecount_f: count this line of input
 * @fname: filename
 * @env: environ
 * @environ: copy of environ
 * @history: history node
 * @alias: alias node
 * @changed_env: when environ changed
 * @status: status of executed command
 * @commd_buff:  command buffer
 * @commd_buf_type: type ||, &&, ;
 * @readfd: fd from to read input
 * @histc: history count
 */
typedef struct info
{
	char *argument;
	char **argv;
	char *p;
	int argc;
	unsigned int err_count;
	int errn;
	int linecount_f;
	char *fname;
	list_type *env;
	list_type *history;
	list_type *alias;
	char **environ;
	int changed_env;
	int status;
	char **commd_buff;
	int commd_buf_type;
	int readfd;
	int histc;
} info_type;

#define INFO_INITIATE \
{NULL, NULL, NULL, 0, 0, 0,\
	0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}

int _strlength(char *s);
int _strcompare(char *s1, char *s2);
char *startwith(const char *word, const char *needle);
char *_strconcat(char *destination, char *source);

char *_strcopy(char *destination, char *source);
char *_strduplicate(const char *string);
void _puts(char *string);
int _putchar(char ch);

char *_stringcopy(char *destination, char *source, int m);
char *_stringconcat(char *s1, char *s2, int m);
char *_stringcharacter(char *string, char ch);

char **stringtow(char *string, char *delimeter);
char **stringtow2(char *string, char delimeter);

int freepointer(void **pointer);
char *_memoryset(char *s, char byte, unsigned int num);
void *_realloc(void *pointer, unsigned int oldsize, unsigned int newsize);
void freestring(char **p);

int is_delimeter(char ch, char *delimeter);
int _erroratoi(char *string);
int interactive_mode(info_type *information);
void error_printing(info_type *information, char *str);
int _isalphabet(int ch);

int _atoi(char *string);
void comment_remove(char *buffer);
int decimal_printing(int input, int fd);
char *number_converting(long int n, int b, int f);

list_type *node_addition(list_type **h, const char *s, int n);
size_t list_length(const list_type *head);
size_t list_printing(const list_type *head);
ssize_t indexNode(list_type *h, list_type *n);
void freeing_list(list_type **ptr);

list_type *node_at_end(list_type **h, const char *s, int index);
char **string_list(list_type *h);
list_type *node_starts(list_type *n, char *p, char ch);
int node_deletion(list_type **h, unsigned int i);
size_t list_printing_string(const list_type *head);

void info_setting(info_type *inform, char **argv);
void info_clearance(info_type *inf);
void info_freeing(info_type *inf, int total);

int _errputchar(char ch);
void _errputs(char *s);
int fd_put(char ch, int fd);
int fd_puts(char *s, int fd);

int myunsetting_environ(info_type *inf);
int mysetting_environ(info_type *inf);
int unsetting_environ(info_type *inf, char *v);
int setting_environ(info_type *inf, char *v, char *val);
int environ(info_type *inf);

char **getting_environ(info_type *inf);
int environ_list_occupy(info_type *inf);
char *getting_environ_value(info_type *inf, const char *n);

int writehistory(info_type *inf);
int readhistory(info_type *inf);

char *gethistory(info_type *inf);
int buildinghistory(info_type *inf, char *buffer, int count);
int history_renumbering(info_type *inf);

int exitfunc(info_type *inf);
int shell_history(info_type *inf);
int change_directory(info_type *inf);

int helpfunc(info_type *inf);
int aliasfunc(info_type *inf);
int alias_printing(list_type *n);

int alias_setting(info_type *inf, char *s);
int alias_unsetting(info_type *inf, char *s);

#endif
