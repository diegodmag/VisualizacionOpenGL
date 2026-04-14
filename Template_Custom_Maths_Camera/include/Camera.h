#ifndef CAMERA_H
#define CAMERA_H

#include "linear_math/Matrix4D.h"
#include "linear_math/Vector3D.h"
#include "MathUtils.h"

class Camera{

    struct Frustrum{
        float fov {0.0f};
        float aspect {0.0f};
        float near {0.0f}; 
        float far {0.0f};
    };


private: 

    linear::math::Vector3D m_position {};
    //Hacia donde mira la camara 
    linear::math::Vector3D m_center{0.0f,0.0f,0.0f};

    // "Arriba" general 
    linear::math::Vector3D m_up {0.0f,1.0f,0.0f};
    // Sistema local de la camara      
    linear::math::Vector3D m_foreward{}; 
    linear::math::Vector3D m_right{}; 
    linear::math::Vector3D m_camera_up{}; 

    // Matriz de rotacion y traslacion 
    linear::math::Matrix4D m_RotMat {}; 
    linear::math::Matrix4D m_TrastMat {}; 

    // Matrices 
    linear::math::Matrix4D m_view_matriz {}; 
    linear::math::Matrix4D m_projection {};

    Frustrum m_frustrum {};  
    
    public: 
    
    //Constructor 
    Camera(linear::math::Vector3D pos);
    
    ~Camera(); 
    
    void InitPerspectiveFrustrum(float fov, float aspect, float near, float far); 

    void ComputeView(); 

    void ComputeProjection();  
    
    const linear::math::Matrix4D& getView(){return m_view_matriz;}
    
    const linear::math::Matrix4D& getProjection(){return m_projection;}

    // 

};

#endif