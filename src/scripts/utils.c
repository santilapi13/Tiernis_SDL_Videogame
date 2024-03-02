#include <../headers/utils.h>

int filesInDirectory(const char *path) {
    DIR *directory;
    struct dirent *entry;
    int amount = 0;

    directory = opendir(path);

    if (directory == NULL) {
        perror("Error al abrir el directorio");
        return -1;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {  // DT_REG indica un archivo regular
            amount++;
        }
    }

    closedir(directory);
    return amount;
}