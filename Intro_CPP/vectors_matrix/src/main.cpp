#include <SFML/Graphics.hpp>
#include <cmath>

#include "LinearMaths.h"

int main(){
    
    float arr[3] = {5.0f, 10.0f, 15.0f};
    
    // std::cout<<arr[0]<<'\n';
    // std::cout<<arr[1]<<'\n';
    // std::cout<<arr[2]<<'\n';

    // Que regresa ? 
    // std::cout<<arr<<'\n'; //-> Es la dirección de un float". Si haces arr + 1, salto 4 bytes
    // std::cout<<&arr<<'\n'; //-> Es la dirección de un bloque de 3 float". Si haces &arr + 1, salto 12 bytes (todo el arreglo)
    // std::cout<<"<<<<<<<"<<'\n';
    // std::cout<<*arr<<'\n';
    // std::cout<<*(arr+1)<<'\n';
    // std::cout<<*(arr+2)<<'\n';
    
    // La variable arr es un puntero al primer elemento del arreglo !!! 
    
    
    float matrix3_3[3][3]={ {1.0f, 2.0f, 3.0f},
                            {4.0f, 5.0f, 6.0f},
                            {7.0f, 8.0f, 9.0f}};
    
    // std::cout<<"<<<<<<<"<<'\n';
    // // que ocurre en un arreglo 2D 
    std::cout<<matrix3_3[0]<<'\n'; // <- esto es un puntero al primer elemento del arreglo {1.0f, 2.0f, 3.0f}
    std::cout<<*(matrix3_3[0]+1)<<'\n'; // <- esto es un puntero al primer elemento del arreglo {1.0f, 2.0f, 3.0f}
    std::cout<<matrix3_3[0][2]<<'\n';
    // std::cout<<matrix3_3[0][2]<<'\n';


    // std::cout<<*(matrix3_3[0])<<'\n'; // <- por lo tanto al desreferenciarlo obtenemos el elemento 
    // std::cout<<*(matrix3_3[0]+1)<<'\n'; // <- por lo tanto al desreferenciarlo obtenemos el elemento 
    // std::cout<<*(matrix3_3[0]+2)<<'\n'; // <- por lo tanto al desreferenciarlo obtenemos el elemento 



    // sfloat vector_as_row[3] {*matrix3_3[0]};

}
