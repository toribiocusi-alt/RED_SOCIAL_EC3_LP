
#include "RedSocial.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std ;

int buscarUsuario(
    const vector<Usuario>& usuarios,
    const string& username
) {
    for (size_t i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].username == username) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

bool registrarUsuario(
    vector<Usuario>& usuarios,
    const string& user,
    const string& pass
) {
    if (buscarUsuario(usuarios, user) != -1) {
        return false;
    }

    Usuario nuevo;
    nuevo.username = user;
    nuevo.password = pass;

    usuarios.push_back(nuevo);

    return true;
}

int iniciarSesion(
    const vector<Usuario>& usuarios,
    const string& user,
    const string& pass
) {
    int idx = buscarUsuario(usuarios, user);

    if (idx != -1 && usuarios[idx].password == pass) {
        return idx;
    }

    return -1;
}

void enviarSolicitudAmistad(
    vector<Usuario>& usuarios,
    int indexActual,
    const string& amigoUser
) {
    if (indexActual < 0 ||

        indexActual >= static_cast<int>(usuarios.size())) {
        cout << "Indice de usuario invalido.\n";
        return;
    }

    int idxAmigo = buscarUsuario(usuarios, amigoUser);

    if (idxAmigo == -1) {
        cout << "El usuario no existe.\n";
        return;
    }

    if (idxAmigo == indexActual) {
        cout << "No puedes agregarte a ti mismo.\n";
        return;
    }

    // Evitar amistades duplicadas.
    
    for (const auto& amigo : usuarios[indexActual].amigos) {
        if (amigo == amigoUser) {
            cout << "Ya son amigos.\n";
            return;
        }
    }

    usuarios[indexActual].amigos.push_back(amigoUser);
    usuarios[idxAmigo].amigos.push_back(
        usuarios[indexActual].username
    );

    cout << "¡Ahora eres amigo de "
              << amigoUser << "!\n";
}
