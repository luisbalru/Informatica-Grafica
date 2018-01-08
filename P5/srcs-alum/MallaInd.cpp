//**********************************************************************************************//
//                                                                                              //
//                            Implementación MallaInd.hpp                                       //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include "MallaInd.hpp"
#include <cstdlib>
#include <cmath>
#include <ctime>


void MallaInd::visualizarBE()
{
  glBegin(GL_TRIANGLES);
    for(unsigned i=0; i<num_tri; i++)
    {
      for(unsigned j=0; j<3; ++j)
      {
        unsigned ind_ver=tri[i](j);
        glVertex3fv(ver[ind_ver]);
      }
    }
  glEnd();
}


void MallaInd::visualizarDE(bool ajedrez)
{
  // habilitar uso de un array de vértices
  glEnableClientState(GL_VERTEX_ARRAY);
  //especificar puntero a tabla de coordenadas de vértices
  glVertexPointer(3,GL_FLOAT,0,&(ver[0]));
  // dibujar usando vértices indexados
  // params: 1 tipo de primitivas, 2 número de vértices, 3 tipo de vertices, 4 puntero a tabla de triángulos
  if(ajedrez)
  {
    glDrawElements(GL_TRIANGLES, 3*num_tri/2,GL_UNSIGNED_INT, tri_pares.data());
    glColor3f(0,0,1);
    glDrawElements(GL_TRIANGLES, 3*num_tri/2,GL_UNSIGNED_INT, tri_impares.data());
  }
  else
    glDrawElements(GL_TRIANGLES, 3*num_tri,GL_UNSIGNED_INT, tri.data());
  // deshabilitar el array de vértices
  glDisableClientState(GL_VERTEX_ARRAY);
}

void MallaInd::visualizarBEAtrTri()
{
  glBegin(GL_TRIANGLES);
  for(unsigned i=0; i<num_tri; ++i)
  {
    if(col_tri.size()>0)
      glColor3fv(col_tri[i]);

    if(normales_caras.size()>0)
      glNormal3fv(normales_caras[i]); //Para normales

    for(unsigned j=0; j<3; ++j)
    {
      unsigned iv=tri[i](j);
      glVertex3fv(ver[iv]);
    }
  }
  glEnd();
}

GLuint MallaInd::VBO_Crear(GLuint tipo, GLuint size, GLvoid* p)
{
  assert(tipo==GL_ARRAY_BUFFER || tipo == GL_ELEMENT_ARRAY_BUFFER);
  GLuint id_vbo;
  glGenBuffers(1, &id_vbo);
  glBindBuffer(tipo,id_vbo);
  glBufferData(tipo,size,p,GL_STATIC_DRAW);

  glBindBuffer(tipo,0);
  return id_vbo;
}

void MallaInd::crearVBOs()
{


    tam_ver = sizeof(float)*3L*num_ver;
    id_vbo_ver = VBO_Crear( GL_ARRAY_BUFFER, tam_ver, ver.data());

    tam_tri_par   = sizeof(float)*3L*num_tri_par;
    tam_tri_impar = sizeof(float)*3L*num_tri_impar;

    id_vbo_tri_par   = VBO_Crear(GL_ELEMENT_ARRAY_BUFFER, tam_tri_impar, tri_pares.data());
    id_vbo_tri_impar = VBO_Crear(GL_ELEMENT_ARRAY_BUFFER, tam_tri_impar, tri_impares.data());

    // cear VBO con la tabla de triángulos
    tam_tri = sizeof(unsigned)*3L * num_tri;
    id_vbo_tri = VBO_Crear( GL_ELEMENT_ARRAY_BUFFER, tam_tri, tri.data());


}

