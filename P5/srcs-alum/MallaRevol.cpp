//**********************************************************************************************//
//                                                                                              //
//                            Implementación MallaRevol.hpp                                     //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include "MallaRevol.hpp"
#include "file_ply_stl.hpp"
#include <cmath>


vector<Tupla3f> MallaRevol::Rotar(Matriz4f& m, vector<Tupla3f>& vertices)
{
  vector<Tupla3f> sol;
  for(Tupla3f& t:vertices)
  {
    sol.push_back(m*t);
  }
  return sol;
}
MallaRevol::MallaRevol(const string & nombre_arch, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla, bool crear_coord_text)
{
  // Extrae información de nombre_arch
  vector<float> vertices_ply;
  ply::read_vertices(nombre_arch.c_str(),vertices_ply);
  // Matriz de rotación en el eje Y
  Matriz4f m = MAT_Rotacion(360.0/nperfiles,0,1,0);
  vector<Tupla3f> perfil;


  for (unsigned i=0; i<vertices_ply.size(); i+=3) {
    Tupla3f vertice = Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]);
    perfil.push_back(vertice);
  }

  ver=perfil;
  int num_ver = perfil.size();

  vector<float> distancias;
  distancias.reserve(num_ver);
  float distancia=0;
  distancias.push_back(distancia);
  for(int i=0; i<num_ver; ++i)
  {
    Tupla3f aux = ver[i+1]-ver[i];
    aux = Tupla3f(abs(aux(0)),abs(aux(1)),abs(aux(2)));
    distancia = sqrt(aux(0)*aux(0) + aux(1)*aux(1) + aux(2)*aux(2)) + distancia;
    distancias.push_back(distancia);
  }

  for(unsigned i=0; i<nperfiles; i++)
  {
    std::vector<Tupla3f> siguientePerfil = Rotar(m,perfil);
    ver.insert(ver.end(),siguientePerfil.begin(),siguientePerfil.end());
    perfil = siguientePerfil;
    int inicio=i*num_ver;
    int fin = inicio + num_ver;
    int p = fin +1;
    for(int j=inicio+1; j<fin; j++)
    {
        // Primer triángulo
        tri.push_back(Tupla3i(j-1,p-1,p));

        // Segundo triángulo
        tri.push_back(Tupla3i(j-1,p,j));
        p++;
    }
  }

  if(crear_tapas)
  {
    Tupla3f centro_superior(0,(ver[0])(1),0);
    Tupla3f centro_inferior(0,(ver[ver.size()-1])(1),0);

    ver.push_back(centro_superior);
    for(unsigned i=0; i<nperfiles;++i){
      int primero=i*num_ver;
      int siguiente = primero + num_ver;
      tri.push_back(Tupla3i(ver.size()-1,primero,siguiente));
    }
    ver.push_back(centro_inferior);
    for(unsigned i=0; i<nperfiles;++i)
    {
      int primero=(i+1)*num_ver-1;
      int segundo=primero+num_ver;
      tri.push_back(Tupla3i(ver.size()-1,primero,segundo));
    }
  }

  for(int i=0; i<tri.size();++i)
  {
    if(i%2==0)
      tri_pares.push_back(tri[i]);
    else
      tri_impares.push_back(tri[i]);
  }

  this->num_ver = ver.size();
  this->num_tri = tri.size();
  this->num_tri_impar = tri_impares.size();
  this->num_tri_par = tri_pares.size();

  if(crear_coord_text)
    calcularCordTextura(nperfiles, num_ver, distancias);
}

void MallaRevol::calcularCordTextura(const unsigned nperfiles, int nvertices, vector<float> distancias)
{
  float s=0;
  float t=0;
  for(int i=0;i<nperfiles;++i)
  {
    s=(float)(i)/float((nperfiles-1));
    for(int j=0; j<nvertices; ++j)
    {
      t=(float)(distancias[j])/(float)(distancias[nvertices-1]);
    }
    coords_textura.push_back(Tupla2f(s,t));
  }
}
