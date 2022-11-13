/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:14 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/13 19:23:53 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *add_buffer(int fd, char *text)
{
    // 1. read the file until \n is in the variable text
    char *buffer;
    int len_byte;

    buffer = calloc(BUFFER_SIZE+1, sizeof(char));
    len_byte = -1;

    while (len_byte != 0 && !ft_strchr(text, '\n') )
    {
        len_byte = read(fd, buffer, BUFFER_SIZE);
        
        //printf("TEXT BEFORE JOIN: %s\n\n", text);
        //printf("BUFFER IS: %s\n\n", buffer);

        if (len_byte < 0)
        {
            free(buffer);
            return (NULL); 
        }
        text = ft_strjoin(text, buffer);

        //printf("TEXT AFTER JOIN: %s\n\n", text);
    }
    free(buffer);
    return (text);
}

char *get_line(char *text)
{
    // 2. fill the variable line
    char *line;
    int len;

    len = 0;
    while (text[len] != '\n')
        len++;
    len++;
    line = calloc(len + 1, sizeof(char));
    ft_strlcpy(line, text, len+1);
  return(line);
}

char *get_next_line(int fd)
{
    static char *text = NULL;

    char *line;

    if (!text)
       text = calloc(2000, sizeof(char));
    
    text = add_buffer(fd, text);
    line = get_line(text);
   
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