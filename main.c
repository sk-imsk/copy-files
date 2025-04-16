// made by sk


#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, const char * argv[]){
    printf("\nthis is in the early stages of development please report bugs to https://github.com/sk-imsk/copy-files/issues\n");
  if (argc == 1){
      printf("usage: copy filename, write filename");
    return 1;
}
    struct filestuff {
      char readFname[20];
      char filedata[100];
       char writeFname[20];
    };
    struct filestuff file;
    
    // write read file name
    strncpy(file.readFname, argv[1], sizeof(file.readFname) - 1);
    file.readFname[sizeof(file.readFname) - 1] = '\0';
    
    // write write file name
    strncpy(file.writeFname, argv[2], sizeof(file.writeFname) -1);
    file.writeFname[sizeof(file.writeFname) - 1] = '\0';
    
    // error check
    FILE *fileread;
    fileread = fopen(file.readFname, "r");
    if (fileread == NULL){
      printf("Error opening read file");      
      perror("error");
      return 2;
      }
    
    FILE *filewrite;
    filewrite = fopen(file.writeFname, "w");
    
    if (filewrite == NULL){
        printf("Error writeing to destination file");
        perror("error");
        return 2;
    }
    
    // start reading and writeing file
    while(fgets(file.filedata, 99, fileread)){
    	fprintf(filewrite, file.filedata);}
  
    fclose(filewrite);
    fclose(fileread);
}

