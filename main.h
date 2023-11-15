#ifndef _MANAGER_H_
#define _MANAGER_H_

/* __________HEADER FILES__________ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ___________MACROS__________*/
#define BUFF_SIZE 4096



/* ________STRUCTS________ */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

/**
 * struct variable - globl var to sstock the file vars
 * @file: ptr to the file
 * @inst_code: code of current instr
 * @stack: ptr to the ptr inst to the stack.
 * 
 * Description: *----------------------*
 */
typedef struct variable
{
        FILE *file;
        int inst_code;
        stack_t **stack;
        char **array;
        char *line;
} global_var;

typedef void (*function)(stack_t **stack, unsigned int l_num);



/* _________EXTERN VARIABLES_________*/
extern global_var var;



/* __________PROTOTYPES__________ */
stack_t *__insert_start(stack_t **head, int data);
stack_t *__insert_end(stack_t **head, int data);
void __read_file(void);
int __word_count(char *line);
char *__strdup(char *str);
char **__handle_line(char *line);
char **__split_line(char *line);
int __is_num(char *num);
function __find_function(char *opcode);
int __is_ascii(int ascii);

/* ----------ERROR FUNCTIONS ----------*/
void __malloc_error();
void __cannot_open_file();
void __monty_usage();
void __push_error(unsigned int l_num);
void __inst_error(unsigned int l_num, char *opcode);
void __pint_error(unsigned int l_num);
void __pop_error(unsigned int l_num);
void __swap_error(unsigned int line_num);
void __add_error(unsigned int l_num);
void __sub_error(unsigned int l_num);
void __div_error(int type, unsigned int l_num);
void __mul_error(unsigned int l_num);
void __mod_error(int type, unsigned int l_num);
void __pchar_error(int type, unsigned int l_num);

/* --------- INSTRUCTIONS --------- */
void __push(stack_t **stack, unsigned int l_num);
void __pall(stack_t **stack, unsigned int l_num);
void __pint(stack_t **stack, unsigned int l_num);
void __pop(stack_t **stack, unsigned int l_num);
void __swap(stack_t **stack, unsigned int l_num);
void __add(stack_t **stack, unsigned int l_num);
void __nop(stack_t **stack, unsigned int l_num);
void __sub(stack_t **stack, unsigned int l_num);
void __div(stack_t **stack, unsigned int l_num);
void __mul(stack_t **stack, unsigned int l_num);
void __mod(stack_t **stack, unsigned int l_num);
void __pchar(stack_t **stack, unsigned int l_num);
void __pstr(stack_t **stack, unsigned int l_num);
void __rotl(stack_t **stack, unsigned int l_num);
void __rotr(stack_t **stack, unsigned int l_num);

/* --------- MEMORY ---------*/
void __free_array(char **array);
void __free_stack(void);



#endif /* _MANAGER_H_ */
