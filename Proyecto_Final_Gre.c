#include <stdio.h>
#include <string.h>

// Estructura para almacenar los datos del usuario
struct Usuario {
    char nombre[50];
    char contrasena[50];
};

// Función para registrar un nuevo usuario
void registrar(struct Usuario *usuario) {
    printf("Registro de nuevo usuario\n");
    printf("Nombre de usuario: ");
    scanf("%s", usuario->nombre);
    printf("Contraseña: ");
    scanf("%s", usuario->contrasena);
    printf("Usuario registrado con éxito.\n");
}

// Función para iniciar sesión
int iniciar_sesion(struct Usuario *usuario) {
    char nombre[50];
    char contrasena[50];
    
    printf("Iniciar sesión\n");
    printf("Nombre de usuario: ");
    scanf("%s", nombre);
    printf("Contraseña: ");
    scanf("%s", contrasena);

    if (strcmp(usuario->nombre, nombre) == 0 && strcmp(usuario->contrasena, contrasena) == 0) {
        printf("Inicio de sesión exitoso.\n");
        return 1;
    } else {
        printf("Nombre de usuario o contraseña incorrectos.\n");
        return 0;
    }
}

int main() {
    struct Usuario usuario;
    int opcion;
    int sesion_iniciada = 0;

    while (!sesion_iniciada) {
        printf("\nMenu:\n");
        printf("1. Registrar\n");
        printf("2. Iniciar sesión\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registrar(&usuario);
                break;
            case 2:
                sesion_iniciada = iniciar_sesion(&usuario);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    printf("Bienvenido al sistema, %s!\n", usuario.nombre);
    return 0;
}

