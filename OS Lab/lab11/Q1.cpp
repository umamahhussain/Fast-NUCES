#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
void replaceWordInFile(const char *fileName, const char *wordToReplace, const char *replacementWord)
{
    int fd = open(fileName, O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    size_t wordToReplaceLength = strlen(wordToReplace);
    size_t replacementWordLength = strlen(replacementWord);
    size_t fileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    char *map = (char *)mmap(NULL, fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED)
    {
        perror("mmap");
        return;
    }

    char *ptr = map;
    while (ptr < map + fileSize)
    {
        char *found = strstr(ptr, wordToReplace);
        if (!found)
        {
            break;
        }

        if (wordToReplaceLength != replacementWordLength)
        {
            size_t offset = found - map;
            size_t newSize = fileSize + replacementWordLength - wordToReplaceLength;
            char *newMap = (char *)mmap(NULL, newSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
            if (newMap == MAP_FAILED)
            {
                perror("mmap");
                return;
            }
            memcpy(newMap, map, offset);
            memcpy(newMap + offset, replacementWord, replacementWordLength);
            memcpy(newMap + offset + replacementWordLength, found + wordToReplaceLength, fileSize - offset - wordToReplaceLength);
            munmap(map, fileSize);
            map = newMap;
            ptr = map + offset + replacementWordLength;
            fileSize = newSize;
        }
        else
        {
            memcpy(found, replacementWord, replacementWordLength);
            ptr = found + replacementWordLength;
        }
    }
    cout << "The updated content of the file is:\n " << map;
    cout << endl;
    munmap(map, fileSize);
    close(fd);
}

int main(int argc, char *argv[])
{
    char word[100], rep[100], *filename;
    filename = argv[1];
    ifstream reader;
    reader.open(filename);
    string s;
    cout << "Old Contents of the file contained:\n";
    while (!reader.eof())
    {
        reader >> s;
        cout << s << " ";
    }
    cout << endl;
    reader.close();

    cout << "Enter the word to replace in the file:\n";
    cin >> word;

    cout << "Enter the word to replace it with:\n";
    cin >> rep;

    replaceWordInFile(filename, word, rep);

    return 0;
}
