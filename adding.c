#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
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

    /* Check if there are at least 2 elements to add */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    h = *head;
    aux = h->n + h->next->n;

    /* Update the value of the second element and remove the first */
    h->next->n = aux;
    *head = h->next;
    free(h);
}
