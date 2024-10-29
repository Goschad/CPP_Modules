#include "../file.hpp"

int main(int argc, char **argv)
{
    char c = 0;
    char *file = NULL;
    unsigned int size = 0;
    std::string RemplaceFile;

    if (argc == 4)
    {
        std::string filename(argv[1]);
        if (!CheckFile(filename))
            return (0);
        size = GetSize(filename);
        file = CopyFile(size, filename);
        RemplaceFile = Remplace(file, argv[2], argv[3]);
        CreateFile(filename, RemplaceFile);
        delete file;
    }
    else
        std::cout<<"• Usage: <filename> [s1] [s2]"<<std::endl;
    return (0);
}