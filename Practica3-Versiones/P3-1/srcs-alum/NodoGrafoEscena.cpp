//**********************************************************************************************//
//                                                                                              //
//                            Implementación NodoGrafoEscena.hpp                                //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include <vector>
#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include "NodoGrafoEscena.hpp"
#include "aux.hpp"
#include "matrizg_impl.hpp"
#include "Objeto3D.hpp"

void NodoGrafoEscena::visualizarGL(ContextoVis& cv){
    glMatrixMode(GL_MODELVIEW); // operamos sobre la ModelView
    glPushMatrix();             // guarda modelview actual

    //recorrer todas las entradas del array que hay en el nodo
    for(unsigned i = 0; i< entradas.size(); i++){
        if (entradas[i].tipoE == 0) //Si la entrada es un objeto (tipoE == 0)
            entradas[i].objeto->visualizarGL(cv);
        else
        {                    //Si la entrada es una transformacion (tipoE == 1)
            glMatrixMode(GL_MODELVIEW);
            glMultMatrixf(*(entradas[i].matriz));
        }
    }
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}
void NodoGrafoEscena::agregar( EntradaNGE * entrada){
    entradas.push_back(*entrada);
}
void NodoGrafoEscena::agregar( Objeto3D *pObjeto){
    EntradaNGE entrada(pObjeto);
    entradas.push_back(entrada);
}
void NodoGrafoEscena::agregar( const Matriz4f & pMatriz){
    EntradaNGE entrada(pMatriz);
    entradas.push_back(entrada);
}
