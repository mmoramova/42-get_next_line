/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:14 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/13 17:06:14 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *text;
    char *buffer;
    int byte;
    char *line;

    if (!text)
        text = calloc(2000, sizeof(char));
    line = calloc(2000, sizeof(char));
    buffer = calloc(BUFFER_SIZE, sizeof(char));

    byte = 1;

    // 1. read the file until \n is in the variable text
    while (byte != 0 && !ft_strchr(text, '\n') )
    {
        byte = read(fd, buffer, 300);
        //printf("TEXT BEFORE JOIN: %s\n\n", text);
        //printf("BUFFER IS: %s\n\n", buffer);
        text = ft_strjoin(text, buffer);
        //printf("TEXT AFTER JOIN: %s\n\n", text);
    }

    // 2. fill the variable line
    if (ft_strchr(text, '\n'))
    {
        int i;
    
        i = 0;
        while (text[i] != '\n' && text[i])
        {
            line[i] = text[i];
            i++;
        }
        if (text[i] == '\n')
        {
            line[i] = text[i];
            i++;
        }
    }  
    //printf("LINE: %s\n\n", line); 
   
    // 3. delete line from buffer
    //printf("TEXT BEFORE: %s\n\n", text); 
    text = ft_strchr(text, '\n'); //+1 TODO;
    //printf("TEXT AFTER 3: %s\n\n", text);

    return (line);
}

int main (int argc, char **argv)
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    //gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xyz get_next_line.c get_next_line_utils.c && ./a.out
}