#include<stdio.h>

int main(){

  int ch, i;
  char* search;

  struct {
    char dname[10],fname[10][10];
    int fcnt;
  }root;

  root.fcnt = 0;
  printf("Enter root dir name\n");
  scanf("%s", root.dname);
  printf("Root dir is: %s\n", root.dname);

  while(1){
    printf("1.Create 2.Display 3.Search 4.Exit\n");
    scanf("%d", &ch);

    switch(ch){
      case 1:
        printf("Enter file name\n");
        scanf("%s", root.fname[root.fcnt]);
        root.fcnt++;
        break;

      case 2:
        for(i=0; i<=root.fcnt; i++)
        printf("%s\t", root.fname[i]);
        printf("\n");
        break;

      case 3:
        printf("Enter the file to be deleted\n");
        scanf("%s", search)
        for(i=0; i<=root.fcnt; i++){
          if(root.fname[i] == search)
            printf("Found at %s\n", i);
        }
        printf("\n");
        break;1

    }
  }



}
