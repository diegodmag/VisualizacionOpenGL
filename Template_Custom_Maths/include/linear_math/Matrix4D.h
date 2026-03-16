// Matrix4D.h
#ifndef MATRIX4D_H
#define MATRIX4D_H

#include <iostream>
#include <cassert>
#include "Vector3D.h"

namespace linear::math {

    struct Matrix4D {
    private:
        float arr_2D[4][4]{}; // Column-major order for OpenGL

    public:
        Matrix4D() = default;
        
        
        static Matrix4D identity() {
            Matrix4D result;
            for (int i = 0; i < 4; i++)
                result(i, i) = 1.0f; // La diagonal es 1.0f 
            return result;
        }

        inline float& operator()(int i, int j) {
            assert(i >= 0 && i < 4 && j >= 0 && j < 4);
            return arr_2D[j][i]; // Column-major
        }

        inline const float& operator()(int i, int j) const {
            assert(i >= 0 && i < 4 && j >= 0 && j < 4);
            return arr_2D[j][i]; // Column-major
        }

        

        // IMPORTANTE 
        // Esta funcion es importante por que devuelve un puntero al primer elemento del arreglo 
        // OpenGL espera un puntero a 16 floats (matrix 4x4) en orden column-major 
        const float* value_ptr() const {
            return &arr_2D[0][0]; // Referencia al primer elmento del array 
        }


    // Construir una matrix de proyeccion en perspectiva 
    // near -> distancia al plano cercano 
    // far -> distancia al plano lejano 
    
    static Matrix4D perspective(float fov, float aspect, float near, float far) {
        Matrix4D result;
        float tanHalfFOV = tanf(fov / 2.0f);
        
        // Buscamos mapear X, Y del espacio de vista al rango de [-1,1] de NDC
        result(0,0) = 1.0f / (aspect * tanHalfFOV);
        result(1,1) = 1.0f / tanHalfFOV;
        result(2,2) = -(far + near) / (far - near);
        result(3,2) = -1.0f;                          // row3, col2 = -1 -> por que openGL mira en -z
        result(2,3) = -(2.0f * far * near) / (far - near); // row2, col3
        
        // All other elements are already zero (default constructor)
        return result;
    }

    static Matrix4D lookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& up) {
        Vector3D d = Normalize(center - eye); // Direction 
        // Deberia ser eye - center para obtener el vector en direccion al centro, pero 
        // en opengl -z es hacia donde apunta la camara, entonces es center-eye
        Vector3D r = Normalize(Cross(d, up)); // El mini eje de x de la camara (Right vector)
        Vector3D u = Cross(r, d); // Up vector 
        
        Matrix4D result = identity();  // sets diagonal to 1, others 0
        
        // Rotation part (columns 0,1,2)
        result(0,2) = -d.x; result(1,2) = -d.y; result(2,2) = -d.z; // col2 
        result(0,0) = r.x;  result(1,0) = r.y;  result(2,0) = r.z;  // col0 
        result(0,1) = u.x;  result(1,1) = u.y;  result(2,1) = u.z;  // col1 
        
        // Translation part (column 3)
        result(0,3) = -Dot(r, eye);
        result(1,3) = -Dot(u, eye);
        result(2,3) =  Dot(d, eye);
        // (3,3) already 1 from identity
        
        return result;
    }

//     static Matrix4D lookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& up) {
//     // Calcular los ejes de la cámara
//     Vector3D forward = Normalize(center - eye);   // dirección hacia adelante
//     Vector3D right = Normalize(Cross(forward, up)); // derecha (producto cruz)
//     Vector3D upCam = Cross(right, forward);        // arriba real (perpendicular)

//     // --- Matriz de rotación (en column-major) ---
//     // La matriz canónica tendría los ejes como filas: 
//     // fila0 = right, fila1 = upCam, fila2 = -forward
//     // Pero como nuestro operador * usa la transpuesta, construimos la matriz
//     // con los ejes como columnas para que al multiplicar dé el mismo resultado.
//     Matrix4D R;
//     // Columna 0: right
//     R(0,0) = right.x;   R(1,0) = right.y;   R(2,0) = right.z;   R(3,0) = 0.0f;
//     // Columna 1: upCam
//     R(0,1) = upCam.x;   R(1,1) = upCam.y;   R(2,1) = upCam.z;   R(3,1) = 0.0f;
//     // Columna 2: -forward
//     R(0,2) = -forward.x; R(1,2) = -forward.y; R(2,2) = -forward.z; R(3,2) = 0.0f;
//     // Columna 3: (0,0,0,1) - el resto ya es cero, solo falta (3,3)=1
//     R(3,3) = 1.0f;

//     // --- Matriz de traslación: traslada el origen al ojo (es decir, mueve por -eye) ---
//     Matrix4D T = identity(); // empieza con identidad
//     T(0,3) = -eye.x;
//     T(1,3) = -eye.y;
//     T(2,3) = -eye.z;
//     // T(3,3) ya es 1 por la identidad

//     // Componer: primero traslación, luego rotación (R * T)
//     return R * T;
// }

