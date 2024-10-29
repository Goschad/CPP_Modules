#include "../file.hpp"

// create the string <filename.replace> //

std::string StrJoin(std::string filename, std::string insert)
{
    std::string NewStr;

    NewStr = filename;
    NewStr = NewStr.insert(NewStr.length(), insert);
    return (NewStr);
}

// check if my file exist //

 int CheckFile(std::string filename)
 {
    std::ifstream ifs(filename);
    char *line;

    line = new char [1];
    if (ifs)
    {
        if (ifs.read(line, 1))
        {
            delete line;
            return (1);
        }
    }
    delete line;
    std::cout<<"Error file ..."<<std::endl;
    ifs.close();
    return (0);
 }

// get <filename> size //

unsigned int GetSize(std::string file)
{
    char c = 0;
    unsigned int size = 0;
    std::ifstream ifs(file);

    for (int i = 0; ifs.get(c); i++)
           size++;

    ifs.close();
    return (size);
}

// copy the file in a char * //

char *CopyFile(unsigned int size, std::string file)
{
    char c = 0;
    char *copy = NULL;
    std::ifstream ifs(file);

    copy = new char [size + 1];

    for (int i = 0; ifs.get(c); i++)
       copy[i] = c;
    copy[size] = '\0';

    ifs.close(); 

    return (copy);
}

 // remplace s1 with s2 into file string //

 std::string Remplace(char *file, char *s1, char *s2)
 {
    int i = 0;
    int j = 0;
    int x = 0;
    std::string remplace(file);
    std::string ss2(s2);

    while (file[i])
    {
        j = 0;
        while (s1[j] && file[i + j] && file[i + j] == s1[j])
        {
            j++;
            if (!s1[j])
            {
                remplace.erase(i - x, j);
                remplace.insert(i - x, ss2);
                x++;
            }
        }
        i++;
    }
    return (remplace);
 }

 void CreateFile(std::string filename, std::string NewFile)
 {
    std::ofstream ofs(StrJoin(filename, ".replace"));
    ofs << NewFile;
    ofs.close();
 }


