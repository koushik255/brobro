#ifndef ZERO_H
#define ZERO_H


#define PATH_MAX_LEN 4096

typedef struct {
    char fdir[PATH_MAX_LEN];
    char *fname;
} filepl;



char **check_file_ext(const char *ext
                   ,filepl name
                   , char *want
                   ,char ***good_files
                   ,int   *count );



#endif
