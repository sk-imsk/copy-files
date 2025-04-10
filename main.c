// made by sk


#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[]){
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
    
    FILE *filepointer;
    filepointer = fopen(file.filename, "w");
  
    fclose(filepointer);
}

