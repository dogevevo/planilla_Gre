#include <stdio.h>
#include <string.h>

// Estructura para almacenar los datos del usuario
struct Usuario {
    char nombre[50];
    char contrasena[50];
};

// Funci�n para registrar un nuevo usuario
void registrar(struct Usuario *usuario) {
    printf("Registro de nuevo usuario\n");
    printf("Nombre de usuario: ");
    scanf("%s", usuario->nombre);
    printf("Contrase�a: ");
    scanf("%s", usuario->contrasena);
    printf("Usuario registrado con �xito.\n");
}

// Funci�n para iniciar sesi�n
int iniciar_sesion(struct Usuario *usuario) {
    char nombre[50];
    char contrasena[50];
    
    printf("Iniciar sesi�n\n");
    printf("Nombre de usuario: ");
    scanf("%s", nombre);
    printf("Contrase�a: ");
    scanf("%s", contrasena);

    if (strcmp(usuario->nombre, nombre) == 0 && strcmp(usuario->contrasena, contrasena) == 0) {
        printf("Inicio de sesi�n exitoso.\n");
        return 1;
    } else {
        printf("Nombre de usuario o contrase�a incorrectos.\n");
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
        printf("2. Iniciar sesi�n\n");
        printf("3. Salir\n");
        printf("Seleccione una opci�n: ");
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
                printf("Opci�n no v�lida. Intente de nuevo.\n");
        }
    }

    printf("Bienvenido al sistema, %s!\n", usuario.nombre);
    return 0;
}

