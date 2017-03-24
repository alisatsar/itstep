#include <stdio.h>
#include <locale.h>
#include <string.h>
 
struct Folder
{
    char Name[256];
    struct Folder* Children;
    int ChildrenCount;
};
 
int main()
{
    setlocale(LC_ALL, "rus");
 
    struct Folder diskCFolders[3];
 
    strcpy(diskCFolders[0].Name, "AMD");
    diskCFolders[0].Children = NULL;
    diskCFolders[0].ChildrenCount = 0;
    strcpy(diskCFolders[1].Name, "Apache24");
    diskCFolders[1].Children = NULL;
    diskCFolders[1].ChildrenCount = 0;
    strcpy(diskCFolders[2].Name, "inetpub");
    diskCFolders[2].Children = NULL;
    diskCFolders[2].ChildrenCount = 0;
 
    struct Folder diskC;
    strcpy(diskC.Name, "C:");
    diskC.Children = diskCFolders;
    diskC.ChildrenCount = 3;
 
    printf("%s\n", diskC.Name);
    for (int i = 0; i < diskC.ChildrenCount; i++)
    {
        printf("\t%s\n", diskC.Children[i].Name);
    }
    return 0;
}
