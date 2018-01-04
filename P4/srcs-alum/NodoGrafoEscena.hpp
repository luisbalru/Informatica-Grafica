#ifndef IG_NODOGRAFOESCENA_HPP
#define IG_NODOGRAFOESCENA_HPP

#include <vector>
#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include "aux.hpp"
#include "matrizg_impl.hpp"
#include "Objeto3D.hpp"
#include "EntradaNGE.hpp"
//Entrada del nodo del Grafo de Escena

class NodoGrafoEscena : public Objeto3D
{
   protected:
      std::vector<EntradaNGE> entradas; //vector de entradas
   public:
      //visualiza usando OpenGL
      virtual void visualizarGL(ContextoVis& cv) ;
      // añadir una entrada (al final).
      void agregar( EntradaNGE * entrada);     //genérica
      // Construir una entrada y añadirla (al final)
      void agregar( Objeto3D *pObjeto);         // objeto
      void agregar( const Matriz4f & pMatriz);  // matriz
      void agregar(Material* pMaterial); // material
      EntradaNGE & devolver(int pos)
      {
        return (entradas[pos]);
      }
};

#endif
