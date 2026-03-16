#ifndef LINEARMATHS_H
#define LINEARMATHS_H

#include <cmath>
#include <iostream>
#include <cassert>

namespace math::linear{

    struct Vector2D
    {
        float x,y; 
    
        Vector2D(){
            x=0.0f;
            y=0.0f;
        }

        Vector2D(float a, float b)
            :x{a},y{b} // Initialization List 
        {
    
        }
    
        // Vector2D v -> v[0] = x, v[1]=y 

        float& operator [](int i){
            if(0<=i<=1){
                return (i==0) ? x : y; 
            }
        }
        
        const float& operator [](int i) const{  
            if(0<=i<=1){
                return (i==0) ? x : y; 
            }
        }
    
        // All the member functions modifies the vector and return the same vector
        
        Vector2D& operator *= (float s){
            x*=s;
            y*=s; 
            return *this; // this returns a pointer to the object that called the function
            // therefore *this, returns the object 
        }
    
        Vector2D& operator /= (float s){
            x/=s;
            y/=s; 
            return *this; // this returns a pointer to the object that called the function
        }
    
        Vector2D& operator += (const Vector2D& v){
            x+=v.x; 
            y+=v.y; 
            return *this;
        }
    
        Vector2D& operator -= (const Vector2D& v){
            x-=v.x; 
            y-=v.y; 
            return *this;
        }
    
        friend std::ostream& operator<<(std::ostream& os,const Vector2D& v) {
            os << "(" << v.x << ", " << v.y<<")";
            return os;
        }
    };
    
    Vector2D operator * (const Vector2D& v, float s){
        return Vector2D{v.x*s, v.y*s};
    }
    
    Vector2D operator / (const Vector2D& v, float s){
        return Vector2D{v.x/s, v.y/s};
    }
    
    Vector2D operator - (const Vector2D& v){
        return Vector2D{-v.x, -v.y};
    }
    
    Vector2D operator +(const Vector2D& u, const Vector2D& v){
        return Vector2D{u.x+v.x, u.y+v.y};
    }
    
    Vector2D operator -(const Vector2D& u, const Vector2D& v){
        return Vector2D{u.x-v.x, u.y-v.y};
    }
    
    float Magnitude (const Vector2D& v){
        return std::sqrt(v.x*v.x + v.y*v.y);
    }
    
    Vector2D Normalize (const Vector2D& v){

        float magnitude {Magnitude(v)};
        if(magnitude==0.0f) return {0.0f, 0.0f};
        // Que pasa si el vector es el 0.0f, 0.0f ? 
        return v/Magnitude(v); 
    }


// LA IDEA ES >>> 

    struct Vector3D{

        float x{}, y{}, z{}; // <- inicializa esto en el 0 de los float

        Vector3D() = default; 

        Vector3D(float a, float b, float c)
            : x{a}, y{b}, z{c}{}; // List initialization

        float& operator[](int i) {
            assert(i >= 0 && i <= 2); //<- guarda o verificacion, evaluar una condicion booleana 
                                      // en caso de no cumplir, se detiene el program y regresa error 
            return ((&x)[i]); // <-- por que puedo hacer esto? Los structs, con 
            // Cuando declaras un struct en C++, el compilador coloca los miembros 
            // en el orden exacto en que los escribiste. Si tienes tres float (de 4 bytes cada uno), 
            // el compilador reserva un bloque continuo de 12 bytes en total. Solo si son del mismo tipo 
            // se puede asegurar que estan en bloques contiguos 
        }
        
        const float& operator[](int i) const { 
            assert(i >= 0 && i <= 2);
            return (&x)[i];
        }

        // ... mas funciones miembro 
    };
    
    // ... funciones que regresan vectores 3D 

    struct  Matrix3D
    {
        
        float n[3][3]{};
        
         
        Matrix3D() = default; //
            // Matrix3D()

        // Almacenamiento interno 
        Matrix3D(   float n00, float n01, float n02, 
                    float n10, float n11, float n12,
                    float n20, float n21, float n22)
                :   n{  {n00, n10, n20},
                        {n01, n11, n21},
                        {n02, n12, n22},
                    }{} // Entonces almacenarmos la matriz en formato column-major order    
        
        Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
                :   n{{a[0], a[1], a[2]},
                      {b[0], b[1], b[2]},
                      {c[0], c[1], c[2]}      
                    }{}
        
        // --> Pero queremos seguir accediendo de manera intuitiva, por lo que regresamos 
        float& operator ()(int i, int j){ // Matrix3D M -> M(2,3) -> M(3,2)
            assert(i >= 0 && i <= 2);
            assert(j >= 0 && j <= 2);
            return(n[j][i]);
        }
        
        const float& operator ()(int i, int j)const {
            assert(i >= 0 && i <= 2);
            assert(j >= 0 && j <= 2);
            return(n[j][i]);
        }
        
        Vector3D column(int j) const{
            assert(j>=0 && j<=2);
            return Vector3D{
                    n[j][0],
                    n[j][1],
                    n[j][2]          
            };
        }

    };
    

};

#endif