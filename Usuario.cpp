
#include "Usuario.h"

#include <iostream>
#include <string>
using namespace std;

void mostrarPerfil(const Usuario& u) {
    cout << "\n==============================\n";
    cout << "       PERFIL DE USUARIO\n";
    cout << "==============================\n";

    cout << "Username: " << u.username << '\n';

    cout << "\nPublicaciones:\n";

    if (u.posts.empty()) {
        cout << "No hay publicaciones.\n";
    } else {
        for (const auto& post : u.posts) {
            cout << "- " << post.contenido
                      << " (" << post.fecha << ")\n";
        }
    }

    cout << "\nAmigos: " << u.amigos.size() << '\n';

    for (const auto& amigo : u.amigos) {
        cout << "- " << amigo << '\n';
    }

    cout << "==============================\n";
}

void agregarPublicacion(
    Usuario& u,
    const string& texto
) {
    Publicacion nueva;

    nueva.contenido = texto;
    nueva.fecha = "Hoy";

    u.posts.push_back(nueva);

    cout << "¡Publicacion agregada correctamente!\n";
}
