
#include "Textura.hpp"


void Textura::activar()
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, idText);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  if (mgct == 0) {
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
  }
  else {
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    if (mgct == 1) {
      glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
      glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
      glTexGenfv(GL_S, GL_OBJECT_PLANE, cs);
      glTexGenfv(GL_T, GL_OBJECT_PLANE, ct);
     }
     else {
       glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
       glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);

       glTexGenfv(GL_S, GL_EYE_PLANE, cs);
       glTexGenfv(GL_T, GL_EYE_PLANE, ct);
      }
  }
}

Textura::Textura(const std::string& archivoJPG, unsigned mgct_p){
  img = new jpg::Imagen(archivoJPG);
  mgct = mgct_p;

  cs[0] = ct[2] = 1;
  cs[1] = cs[2] = cs[3] = ct[0] = ct[1] = ct[3] = 0;

  glEnable(GL_TEXTURE_2D);
  glGenTextures(1, &idText);
  glBindTexture(GL_TEXTURE_2D, idText);

  gluBuild2DMipmaps(
    GL_TEXTURE_2D,
    GL_RGB,
    img->tamX(), img->tamY(),
    GL_RGB, GL_UNSIGNED_BYTE,
    img->leerPixels()
  );

  glBindTexture(GL_TEXTURE_2D, 0);
}
