// made by sk


#include <stdio.h>
#include <string.h>
#include <errno.h>






int main(int argc, const char * argv[]){
    printf("\nthis is in the early stages of development please report bugs to https://github.com/sk-imsk/copy-files/issues\n");
  if (argc < 2){
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
    fileread = fopen(file.readFname, "rb");
    if (fileread == NULL){
      printf("Error opening read file");      
      perror("error");
      return 2;
      }
    
    FILE *filewrite;
    filewrite = fopen(file.writeFname, "wb");
    if (filewrite == NULL){
        printf("Error writeing to destination file");
        perror("error");
        return 2;
    }
    
    // start reading and writeing file
    while(fread(file.filedata, 1, sizeof(fileread), fileread) ){
    	fwrite(file.filedata, 1, sizeof(fileread), filewrite);}
  
    fclose(filewrite);
    fclose(fileread);
}
