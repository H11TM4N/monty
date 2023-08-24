#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a newline
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;  /* Unused parameter */

    h = *head;

    /* Iterate through the stack elements until a non-printable character is encountered or the stack is empty */
    while (h)
    {
        if (h->n > 127 || h->n <= 0)
        {
            break;
        }
        
        /* Print the character represented by the element's value */
        printf("%c", h->n);
        h = h->next;
    }
    
    printf("\n");  /*Print a newline at the end*/ 
}
