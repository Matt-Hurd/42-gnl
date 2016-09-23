/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:03:14 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/21 23:46:33 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
** Too lazy to test:
** ft_memccpy
** ft_memmove
** ft_memcmp
*/

int		itoatests[] = {
	0,
	-1,
	1,
	42,
	-42,
	100,
	-101,
	1001,
	-1111,
	9,
	-9,
	10,
	-10,
	2147483647,
	-2147483647,
	-2147483648
};

char	*g_atoitests[] = {
	"1000",
	"0000123",
	"   +42",
	"   -42",
	"+ 42",
	"- 42",
	"+-42",
	"\r\n\t\v42",
	"",
	"\\1",
	"+1",
	"0-1",
	"-+1",
	"0+-1",
	"--1",
	"++1",
	"2147483647",
	"2147483648",
	"2147483649",
	"-2147483647",
	"-2147483648",
	"-2147483649",
	"1789324638",
	"11221f11",
	"42 43 44 45 46",
	"9223372036854775807",
	"9223372036854775808",
	"9223372036854775809",
	"-9223372036854775807",
	"-9223372036854775808",
	"-9223372036854775809",
	"      9223372036854775809",
	"  \r\n\t\v\f    9223372036854775806",
	"18446744073709551615",
	"18446744073709551616",
	"18446744073709551617",
	"-18446744073709551615",
	"-18446744073709551616",
	"-18446744073709551617",
	"\"1\"*(2**32-1)+\"-\"+\"0\"",
	"-10000000000000000000",
	"-33333333333333333333",
	"-333333333333333333333",
	"36893488147419103237",
	"00000000000000000000000000042",
	"  +00000000000000000000000000042",
	"     "
};

char *itoa(int 	i)
{
  /* Room for INT_DIGITS digits, - and '\0' */
  static char buf[20 + 2];
  char *p = buf + 20 + 1;	/* points to terminating '\0' */
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  }
  else {			/* i < 0 */
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}

