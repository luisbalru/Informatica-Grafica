//**********************************************************************************************//
//                                                                                              //
//                            Implementación MallaPLYhpp                                        //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//


#include "MallaPLY.hpp"

MallaPLY::MallaPLY(const string & nombre_archivo) {
  // Extrae los puntos para generar los vértices y las caras
  // desde el archivo PLY pasado como argumento.
  vector<float> vertices_ply;
  vector<int> caras_ply;
  ply::read(nombre_archivo.c_str(), vertices_ply, caras_ply);

  // Genera la malla organizando los puntos leídos en tuplas
  // Organiza los vértices
  for (unsigned i=0; i<vertices_ply.size(); i+=3) {
    Tupla3f vertice = Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]);
    ver.push_back(vertice);
  }

  // Organiza las caras
  for (unsigned i=0; i<caras_ply.size(); i+=3) {
    Tupla3i cara = Tupla3i(caras_ply[i],caras_ply[i+1],caras_ply[i+2]);
    tri.push_back(cara);
  }
  this-> num_ver = ver.size();
  this-> num_tri= tri.size();
  for(int i=0; i<tri.size(); i++)
  {
    if(i%2==0)
      tri_pares.push_back(tri[i]);
    else
      tri_impares.push_back(tri[i]);
  }
  this-> num_tri_par=tri_pares.size();
  this-> num_tri_impar=tri_impares.size();
}
