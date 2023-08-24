#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    /* Check if the argument for push exists */
    if (bus.arg)
    {
        /* Check if the argument is a negative number */
        if (bus.arg[0] == '-')
            j++;

        /* Check if the argument contains non-digit characters */
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > 57 || bus.arg[j] < 48)
                flag = 1;
        }

        /* If there are non-digit characters, print an error and exit */
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* If no argument is provided, print an error and exit */
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    n = atoi(bus.arg);

    /* Depending on the lifo (last in, first out) mode, add to the stack or queue */
    if (bus.lifo == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
