#ifndef CUBE_H
#define CUBE_H

#include "Model.h"

class Cube: public Model
{
private:
    GLfloat vertices[48];
    GLuint indices[36];
public: 

    Cube(ShaderProgram* program) : Model(program){

        initGeometry();
        
        init();

    }

    void initGeometry() override;

    void init() override;

    void renderModel(const glm::mat4& view, const glm::mat4& projection) override;

    void updateModel(float deltaTime) override;

    void finish() override;

}; 

#endif