#include "shell.h"

/**
 * _myenv - It prints the current environment
 * @dete: Structure containing potential arguments.
 * Return: Always 0
 */
int _myenv(info_t *dete)
{
	print_list_str(dete->env);
	return (0);
}

/**
 * _getenv - It gets the value of an environ variable
 * @dete: Structure containing potential arguments.
 * @name: environ var name
 *
 * Return: the value
 */
char *_getenv(info_t *dete, const char *name)
{
	list_t *node = dete->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable.
 * @dete: Structure containing potential arguments. 
 *  Return: Always 0
 */
int _mysetenv(info_t *dete)
{
	if (dete->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(dete, dete->argv[1], dete->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @dete: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myunsetenv(info_t *dete)
{
	int i;

	if (dete->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= dete->argc; i++)
		_unsetenv(dete, dete->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int populate_env_list(info_t *dete)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	dete->env = node;
	return (0);
}
