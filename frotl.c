#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
    stack_t *tmp = *head, *aux;

    /* If the stack is empty or has only one element, no rotation is needed */
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    aux = (*head)->next;
    aux->prev = NULL;

    /* Find the last node in the stack */
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    /* Rotate the stack by updating pointers */
    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    (*head) = aux;
}
