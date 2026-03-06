#include "lists.h"

/**
 * reverse_list - reverses a singly linked list
 * @head: head of list to reverse
 *
 * Return: new head
 */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *prev;
	listint_t *next;

	prev = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to head of list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *prev_slow;
	listint_t *mid;
	listint_t *second_half;
	listint_t *left;
	listint_t *right;
	int result;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;
	prev_slow = NULL;
	mid = NULL;
	result = 1;

	while (fast != NULL && fast->next != NULL)
	{
		prev_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
	{
		mid = slow;
		second_half = slow->next;
	}
	else
	{
		second_half = slow;
	}

	right = reverse_list(second_half);
	left = *head;
	second_half = right;

	while (right != NULL)
	{
		if (left->n != right->n)
		{
			result = 0;
			break;
		}
		left = left->next;
		right = right->next;
	}

	second_half = reverse_list(second_half);
	if (mid != NULL)
	{
		mid->next = second_half;
		prev_slow->next = mid;
	}
	else
	{
		prev_slow->next = second_half;
	}

	return (result);
}
