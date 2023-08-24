#include "monty.h"

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;

    /* Count the number of elements in the stack */
    while (h)
    {
        h = h->next;
        len++;
    }

    /* Check if there are at least 2 elements to divide */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    /* Check if division by zero would occur */
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    aux = h->next->n / h->n;
	
    /* Update the value of the second element and remove the first */
    h->next->n = aux;
    *head = h->next;
    free(h);
}
