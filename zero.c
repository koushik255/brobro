#include "zero.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char **check_file_ext(const char *ext
                   , filepl name
                   , char *want
                   ,char ***good_files
                   ,int   *count )
{

    const char *namename = name.fname;
    if (ext && ext != namename){
        if (strcmp(ext,want)==0){
                                    //printf("File %-20s Extension : %s\n",name,ext);


    *good_files = realloc(*good_files,(*count +1) * sizeof ** good_files);

            (*good_files)[(*count)++] = strdup(namename);
            

        }
    }

return *good_files;
}
