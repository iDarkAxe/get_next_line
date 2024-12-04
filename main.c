/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:49:56 by aviscogl          #+#    #+#             */
/*   Updated: 2024/11/30 12:49:56 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int fd;
    char *str;
    int index;

    index = 0;
    setbuf(stdout, NULL);
    setvbuf(stdout, NULL, _IONBF, 0); 
    if (argc >= 2){
        fd = open(argv[1], O_RDONLY);
    }
    else {
         fd = open("get_next_line.c", O_RDONLY);
    }
    
	printf("fd %d\n", fd);
    do
    {
        str = get_next_line(fd);
        printf("line %05d | %s", index, str);
        index++;
        free(str);
    } while (str != NULL);
    return (0);
}


// https://www.baeldung.com/linux/limit-file-descriptors pour voir fd-max
// ulimit -n renvoie 1024