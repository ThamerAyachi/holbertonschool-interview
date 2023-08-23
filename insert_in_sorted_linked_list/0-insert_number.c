#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    int flag = 0;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;

    if (*head == NULL)
        *head = new;
    else if (current->n >= new->n)
    {
        new->next = current;
        current = new;
        *head = current;
        return (*head);
    }
    else
    {
        while (current->next != NULL && current->next->next != NULL)
        {
            if (current->next->n >= new->n && flag == 0)
            {
                new->next = current->next;
                current->next = new;
                flag = 1;
            }
            current = current->next;
        }
    }

    return (new);
}
