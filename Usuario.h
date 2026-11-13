
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <iostream> 

using namespace std;

// estructura PUBLICACION

struct Publicacion {
    string contenido;
    string fecha;
};



// estructura USUARIO

struct Usuario {
    string username;
    string password;
    vector<Publicacion> posts;
    vector<string> amigos;
};

// funcion mostrar perfil
void mostrarPerfil(const Usuario& u);

// funcion agregar publicacion

void agregarPublicacion(
    Usuario& u,
    const string& texto
);

#endif
