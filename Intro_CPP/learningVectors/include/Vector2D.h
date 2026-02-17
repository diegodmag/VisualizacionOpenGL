#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <iostream>

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

};






#endif