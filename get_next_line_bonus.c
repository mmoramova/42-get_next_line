/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:12:22 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/26 12:20:18 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *ft_free(char **text)
{
    free(*text);
    *text = NULL;
    return (NULL);
}

char *add_buffer(int fd, char *text)
{
    // 1. read the file until \n
    char buffer[BUFFER_SIZE+1];
    int len_byte;

    len_byte = 1;
    buffer[0] = '\0';
    while (len_byte > 0 && !ft_strchr(buffer, '\n'))
    {
        len_byte = read(fd, buffer, BUFFER_SIZE);

        if(len_byte > 0)
        {
            buffer[len_byte] = '\0';
            text = ft_strjoin(text, buffer);
        }
    }
    if (len_byte < 0)
        return (ft_free(&text)); 
    return (text);
}

char *get_lines(char *text)
{
    // 2. fill the variable line
    char *line;
    int len;

    len = 0;
    while (text[len] && text[len] != '\n')
        len++;
    if (text[len] == '\n') 
        len++;
    line = malloc((len + 1) * sizeof(char));
    if(!line)
        return(NULL);
    ft_strlcpy(line, text, len + 1);
  return(line);
}

char *update_text(char *text)
{
    // 3. delete line from buffer
    char *new_text;
    char *end;
    int len;

    end = ft_strchr(text, '\n');
    if (!end)
        return(ft_free(&text));
    else
        len = (end - text) + 1;
    if (!text[len])
        return(ft_free(&text));
    new_text = ft_substr(text, len, ft_strlen(text) - len);
    ft_free(&text);
    return (new_text);
}

char *get_next_line(int fd)
{
    char        *line;
    static char *text[OPEN_MAX];

    if (fd < 0  || fd > OPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    if (!text[fd] || (!ft_strchr(text[fd], '\n')))
        text[fd] = add_buffer(fd, text[fd]);
    if (!text[fd])
        return(NULL);
    line = get_lines(text[fd]);
    if(!line)
        return (ft_free(&text[fd]));
    text[fd] = update_text(text[fd]);
    return (line);
}
/*
int main (int argc, char **argv)
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);
    printf("|%s|\n\n", get_next_line(fd)); 
    //gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xyz get_next_line.c get_next_line_utils.c && ./a.out
}*/