// made by sk


#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char * argv[]){
  printf("this is in the early stages of development please report bugs to https://github.com/sk-imsk/copy-files/issues\n")
  if (argc == 1){
      printf("usage: copy filename");
    return 1;
}
    struct filestuff {
      char filename[20];
      char filedata[100];
    };
    struct filestuff file;
    strncpy(file.filename, argv[1], sizeof(file.filename) - 1);
    file.filename[sizeof(file.filename) - 1] = '\0';
    // error check
    FILE *filepointer;
    filepointer = fopen(file.filename, "r");
    if (filepointer == NULL){
      perror("error");
      return 2;
      }
    // start reading and writeing file
    while(fgets(file.filedata, 99, filepointer)){
        printf("%s", filedata);}
  
  fclose(filepointer);
}

