#include "Utils.h"

#include <iostream>
#include <fstream>
#include <SOIL2/SOIL2.h>


GLuint Utils::LoadTexture(const char *texImagePath){
    GLuint textureID; 
    textureID = SOIL_load_OGL_texture(texImagePath,
                                     SOIL_LOAD_AUTO, 
                                     SOIL_CREATE_NEW_ID, 
                                     SOIL_FLAG_INVERT_Y);
    if(textureID == 0 )  std::cout << "could not find texture file" << texImagePath << std::endl;
    
    else std::cout << "texture succesfully loaded" << texImagePath << std::endl;

    return textureID;
}