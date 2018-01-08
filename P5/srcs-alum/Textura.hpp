//**********************************************************************************************//
//                                                                                              //
//                            Definición Textura.hpp                                            //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#ifndef IG_TEXTURA_HPP
#define IG_TEXTURA_HPP

#include "aux.hpp"
#include "jpg_imagen.hpp"
#include "practicas.hpp"

class Textura
{
  public:
    GLuint idText; // identificador OpenGL de la textura
    jpg::Imagen* img; // puntero a objeto imagen con los texels en RAM
    unsigned mgct; // modo generación cc.tt: 0=desactivado, 1=objeto, 2=mundo
    float cs[4], ct[4]; // Coeficientes s para generación de cc.tt. (si mgct!=0) // coeficientes T para generación de cc.tt.
    bool generada;

    // activar la textura: habilita texturas y activa esta en concreto
    void activar();
    Textura(const std::string& archivoJPG, unsigned mgct);
};



#endif
