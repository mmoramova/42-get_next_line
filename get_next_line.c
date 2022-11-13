/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:14 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/13 22:55:47 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *add_buffer(int fd, char *text)
{
    // 1. read the file until \n is in the variable text
    char *buffer;
    int len_byte;

    buffer = ft_calloc(BUFFER_SIZE+1, sizeof(char));
    if(!buffer)
        return(NULL);
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

char *get_lines(char *text)
{
    // 2. fill the variable line
    char *line;
    int len;

    len = 0;
    while (text[len] != '\n')
        len++;
    len++;
    line = ft_calloc(len + 1, sizeof(char));
    if(!line)
        return(NULL);
    ft_strlcpy(line, text, len+1);
  return(line);
}

char *update_text(char *text, size_t len)
{
    // 3. delete line from buffer
    char *new_text;

    //printf("TEXT BEFORE: %s\n\n", text); 
    //printf("SIZE OF LINE: %d\n\n", len);
    //printf("TEXT: %s\n\n", new_text);
    new_text = ft_substr(text, len, ft_strlen(text) - len);
    free(text);
    return (new_text);
}

char *get_next_line(int fd)
{
    char        *line;
    static char *text = NULL;

    if (!text)
       text = ft_calloc(3000, sizeof(char));
    
    text = add_buffer(fd, text);
    if (!text)
        return(NULL);
    line = get_lines(text);
    text = update_text(text, strlen(line));
 
    return (line);
}

/*int main (int argc, char **argv)
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd)); 
    printf("|%s|\n\n", get_next_line(fd));
    printf("|%s|\n\n", get_next_line(fd));
    printf("|%s|\n\n", get_next_line(fd));
    printf("|%s|\n\n", get_next_line(fd));
    printf("|%s|\n\n", get_next_line(fd));
    printf("|%s|\n\n", get_next_line(fd));
    //gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xyz get_next_line.c get_next_line_utils.c && ./a.out
}*/