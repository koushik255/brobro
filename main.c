#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "zero.h"




#define PATH_MAX_LEN 4096

// this ***good_files is the pointer to the **goodfiles 
// because the realloc might move the block we gotta replace 
// the callers variable 
//the 3 stars allows us to pass the address of the callers variable 
//so we can overwrite it
//were basically *** is just the address of the good_files and goodfiles is a char array string so its **
//and since realloc can move shit randomly we gotta have like a W base point thats why we pass the adress
//C is pass by value, when you hand it into the function you pass it as a private independant copy
//
//create my own sorting thing? or look at different algorihms 



void print_filepl (filepl *nicebor){
    char *dir = nicebor->fdir;
    char *name = nicebor->fname;

    //printf("From filepl %s\n",dir);
    char *last_part;
    char *seprator = "/";
    last_part = strrchr(name,*seprator);
   // printf("from filepl %s\n",name);
   // printf("last part %s\n",last_part);
}


int froerty(const filepl fullfile)
{
    char *path = fullfile.fname;
   // printf("path from fro %s\n",path);
    struct dirent *entry;
    DIR *dir = opendir(path);
  
    //printf("Contents of dir %s\n",path);
    // array of c string is "char *"
    // so this is a pointer to a pointer of C strings j
    char **good_files = NULL;
    int file_cnt = 0;
     if (dir == NULL) {
        //printf("its wraps in dir ==null %s\n",path);
        perror("opendir");
        //exit(EXIT_FAILURE);
        
        return 1;
    }


    while((entry = readdir(dir))!=NULL){
         char *name = entry->d_name;

        // this skips the bs that posix just spawns for no reason
        if (strcmp(name,".")==0|| strcmp(name, "..")==0)
            continue;

        if (entry ->d_type == DT_DIR) {
            char new_path[PATH_MAX_LEN];

            snprintf(new_path, sizeof(new_path),"%s/%s",path,name);
            // i think its cause this file is just a static copy?
            
            filepl new_file = {
                .fname = new_path, 
            };
            

         
            print_filepl(&new_file);
            froerty(new_file);
        }
        
        if (entry ->d_type == DT_REG){
        const char *ext = strrchr(name, '.');
       
        char *want = ".mkv";

        filepl new_file = {
                .fname = name
            };


        check_file_ext(ext,new_file,want,&good_files,&file_cnt);
    }

}
        

    for (int i = 0; i< file_cnt; ++i) {
        printf("dude %s\n",good_files[i]);
        free(good_files[i]);
    }
    free(good_files);
        closedir(dir);



    return 0;
}

// il make a floating file explorerm
// so right now im doing file structs 
// so that for each element in the dir im in as we would be in the file thing 


int main(void) {

    printf("Sup Koushik!\n");
    char *path = "/home/koushikk/Downloads/";
    filepl first ={
        .fname = path,
    };

    froerty(first);

    return 0;
}


