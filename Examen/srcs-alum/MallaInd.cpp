//**********************************************************************************************//
//                                                                                              //
//                            Implementación MallaInd.hpp                                       //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include "MallaInd.hpp"
#include <cstdlib>
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

float MallaInd::Minimo(int n)
{
  float min_aux;
  min_aux=(ver[0])(n);
  for(int i=1; i<ver.size(); ++i)
  {
    if((ver[i])(n)<min_aux)
      min_aux=(ver[i])(n);
  }
  return min_aux;
}

float MallaInd::Maximo(int n)
{
  float max_aux;
  max_aux=(ver[0])(n);
  for(int i=1; i<ver.size(); ++i)
  {
    if((ver[i])(n)>max_aux)
      max_aux=(ver[i])(n);
  }
  return max_aux;
}

vector<Tupla3f> MallaInd::MinMax()
{
  vector<Tupla3f> extremos;
  float min_x, min_y, min_z;
  float max_x, max_y, max_z;
  for(int i=0; i<ver.size();++i)
  {
    min_x=Minimo(0);
    min_y=Minimo(1);
    min_z=Minimo(2);

    max_x=Maximo(0);
    max_y=Maximo(1);
    max_z=Maximo(2);
  }
  Tupla3f minimo(min_x,min_y,min_z);
  Tupla3f maximo(max_x,max_y,max_z);
  extremos.push_back(minimo);
  extremos.push_back(maximo);
  return extremos;
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

void MallaInd::visualizarCaja()
{
  glBegin(GL_QUADS);
    for(unsigned i=0; i<6; i++)
    {
      for(unsigned j=0; j<3; ++j)
      {
        unsigned ind_ver=ver[i](j);
        glVertex3fv(ver[ind_ver]);
      }
    }
  glEnd();
}

void MallaInd::visualizarBEAtrTri()
{
  glBegin(GL_TRIANGLES);
  for(unsigned i=0; i<num_tri; ++i)
  {
    if(col_tri.size()>0)
      glColor3fv(col_tri[i]);
/*
    if(nor_tri.size()>0)
      glNormal3fv(nor_tri[i]); //Para normales
*/
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

static Paralelepipedo* caja=NULL;

void MallaInd::visualizarGL(ContextoVis & cv)
{

    if(primera_vez)
    {
      caja = new Paralelepipedo();
      primera_vez=false;
    }
    glColor3f(0,0,0);
    caja->visualizarCaja();

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
    if(VBOs == false && cv.VBOs == true){
      crearVBOs();
      VBOs=true;
    }

    if(VBOs)
      visualizarVBOs();
    else
      visualizarDE(Ajedrez);
}
