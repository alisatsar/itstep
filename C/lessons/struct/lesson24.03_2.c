#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Folder
{
	char Name[256];
	struct Folder* Children;
	int ChildrenCount;
};

void addFolder(struct Folder* folder, char* newFolderName);

int main()
{
	struct Folder diskCFolders[4];
		
	struct Folder diskC;

	strcpy(diskC.Name, "C:");
	diskC.ChildrenCount = 0;
	diskC.Children = diskCFolders;

	addFolder(&diskC, "AMD");
	addFolder(&diskC, "ad");
	addFolder(&diskC, "AMsdgD");
	addFolder(&diskC, "sfg");


	printf("%s\n", diskC.Name);
	for (int i = 0; i < diskC.ChildrenCount; i++)
	{
		printf("\t%s\n", diskC.Children[i].Name);
	}

	/*printf("%s\n", amdFolders.Name);
	for (int i = 0; i < amdFolders.ChildrenCount; i++)
	{
		printf("\t%s\n", amdFolders.Children[i].Name);
	}
	return 0;*/
}
	
void addFolder(struct Folder* folder, char* newFolderName)
{
	struct Folder* newC = &folder->Children[folder->ChildrenCount];
	strcpy(newC->Name, newFolderName);
	newC->Children = NULL;
	newC->Children = 0;
	folder->ChildrenCount++;
}
