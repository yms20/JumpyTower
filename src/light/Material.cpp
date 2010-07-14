#include "Material.h"

Material::Material()
{
		ambient(1,1,1,1);
	diffuse(1,1,1,1);
	emissive(1,1,1,1);
	specular(1,1,1,1);
	m_shininess = 100;
	m_texture = -1;
	m_pTextureFilename = 0;
}

Material::~Material()
{

 	
}

Material::Material(GLchar * name){

}
void Material::ambient(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha){

m_ambient[0] = red ;
m_ambient[1] = green;
m_ambient[2] = blue;
m_ambient[3] = alpha;

}

void Material::diffuse(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha){

m_diffuse[0] = red ;
m_diffuse[1] = green;
m_diffuse[2] = blue;
m_diffuse[3] = alpha;

}

void Material::specular(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha){

m_specular[0] = red ;
m_specular[1] = green;
m_specular[2] = blue;
m_specular[3] = alpha;

}

void Material::emissive(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha){

m_emissive[0] = red ;
m_emissive[1] = green;
m_emissive[2] = blue;
m_emissive[3] = alpha;

}


void Material::set(Material m ){


  glMaterialfv( GL_FRONT, GL_AMBIENT, m.m_ambient );
  glMaterialfv( GL_FRONT, GL_DIFFUSE, m.m_diffuse );
  glMaterialfv( GL_FRONT, GL_SPECULAR, m.m_specular );
  glMaterialfv( GL_FRONT, GL_EMISSION, m.m_emissive );
  glMaterialf( GL_FRONT, GL_SHININESS, m.m_shininess );

  if ( m.m_texture > 0 )
  {
    glBindTexture( GL_TEXTURE_2D, m.m_texture );
    glEnable( GL_TEXTURE_2D );
  }
  else
    glDisable( GL_TEXTURE_2D );

}

GLuint  Material::LoadTexture(char *filename,int *textw,int *texth) {

  SDL_Surface *surface;
  GLuint textureid;
  int mode;

   surface = IMG_Load(filename);

        // Or if you don't use SDL_image you can use SDL_LoadBMP here instead:
        // surface = SDL_LoadBMP(filename);
        // could not load filename
  if (!surface) {return 0;  }

        // work out what format to tell glTexImage2D to use...
  if (surface->format->BytesPerPixel == 3) { // RGB 24bit
    mode = GL_RGB;
  } else if (surface->format->BytesPerPixel == 4) { // RGBA 32bit
    mode = GL_RGBA;
  } else {
     SDL_FreeSurface(surface);
    printf("IMG_Load(filename) in Rosegarden Neither RGB nor RGBA !\n ");
    return 0;
    
  }

  *textw=surface->w;
  *texth=surface->h;
        // create one texture name
  glGenTextures(1, &textureid);

        // tell opengl to use the generated texture name
  glBindTexture(GL_TEXTURE_2D, textureid);

        // this reads from the sdl surface and puts it into an opengl texture
  glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

        // these affect how this texture is drawn later on...
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   

        // clean up
  SDL_FreeSurface(surface);

  return textureid;
}