#include "monty.h"

/** Global bus structure to store information **/
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    /** Check if the correct number of arguments is provided **/
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /** Open the Monty code file for reading **/
    file = fopen(argv[1], "r");
    bus.file = file;

    /** Check if the file can be opened **/
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /** Read Monty code line by line and execute it **/
    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        bus.content = content;
        counter++;

        if (read_line > 0)
        {
            /** Call the execute function to interpret and execute Monty code **/
            execute(content, &stack, counter, file);
        }

        /** Free memory allocated for the content of the line **/
        free(content);
    }

    /** Free memory used by the stack and close the file **/
    free_stack(stack);
    fclose(file);

    return (0);
}