void MallaInd::visualizarVBOs()
{
  glBindBuffer(GL_ARRAY_BUFFER,id_vbo_ver);
  glVertexPointer(3,GL_FLOAT,0,0);
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glEnableClientState(GL_VERTEX_ARRAY);
  if(Ajedrez)
  {
    glColor3f(1,0,0);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri_impar);
    glDrawElements( GL_TRIANGLES, 3L*num_tri_impar, GL_UNSIGNED_INT,NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    glColor3f(0,0,1);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri_par);
    glDrawElements( GL_TRIANGLES, 3L*num_tri_par, GL_UNSIGNED_INT,NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    glDisableClientState(GL_VERTEX_ARRAY);

  }
  else
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id_vbo_tri);
    glDrawElements(GL_TRIANGLES, 3L*num_tri,GL_UNSIGNED_INT,NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void MallaInd::visualizarDE_NT()
{
  glVertexPointer(3,GL_FLOAT,0,ver.data());
  glTexCoordPointer(2, GL_FLOAT,0, coords_textura.data());
  glNormalPointer(GL_FLOAT,0,normales_vertices.data());

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);

  glDrawElements(GL_TRIANGLES,num_tri,GL_UNSIGNED_INT,tri.data());

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}


void MallaInd::visualizarGL(ContextoVis & cv)
{
    glColor3f(1.0,0.0,0.0);
    if(cv.modoVisu==modoAjedrez)
      this->Ajedrez=true;
    else
      this->Ajedrez=false;

    if(cv.modoVisu==modoAlambre){
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else if(cv.modoVisu==modoPuntos){
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
    }
    else if(cv.modoVisu==modoSolido){
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }
    else if(cv.modoVisu==modoAjedrez)
    {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      //visualizarBEAtrTri();
    }

    else if(cv.modoVisu==modoColorPlano)
    {
      glColor3f(color_x/256.0,color_y/256.0,color_z/256.0);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    else if(cv.modoVisu==modoIluminacionSombreadoPlano)
    {
      glShadeModel(GL_FLAT);

      if (!coords_textura.empty()) {
        glTexCoordPointer(2, GL_FLOAT, 0, &coords_textura.front());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      }

      if (!normales_vertices.empty()) {
        glNormalPointer(GL_FLOAT, 0, &normales_vertices.front());
        glEnableClientState(GL_NORMAL_ARRAY);
      }

      glDrawElements(GL_TRIANGLES, 3 * tri.size(), GL_UNSIGNED_INT, &tri.front());

      glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      glDisableClientState(GL_NORMAL_ARRAY);
    }

    else if(cv.modoVisu==modoIluminacionSombreadoSuave)
    {
      glShadeModel(GL_SMOOTH);
      if (!coords_textura.empty()) {
        glTexCoordPointer(2, GL_FLOAT, 0, &coords_textura.front());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      }

      if (!normales_vertices.empty()) {
        glNormalPointer(GL_FLOAT, 0, &normales_vertices.front());
        glEnableClientState(GL_NORMAL_ARRAY);
      }

      glDrawElements(GL_TRIANGLES, 3 * tri.size(), GL_UNSIGNED_INT, &tri.front());

      glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      glDisableClientState(GL_NORMAL_ARRAY);
    }

    if(VBOs == false && cv.VBOs == true){
      crearVBOs();
      VBOs=true;
    }

    if(VBOs)
      visualizarVBOs();
    else
      visualizarDE(Ajedrez);
}

static Tupla3f normalizar(Tupla3f t) {
  return (t(X) != 0 || t(Y) != 0 || t(Z) != 0) ? t.normalized() : Tupla3f(1, 0, 0);
}

void MallaInd::calcularNormales()
{
  normales_vertices.reserve(ver.size());
  normales_caras.reserve(tri.size());
  for(int i=0; i<ver.size();++i)
    normales_vertices[i] = Tupla3f(0,0,0);

  for(int i=0; i<tri.size();++i)
  {
    int c1 = tri[i](0);
    int c2 = tri[i](1);
    int c3 = tri[i](2);

    Tupla3f p = ver[c1];
    Tupla3f q = ver[c2];
    Tupla3f r = ver[c3];

    Tupla3f a = q - p;
    Tupla3f b = r - p;

    Tupla3f mc = b.cross(a);
    normales_caras.push_back(mc);
  }

  for(int i=0; i<tri.size(); ++i)
  {
    for(int j=0; j<3; ++j)
    {
      int v = tri[i][j];
      normales_vertices[v] = normales_vertices[v] + normales_caras[i];
    }
  }
  std::transform(normales_caras.begin(), normales_caras.end(),normales_caras.begin(), normalizar);
  std::transform(normales_vertices.begin(), normales_vertices.end(),normales_vertices.begin(), normalizar);

}
