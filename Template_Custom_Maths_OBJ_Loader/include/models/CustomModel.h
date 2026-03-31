#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <vector>
#include "Model.h"

#define num_VBOs 3

class CustomModel: public Model{
private:
    const char * m_filePath; 
    int numVertices; 
    // std::vector<glm::vec3> vertices; 
    // std::vector<glm::vec2> texCoords; 
    // std::vector<glm::vec3> normalVecs;

    GLuint m_VBO[num_VBOs];

    std::vector<float> m_vertices; // vertices
    std::vector<float> m_textCoords; // text_coords 
    std::vector<float> m_normalVecs; // normla vertex 
public: 

    CustomModel(ShaderProgram* program, const char *filePath) 
        : Model(program)
        , m_filePath{filePath}
    {

        initGeometry();
        
        init();

    }

    void initGeometry() override;

    void init() override;

    // This one needs a mat4 from ours 
    // void renderModel(const glm::mat4& view, const glm::mat4& projection) override;
    void translate(const linear::math::Vector3D& translation) override; 

    void rotate(float angle, const linear::math::Vector3D& axis) override; 

    void scale(const linear::math::Vector3D& scaling) override;
    
    
    void renderModel(const linear::math::Matrix4D& view, const linear::math::Matrix4D& projection) override;

    void updateModel(float deltaTime) override;

    void finish() override;

};


#endif