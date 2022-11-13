/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:14 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/13 12:52:24 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    int fd;
    char c[2000];
    
    fd = open(argv[1], O_RDONLY);
    
    read(fd, c, 2000);

    printf("%s", c);
}