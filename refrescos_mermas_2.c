#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estructura para almacenar los datos de un refresco
struct Refresco {
    char nombre[50];
    int existencias;
    int ventas;
};

// Estructura para almacenar los datos de una merma de refresco
struct Merma {
    char nombre[50];
    float costo;
    float totalPerdida;
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif
}

void inicializarMermas(struct Merma* mermas, int size) {
    for (int i = 0; i < size; i++) {
        strcpy(mermas[i].nombre, "");
        mermas[i].costo = 0.0;
        mermas[i].totalPerdida = 0.0;
    }
}

int main() {
    // Datos del estudiante
    // Nombre: Marco Alejandro Urías Ramírez
    // Fecha de elaboración: 06/junio/2023
    // Grupo: DS-DIIS-2301-B2-004

    // Inicializar existencias de refrescos
    struct Refresco refrescos[] = {
        {"Agua", 5, 0},
        {"Refresco de sabor", 5, 0},
        {"Refresco sabor cola", 5, 0},
        {"Agua mineral", 5, 0},
        {"Jugo", 5, 0}
    };

    // Inicializar mermas de refrescos
    struct Merma mermas[5]; // Se asume que hay 5 tipos de refrescos
    inicializarMermas(mermas, sizeof(mermas) / sizeof(mermas[0]));

    // Obtener fecha actual
    time_t tiempo_actual = time(NULL);
    struct tm* fecha_actual = localtime(&tiempo_actual);

    // Menú principal
    int opcion;
    while (1) {
        clearScreen();
        printf("*******************************************\n");
        printf("MENÚ PRINCIPAL\n");
        printf("*******************************************\n");
        printf("1. Registrar venta\n");
        printf("2. Mostrar existencias\n");
        printf("3. Mostrar ventas\n");
        printf("4. Mostrar ingresos\n");
        printf("5. Mermas de refresco\n");
        printf("6. Mostrar pérdida económica por mermas\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");

        scanf("%d", &opcion);

        // Limpiar el búfer de entrada
        while (getchar() != '\n');

        switch (opcion) {
            case 1: {
                clearScreen();
                printf("Tipos de refrescos disponibles:\n");
                for (int i = 0; i < sizeof(refrescos) / sizeof(refrescos[0]); i++) {
                    printf("%d. %s\n", i + 1, refrescos[i].nombre);
                }

                int tipo_refresco;
                printf("Ingrese el número de opción del refresco vendido: ");
                scanf("%d", &tipo_refresco);

                if (tipo_refresco >= 1 && tipo_refresco <= sizeof(refrescos) / sizeof(refrescos[0])) {
                    int indice_refresco = tipo_refresco - 1;

                    if (refrescos[indice_refresco].existencias > 0) {
                        refrescos[indice_refresco].existencias--;
                        refrescos[indice_refresco].ventas++;
                        printf("Venta registrada con éxito.\n");
                    } else {
                        printf("No hay existencias disponibles para ese tipo de refresco.\n");
                    }
                } else {
                    printf("Opción no válida.\n");
                }

                break;
            }

            case 2: {
                clearScreen();
                printf("Existencias:\n");
                for (int i = 0; i < sizeof(refrescos) / sizeof(refrescos[0]); i++) {
                    printf("%s: %d\n", refrescos[i].nombre, refrescos[i].existencias);
                }

                break;
            }

            case 3: {
                clearScreen();
                printf("Ventas:\n");
                for (int i = 0; i < sizeof(refrescos) / sizeof(refrescos[0]); i++) {
                    printf("%s: %d\n", refrescos[i].nombre, refrescos[i].ventas);
                }

                break;
            }

            case 4: {
                clearScreen();
                int ingresos = 0;
                for (int i = 0; i < sizeof(refrescos) / sizeof(refrescos[0]); i++) {
                    ingresos += refrescos[i].ventas;
                }

                printf("Ingresos por ventas de refresco de este día: $%d\n", ingresos);

                break;
            }

            case 5: {
                clearScreen();
                printf("Tipos de refrescos disponibles para mermas:\n");
                for (int i = 0; i < sizeof(refrescos) / sizeof(refrescos[0]); i++) {
                    printf("%d. %s\n", i + 1, refrescos[i].nombre);
                }

                int tipo_refresco;
                printf("Ingrese el número de opción del refresco para la merma: ");
                scanf("%d", &tipo_refresco);

                if (tipo_refresco >= 1 && tipo_refresco <= sizeof(refrescos) / sizeof(refrescos[0])) {
                    int indice_refresco = tipo_refresco - 1;

                    char nombre_refresco[50];
                    float costo;
                    printf("Ingrese el costo del refresco para la merma: $");
                    scanf("%f", &costo);

                    strcpy(mermas[indice_refresco].nombre, refrescos[indice_refresco].nombre);
                    mermas[indice_refresco].costo = costo;
                    mermas[indice_refresco].totalPerdida += costo;
                    printf("Merma registrada con éxito.\n");
                } else {
                    printf("Opción no válida.\n");
                }

                break;
            }

            case 6: {
                clearScreen();
                printf("Pérdida económica por mermas:\n");
                float totalPerdida = 0.0;
                for (int i = 0; i < sizeof(mermas) / sizeof(mermas[0]); i++) {
                    printf("%s: $%.2f\n", mermas[i].nombre, mermas[i].totalPerdida);
                    totalPerdida += mermas[i].totalPerdida;
                }
                printf("Total pérdida económica por mermas: $%.2f\n", totalPerdida);

            break;
            }

            case 7: {
                clearScreen();
                printf("Fin del programa\n");
                return 0;
            }

            default: {
                clearScreen();
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
                break;
            }
        }

        // Esperar a que el usuario presione Enter para continuar
        printf("\nPresione Enter para continuar...");
        getchar();
    }

    return 0;
}
