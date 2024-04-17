#include "Array.hpp"

#define SIZE 10

int main( void )
{
    Array< float > test;

    Array< int > intArray( 10 );
    Array< int > intArray2( 5 );

    for ( unsigned int i = 0; i < intArray.size(); i++ )
        intArray[i] = i * 2;
	for ( unsigned int i = 0; i < intArray2.size(); i++ )
        intArray2[i] = i * 3;

    std::cout << "Int Array 1: " << intArray << std::endl;
	std::cout << "int Array 2: " << intArray2 << std::endl;

	std::cout << "Modifie Array 2 !" << std::endl;
    intArray2 = intArray;

    std::cout << "int Array 2: " << intArray2 << std::endl;

    try {
        std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
        std::cout << "Accessing an invalid index: " << intArray[10] << std::endl;
    } 
	catch ( OutOfBoundsException& e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return ( 0 );
}