int	main(void)
{
	char *(test_strings)[10] = 
	{
		"aA0\t\n &^\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"a\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"aA\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"\0\0\0\0\0\0\0\0\0\0\0\0\0",
		">\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"123!@asd#\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"ASD6541a23\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"!@#EDAsFD !~#@ AS5a623445/*-2345234+5dfs ;;D /6*\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"this is a test\0\0\0\0\0\0\0\0\0\0\0\0\0",
		"is shit broken yet?a\0\0\0\0\0\0\0\0\0\0\0\0\0"
	};
	char *temp;
	char *temp2;
	int c = -1;
	//char tests
	while (++c <= 255)
	{
		if (!!isalpha(c) != ft_isalpha(c))
			printf("ft_isalpha FAIL for char %d\n", c);
		if (!!isdigit(c) != ft_isdigit(c))
			printf("ft_isaldigit FAIL for char %d\n", c);
		if (!!isalnum(c) != ft_isalnum(c))
			printf("ft_isalnum FAIL for char %d\n", c);
		if (!!isascii(c) != ft_isascii(c))
			printf("ft_isascii FAIL for char %d\n", c);
		if (!!isprint(c) != ft_isprint(c))
			printf("ft_isprint FAIL for char %d\n", c);
		if (tolower(c) != ft_tolower(c))
			printf("ft_tolower FAIL for char %d\n", c);
		if (toupper(c) != ft_toupper(c))
			printf("ft_toupper FAIL for char %d\n", c);
	}
	c = -1;

	while (++c < 17)
		if (strcmp(itoa(itoatests[c]), ft_itoa(itoatests[c])))
			printf("ft_itoa FAIL on %d, expected %s, got %s\n", itoatests[c], itoa(itoatests[c]), ft_itoa(itoatests[c]));

	while (++c < 46	)
		if (atoi(g_atoitests[c]) != ft_atoi(g_atoitests[c]))
			printf("ft_atoi FAIL on %s, expected %d, got %d\n", g_atoitests[c], atoi(g_atoitests[c]), ft_atoi(g_atoitests[c]));

	c = -1;
	if (ft_strcmp("a", "") < 0)
		printf("ft_strcmp FAIL test a\n");
	if (ft_strcmp("", "") != 0)
		printf("ft_strcmp FAIL test b\n");
	if (ft_strcmp("THIS IS A LONG TEST", "THIS IS A LONGER TEST") > 0)
		printf("ft_strcmp FAIL test c\n");

	if (ft_strncmp("a", "", 1) < 0)
		printf("ft_strncmp FAIL test a\n");
	if (ft_strncmp("", "", 5) != 0)
		printf("ft_strncmp FAIL test b\n");
	if (ft_strncmp("THIS IS A LONG TEST", "THIS IS A LONGER TEST", 5) != 0)
		printf("ft_strncmp FAIL test c\n");
	while (++c < 10)
	{
		if (ft_strlen(test_strings[c]) != strlen(test_strings[c]))
			printf("ft_strlen FAIL for '%s', expected %d, got %d\n", test_strings[c], (int)strlen(test_strings[c]), (int)ft_strlen(test_strings[c]));
		int len = strlen(test_strings[c]) + 1;
		char *a = (char *)malloc(len);
		char *b = (char *)malloc(len);
		if (memcmp(memcpy(a, test_strings[c], len), ft_memcpy(b, test_strings[c], len), len))
			printf("ft_memcpy FAIL for '%s'\n", test_strings[c]);

		ft_memset(a, c, len);
		int x = -1;
		while (++x < len)
			if (a[x] != c)
				printf("ft_memset FAIL for test %d\n", c);

		ft_bzero(b, len);
		x = -1;
		while (++x < len)
			if (b[x])
				printf("ft_bzero FAIL for test %d\n", c);

		temp = (char *)malloc(strlen(test_strings[c] + 1) * sizeof(char));
		if (strcmp(test_strings[c], ft_strcpy(temp, test_strings[c])))
			printf("ft_strcpy FAIL for '%s', got %s\n", test_strings[c], temp);

		if (strcmp(strdup(test_strings[c]), ft_strdup(test_strings[c])))
			printf("strdup FAIL for '%s', got %s\n", test_strings[c], ft_strdup(test_strings[c]));

		temp2 = (char *)malloc(c + 1);
		temp2 = (char *)malloc(c + 1);
		// if (strcmp(strncpy(temp2, test_strings[c], c), ft_strncpy(temp, test_strings[c], c)))
		// 	printf("ft_strncpy FAIL for '%s', expected %s, got %s\n", test_strings[c], temp2, temp);

		if (x < 9)
		{
			temp = (char *)malloc(100);
			temp2 = (char *)malloc(100);
			strcpy(temp, test_strings[c]);
			strcpy(temp2, test_strings[c]);
			if(strcmp(strcat(temp, test_strings[c + 1]), ft_strcat(temp, test_strings[c + 1])))
				printf("ft_strcat FAIL, expected %s, got %s\n", temp, temp2);

			temp = (char *)malloc(100);
			temp2 = (char *)malloc(100);
			strcpy(temp, test_strings[c]);
			strcpy(temp2, test_strings[c]);
			if(strcmp(strncat(temp, test_strings[c + 1], c), ft_strncat(temp, test_strings[c + 1], c)))
				printf("ft_strncat FAIL, expected %s, got %s\n", temp, temp2);
		}
		if (memchr(test_strings[c], 'a', 5) != ft_memchr(test_strings[c], 'a', 5))
			printf("ft_memchr FAIL for '%s', expected %X, got %X\n", test_strings[c], (unsigned int)memchr(test_strings[c], 'a', 5), (unsigned int)ft_memchr(test_strings[c], 'a', 5));

		if (strchr(test_strings[c], 'a') != ft_strchr(test_strings[c], 'a'))
			printf("ft_str FAIL for '%s', expected %X, got %X\n", test_strings[c], (unsigned int)strchr(test_strings[c], 'a'), (unsigned int)ft_strchr(test_strings[c], 'a'));
		}
	return (0);
}
