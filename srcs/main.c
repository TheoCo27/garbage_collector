/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:29 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 16:29:01 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

//TEST WITH LOCK PTR
int	main(int argc, char **argv)
{
	t_garbage *lst;
	char	*str;
	char	*str2;
	char	*str3;
	char	**tab_str;

	(void)argc;
	(void)argv;
	lst = NULL;
	str = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
	if (!str)
		return (1);
	str2 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
	if (!str2)
		return (1);
	str3 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
	if (!str3)
		return (1);
	tab_str = g_malloc(4 * sizeof(char *));
	if (!tab_str)
		return (1);
	tab_str[0] = str;
	tab_str[1] = str2;
	tab_str[2] = str3;
	tab_str[3] = NULL;
	ft_strcpy(str, "Hello world\n");
	ft_strcpy(str2, "2ello world\n");
	ft_strcpy(str3, "3ello world\n");
	ft_putstr_fd(str, 1);
	ft_putstr_fd(str2, 1);
	ft_putstr_fd(str3, 1);
	lock_ptr(str);
	garbage_clear_unlock();
	ft_putstr_fd(str, 1);
	lst = get_garbage(NULL);
	garbage_lstclear(&lst);
	return (0);
}

//TEST 3 STRINGS FREE FIRST
// int	main(int argc, char **argv)
// {
// 	t_garbage *lst;
// 	char	*str;
// 	char	*str2;
// 	char	*str3;
// 	char	**tab_str;

// 	(void)argc;
// 	(void)argv;
// 	lst = NULL;
// 	str = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str)
// 		return (1);
// 	str2 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str2)
// 		return (1);
// 	str3 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str3)
// 		return (1);
// 	tab_str = g_malloc(4 * sizeof(char *));
// 	if (!tab_str)
// 		return (1);
// 	tab_str[0] = str;
// 	tab_str[1] = str2;
// 	tab_str[2] = str3;
// 	tab_str[3] = NULL;
// 	ft_strcpy(str, "Hello world\n");
// 	ft_strcpy(str2, "2ello world\n");
// 	ft_strcpy(str3, "3ello world\n");
// 	ft_putstr_fd(str, 1);
// 	ft_putstr_fd(str2, 1);
// 	ft_putstr_fd(str3, 1);
// 	g_free(str);
// 	lst = get_garbage(NULL);
// 	garbage_lstclear(&lst);
// 	return (0);
// }

//TEST 3 STRINGS FREE LAST
// int	main(int argc, char **argv)
// {
// 	t_garbage *lst;
// 	char	*str;
// 	char	*str2;
// 	char	*str3;
// 	char	**tab_str;

// 	(void)argc;
// 	(void)argv;
// 	lst = NULL;
// 	str = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str)
// 		return (1);
// 	str2 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str2)
// 		return (1);
// 	str3 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str3)
// 		return (1);
// 	tab_str = g_malloc(4 * sizeof(char *));
// 	if (!tab_str)
// 		return (1);
// 	tab_str[0] = str;
// 	tab_str[1] = str2;
// 	tab_str[2] = str3;
// 	tab_str[3] = NULL;
// 	ft_strcpy(str, "Hello world\n");
// 	ft_strcpy(str2, "2ello world\n");
// 	ft_strcpy(str3, "3ello world\n");
// 	ft_putstr_fd(str, 1);
// 	ft_putstr_fd(str2, 1);
// 	ft_putstr_fd(str3, 1);
// 	g_free(str3);
// 	lst = get_garbage(NULL);
// 	garbage_lstclear(&lst);
// 	return (0);
// }

// //TEST 3 STRINGS FREE MID
// int	main(int argc, char **argv)
// {
// 	t_garbage *lst;
// 	char	*str;
// 	char	*str2;
// 	char	*str3;
// 	char	**tab_str;

// 	(void)argc;
// 	(void)argv;
// 	lst = NULL;
// 	str = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str)
// 		return (1);
// 	str2 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str2)
// 		return (1);
// 	str3 = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str3)
// 		return (1);
// 	tab_str = g_malloc(4 * sizeof(char *));
// 	if (!tab_str)
// 		return (1);
// 	tab_str[0] = str;
// 	tab_str[1] = str2;
// 	tab_str[2] = str3;
// 	tab_str[3] = NULL;
// 	ft_strcpy(str, "Hello world\n");
// 	ft_strcpy(str2, "2ello world\n");
// 	ft_strcpy(str3, "3ello world\n");
// 	ft_putstr_fd(str, 1);
// 	ft_putstr_fd(str2, 1);
// 	ft_putstr_fd(str3, 1);
// 	g_free(str2);
// 	lst = get_garbage(NULL);
// 	garbage_lstclear(&lst);
// 	return (0);
// }

//TEST WITH ONE STRING
// int	main(int argc, char **argv)
// {
// 	t_garbage *lst;
// 	char	*str;

// 	(void)argc;
// 	(void)argv;
// 	lst = NULL;
// 	str = g_malloc((ft_strlen("Hello World\n") + 1) *sizeof(char));
// 	if (!str)
// 		return (1);
// 	ft_strcpy(str, "Hello world\n");
// 	ft_putstr_fd(str, 1);
// 	g_free(str);
// 	lst = get_garbage(NULL);
// 	garbage_lstclear(&lst);
// 	return (0);
// }
