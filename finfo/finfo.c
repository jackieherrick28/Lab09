/**************************************************************************************************************************************
* Filename: finfo.c
* Class: CPE 2600 121
* Description: Displays the file information about a given file  provided via the command line.
* Author: Jackie Herrick
* Date: 11/05/26
* gcc finfo.c -o finfo
* ./finfo
**************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void print_file_type(mode_t mode)
{
    printf("File Type: ");

    if (S_ISREG(mode))
    {
        printf("Regular File\n");
    }
    else if (S_ISDIR(mode))
    {
        printf("Directory\n");
    }
    else if (S_ISLNK(mode))
    {
        printf("Symbolic Link\n");
    }
    else if (S_ISCHR(mode))
    {
        printf("Character Device\n");
    }
    else if (S_ISBLK(mode))
    {
        printf("Block Device\n");
    }
    else if (S_ISFIFO(mode))
    {
        printf("FIFO/Pipe\n");
    }
    else if (S_ISSOCK(mode))
    {
        printf("Socket\n");
    }
    else
        printf("Unknown\n");
}

void print_permissions(mode_t mode)
{
    char perms[10];

    perms[0] = (mode & S_IRUSR) ? 'r' : '-';
    perms[1] = (mode & S_IWUSR) ? 'w' : '-';
    perms[2] = (mode & S_IXUSR) ? 'x' : '-';

    perms[3] = (mode & S_IRGRP) ? 'r' : '-';
    perms[4] = (mode & S_IWGRP) ? 'w' : '-';
    perms[5] = (mode & S_IXGRP) ? 'x' : '-';

    perms[6] = (mode & S_IROTH) ? 'r' : '-';
    perms[7] = (mode & S_IWOTH) ? 'w' : '-';
    perms[8] = (mode & S_IXOTH) ? 'x' : '-';

    perms[9] = '\0';

    printf("Permissions: %s\n", perms);
}

int main(int argc, char *argv[])
{
    struct stat fileInfo;
    char timeString[100];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileInfo) == -1)
    {
        perror("stat");
        return 1;
    }

    print_file_type(fileInfo.st_mode);

    print_permissions(fileInfo.st_mode);

    printf("Owner UID: %u\n", fileInfo.st_uid);

    printf("Size: %ld bytes\n", (long)fileInfo.st_size);

    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&fileInfo.st_mtime));

    printf("Last Modified: %s\n", timeString);

    return 0;
}