#include "Camera.h"

Camera::Camera(linear::math::Vector3D pos)
    : m_position{pos}
    {
        m_RotMat = linear::math::Matrix4D::identity(); 
        m_TrastMat = linear::math::Matrix4D::identity(); 

        //Initial value
        m_yaw = -90.0f;  // Esto hace que mire hacia -Z
        m_pitch = 0.0f;
        m_sensitivity = 0.05f; // Asegúrate de que no sea 0
        m_first_mouse = true; // Crucial para el primer frame
        
        // // Dirección inicial coherente con yaw = -90
        m_foreward = linear::math::Vector3D(0.0f, 0.0f, -1.0f);
    }; 

Camera::~Camera(){}; 

void Camera::InitPerspectiveFrustrum(float fov, float aspect, float near, float far){
    m_frustrum.fov = fov; 
    m_frustrum.aspect = aspect; 
    m_frustrum.near = near; 
    m_frustrum.far = far; 
}


void Camera::ComputeView(){
    // m_foreward = linear::math::Normalize(m_position-m_center); // eye - center  
    
    m_right = linear::math::Normalize(linear::math::Cross(m_foreward,m_up)); 
    m_camera_up = linear::math::Cross(m_right,m_foreward); 

    m_RotMat(0,0) = m_right.x; m_RotMat(0,1) = m_right.y; m_RotMat(0,2) = m_right.z; 
    m_RotMat(1,0) = m_camera_up.x; m_RotMat(1,1) = m_camera_up.y; m_RotMat(1,2) = m_camera_up.z; 
    m_RotMat(2,0) = m_foreward.x; m_RotMat(2,1) = m_foreward.y; m_RotMat(2,2) = m_foreward.z; 

    m_TrastMat(0,3) = -m_position.x; 
    m_TrastMat(1,3) = -m_position.y; 
    m_TrastMat(2,3) = -m_position.z;  

    m_view_matriz = m_RotMat * m_TrastMat; 

}

void Camera::ComputeProjection(){

    float tanHalfFOV = tanf(m_frustrum.fov / 2.0f);
    m_projection(0,0) = 1.0f / (m_frustrum.aspect * tanHalfFOV);
    m_projection(1,1) = 1.0f / tanHalfFOV;
    m_projection(2,2) = -(m_frustrum.far + m_frustrum.near) / (m_frustrum.far - m_frustrum.near);
    m_projection(3,2) = -1.0f; 
    m_projection(2,3) = -(2.0f * m_frustrum.far * m_frustrum.near) / (m_frustrum.far - m_frustrum.near);

}


// Rotation 

void Camera::ComputeRotation(double xpos, double ypos){
    
    if(m_first_mouse){
        m_last_mouseX=xpos;
        m_last_mouseY=ypos;
        m_first_mouse=false;
        // return; 
    }

    float xoffset = xpos - m_last_mouseX;
    float yoffset = m_last_mouseY - ypos; 
    m_last_mouseX = xpos;
    m_last_mouseY = ypos;

    xoffset *= m_sensitivity;
    yoffset *= m_sensitivity;

    m_yaw   += xoffset;
    m_pitch += yoffset;

    if(m_pitch > 89.0f)
        m_pitch = 89.0f;
    if(m_pitch < -89.0f)
        m_pitch = -89.0f;


    m_camera_direction.x = cos(linear::math::radians(m_yaw)) * cos(linear::math::radians(m_pitch));
    m_camera_direction.y = sin(linear::math::radians(m_pitch));
    m_camera_direction.z = sin(linear::math::radians(m_yaw)) * cos(linear::math::radians(m_pitch));
    m_foreward = linear::math::Normalize(m_camera_direction);
}

void Camera::Move_Foreward(float displacement){
    m_position+= m_foreward*displacement;
}

void Camera::Move_Right(float displacement){
    m_position+= m_right*displacement;
}   

void Camera::Move_Up(float displacement){
    m_position+= m_camera_up*displacement;
}