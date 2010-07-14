#ifndef MATERIAL_H_
#define MATERIAL_H_
#include "../global.h"
class Material
{
public:

	GLfloat m_ambient[4], m_diffuse[4], m_specular[4], m_emissive[4];
	GLfloat m_shininess;
	GLuint m_texture; // Texture UID
	GLchar *m_pTextureFilename;


	Material();
	Material(GLchar * name);
	virtual ~Material();
	void specular(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha);
	void ambient(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha);
	void diffuse(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha);
	void emissive(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha);
	void texture(GLchar * fliename);
	GLuint LoadTexture(char *filename,int *textw,int *texth) ;
	
	static void set(Material m);
};

#endif /*MATERIAL_H_*/
