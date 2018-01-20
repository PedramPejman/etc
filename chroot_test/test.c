#include <stdio.h>
#include <dirent.h>

void print_dir(char *dir_name) {
  DIR *dir = opendir(dir_name);
  struct dirent *ent;
  int mod_count=0;

	printf("{\n");

  while ((ent = readdir(dir)) != NULL) {
    if (strcmp(ent->d_name, ".") &&  
        strcmp(ent->d_name, ".."))
			printf("[%s]\n", ent->d_name);
  }

	printf("}\n");

  closedir(dir);
}

int main() {
  printf("starting\n");
  int x = chroot(".");
  printf("chroot [%d]\n", x);
	
	const char *args = {"diff", "x", "y"};

  x = execl("bin/sh", "sh", "-c", "./runner", (char *) 0);
	printf ("run [%d]\n", x);
}

