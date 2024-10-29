#ifndef FILE_HPP
#define FILE_HPP

// include //

#include <iostream>
#include <string>
#include <fstream>
#include <new>

// function //

int CheckFile(std::string filename);
unsigned int GetSize(std::string file);
char *CopyFile(unsigned int size, std::string file);
std::string Remplace(char *file, char *s1, char *s2);
void CreateFile(std::string filename, std::string NewFile);
std::string StrJoin(std::string filename, std::string insert);


#endif