    // Translation matrix
    static Matrix4D translate(const Vector3D& v) {
        Matrix4D result = identity();
        result(0,3) = v.x;
        result(1,3) = v.y;
        result(2,3) = v.z;
        return result;
    }

    // Rotation around X axis
    static Matrix4D rotateX(float angle) {
        Matrix4D result = identity();
        float c = cosf(angle);
        float s = sinf(angle);
            
        result(1, 1) = c;
        result(2, 1) = -s;
        result(1, 2) = s;
        result(2, 2) = c;
            
        return result;
    }

        // Rotation around Y axis
        static Matrix4D rotateY(float angle) {
            Matrix4D result = identity();
            float c = cosf(angle);
            float s = sinf(angle);
            
            result(0, 0) = c;
            result(2, 0) = s;
            result(0, 2) = -s;
            result(2, 2) = c;
            
            return result;
        }

        // Rotation around Z axis
        static Matrix4D rotateZ(float angle) {
            Matrix4D result = identity();
            float c = cosf(angle);
            float s = sinf(angle);
            
            result(0, 0) = c;
            result(1, 0) = -s;
            result(0, 1) = s;
            result(1, 1) = c;
            
            return result;
        }

        // Scale matrix
        static Matrix4D scale(const Vector3D& v) {
            Matrix4D result;
            result(0, 0) = v.x;
            result(1, 1) = v.y;
            result(2, 2) = v.z;
            result(3, 3) = 1.0f;
            return result;
        }

        friend Matrix4D operator*(const Matrix4D& a, const Matrix4D& b) {
            Matrix4D result;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    float sum = 0;
                    for (int k = 0; k < 4; k++) {
                        sum += a(i, k) * b(k, j);
                    }
                    result(i, j) = sum;
                }
            }
            return result;
        }
    };

    // Vector4D for homogeneous coordinates
    struct Vector4D {
        float x{}, y{}, z{}, w{};
        
        Vector4D() = default;
        Vector4D(float _x, float _y, float _z, float _w = 1.0f) 
            : x(_x), y(_y), z(_z), w(_w) {}
        
        // Convert from Vector3D (add w component)
        explicit Vector4D(const Vector3D& v, float _w = 1.0f) 
            : x(v.x), y(v.y), z(v.z), w(_w) {}
        
        // Convert back to Vector3D (perspective division)
        Vector3D toVector3D() const {
            if (w != 0 && w != 1.0f) {
                return Vector3D(x/w, y/w, z/w);
            }
            return Vector3D(x, y, z);
        }
    };

    // Vector4D * Matrix4D multiplication
    inline Vector4D operator*(const Matrix4D& m, const Vector4D& v) {
        return Vector4D(
            m(0,0)*v.x + m(1,0)*v.y + m(2,0)*v.z + m(3,0)*v.w,
            m(0,1)*v.x + m(1,1)*v.y + m(2,1)*v.z + m(3,1)*v.w,
            m(0,2)*v.x + m(1,2)*v.y + m(2,2)*v.z + m(3,2)*v.w,
            m(0,3)*v.x + m(1,3)*v.y + m(2,3)*v.z + m(3,3)*v.w
        );
    }

    // Vector3D * Matrix4D multiplication (implicitly converts to Vector4D with w=1)
    inline Vector3D operator*(const Matrix4D& m, const Vector3D& v) {
        Vector4D v4(v, 1.0f);
        Vector4D result = m * v4;
        return result.toVector3D();
    }
}

#endif