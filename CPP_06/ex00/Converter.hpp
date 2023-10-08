#ifndef CONVERTER_HPP
#define CONVERTER_HPP

// char //

#define CHAR 1
#define NON_DISPLAYABLE_CHAR 33
#define LIMITE_CHAR 127

#define INT 2

#define FLOAT 3

#define DOUBLE 4

#define PSEUDO 5

#define ERROR  0

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

class Converter
{
    private:
        const std::string _input;
        char              _c;
        int               _i;
        float             _f;
        double            _d;
        int  DefineInput( void ) ;
        void printPseudoInf( void ) ;
        void printChar( char c ) ;
        void printInt( void ) ;
        void printDeci( void ) ;

        char    getChar( void ) const ;
        int     getInt( void ) const ;
        float   getFloat( void ) const ;
        double  getDouble( void ) const ;
        const std::string getInput( void ) const ;

    public:
        Converter( void ) ;
        Converter( std::string input ) ;
        Converter( Converter const & src ) ;

        Converter & operator=( Converter const & rhs ) ;

        ~Converter( void ) ;
};


#endif