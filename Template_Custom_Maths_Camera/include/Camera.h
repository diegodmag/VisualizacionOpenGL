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
    // linear::math::Vector3D m_center{-2.0f,1.5f,2.0f};

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

    // Euler Angles for camera movement 
    linear::math::Vector3D m_camera_direction{}; 
    float m_yaw {};
    float m_pitch {}; 

    float m_sensitivity = 0.1f;

    //For rotation input 
    float m_last_mouseX = 0.0;
    float m_last_mouseY = 0.0;

    bool m_first_mouse = true;

    public: 
    
    //Constructor 
    Camera(linear::math::Vector3D pos);
    
    ~Camera(); 
    
    void InitPerspectiveFrustrum(float fov, float aspect, float near, float far); 

    void ComputeView(); 

    void ComputeProjection();  
    
    void ComputeRotation(double xpos, double ypos); 

    const linear::math::Matrix4D& getView(){return m_view_matriz;}
    
    const linear::math::Matrix4D& getProjection(){return m_projection;}

    // Camera traslation 
    void Move_Right(float displacement);  

    void Move_Foreward(float displacement);  
    
    void Move_Up(float displacement);  

};

#endif