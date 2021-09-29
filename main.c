/*
** EPITECH PROJECT, 2020
** BOOSTRAP MY_LS
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/my.h"
#include <sys/stat.h>
#include <sys/sysmacros.h>

char gettype(struct stat stats)
{
    return ((S_ISLNK(stats.st_mode)?'l':(S_ISDIR(stats.st_mode)?'d':(S_ISCHR(stats.st_mode)?'c':(S_ISREG(stats.st_mode)?'f':' ')))));
}
int main (int argc, char *argv[]) {
    struct stat stats;
    stat(argv[1], &stats);

    argc = argc;

    my_printf("Name : %s\n", argv[1]);
    my_printf("Type : %c\n", gettype(stats));
    my_printf("Inode : %ld\n", stats.st_ino);
    my_printf("Hard Link : %ld\n", stats.st_nlink);
    my_printf("Size : %ld\n", stats.st_size);
    my_printf("Allocated space : %ld\n", stats.st_blksize);
    my_printf("Minor : %d\n", minor(stats.st_dev));
    my_printf("Major : %d\n", major(stats.st_dev));
    my_printf("UID : %d\n", stats.st_uid);
    my_printf("GID : %d\n", stats.st_gid);
    
}