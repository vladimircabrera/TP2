# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/* MENSAJES */
# define MSJ_BIENVENIDA "BIENVENIDO AL PROGRAMA DE MUESTREO DE FUNCIONES"
# define MSJ_SELECCION_ESTADO "INGRESE EL NUMERO DE LA OPCION QUE DESEE:"
# define MSJ_TIEMP_INIC "INGRESE EL TIEMPO EN EL QUE DESEA INICIAR EL MUESTREO:"
# define MSJ_TIEMP_FINAL "INGRESE EL TIEMPO EN EL QUE DESEA FINALIZAR EL MUESTREO:"
# define MSJ_NUM_MUESTRAS "INGRESE LA CANTIDAD DE MUESTRAS QUE DESEA TOMAR:"
# define MSJ_AMPLITUD "INGRESE UN VALOR PARA LA AMPLITUD:"
# define MSJ_FRECUENCIA "INGRESE UN VALOR PARA LA FRECUENCIA:"
# define MSJ_ANG_INIC "INGRESE UN VALOR PARA EL ANGULO INICIAL:"

/* VALORES DEL MENU */
# define SELEC_M_PRINC 'a'
# define SELEC_M_FUNC 'b'
# define SELEC_SIN 'c'
# define SELEC_LOG 'd'
# define SELEC_LINEAL 'e'
# define SELEC_EXP 'f'
# define SELEC_HEAV 'g'
# define SELEC_MRUA 'h'
# define SELEC_PARAB 'i'
# define SELEC_SALIR 'q'

# define PI 3.14

/* MENSAJES DE ERROR */
# define ERR_INGRESO "LA OPCION INGRESADA NO ES CORRECTA."

typedef enum {	MENU_PRINCIPAL = SELEC_M_PRINC,
				MUES_FUNCION = SELEC_M_FUNC,
				SENOIDAL = SELEC_SIN,
				LOGARITMICA = SELEC_LOG,
				LOG_LINEAL = SELEC_LINEAL,
				EXPONENCIAL = SELEC_EXP,
				HEAVISIDE = SELEC_HEAV,
				MRUA = SELEC_MRUA,
				PARAB_HIP = SELEC_PARAB,
				SALIDA = SELEC_SALIR } menu_t;

int main (void)
{

	menu_t st = MENU_PRINCIPAL;

	float temp_i, temp_f, rango_muestra, resultado;

	float aux_a, aux_b, aux_c;
	long int n_muestras;
	int user_choice, i, c;

	puts(MSJ_BIENVENIDA);

	while (st != SALIDA)
	{

		puts (MSJ_SELECCION_ESTADO);
		printf ("\t%c. %s\n\t%c. %s\n", MUES_FUNCION, "MUESTREO DE FUNCIONES", SALIDA, "SALIR DEL PROGRAMA");

		st = tolower(getchar ());
		while ((c = getchar()) != '\n' && c != EOF);

		switch (st)
		{

			case MUES_FUNCION:

				do{
					puts("INGRESE LOS VALORES DEL TIEMPO INICIAL, TIEMPO FINAL Y CANTIDAD DE MUESTRAS EN ESE ORDEN:");
					if(scanf("%f%f%i", &temp_i, &temp_f, &n_muestras) != 3){
						fprintf(stderr, "%s\n", ERR_INGRESO);
						while ((c = getchar()) != '\n' && c != EOF);
					}else if(n_muestras == 0){
						fprintf(stderr, "%s\n", ERR_INGRESO);
						printf("%s\n", "El numero de muestras no puede ser 0");
					}
				}while(temp_i > temp_f);

				while ((c = getchar()) != '\n' && c != EOF);

                rango_muestra = (temp_f-temp_i)/n_muestras;

				puts(MSJ_SELECCION_ESTADO);
				printf("\t%c. %s\n\t%c. %s\n\t%c. %s\n\t%c. %s\n\t%c. %s\n\t%c. %s\n\t%c. %s\n\t%c. %s\n", SELEC_SIN, "SENOIDAL", SELEC_LOG, "LOGARITMICA", SELEC_LINEAL, "LOG LINEAL", SELEC_EXP, "EXPONENCIAL", SELEC_HEAV, "HEAVISIDE", SELEC_MRUA, "MRUA", SELEC_PARAB,"PARAB_HIP", SELEC_M_PRINC, "VOLVER AL MENUN PRINCIPAL");
				
				st = tolower(getchar ());
				while ((c = getchar()) != '\n' && c != EOF);

				while(st != MENU_PRINCIPAL){

					switch(st){

						case SENOIDAL:

							printf("%s\n", MSJ_AMPLITUD);
                			scanf("%f", &aux_a);
                			printf("%s\n", MSJ_FRECUENCIA);
                			scanf("%f", &aux_b);
                			printf("%s\n", MSJ_ANG_INIC);
                			scanf("%f", &aux_c);
                			printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR);

                			for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                			{
                				printf("\t%.*f\t%.*f\n", prec_dec,temp_i, prec_dec, senoidal(aux_a, aux_b, temp_i, aux_c));
                			}
							
							st = MENU_PRINCIPAL;
							break;

						case LOGARITMICA:
							puts("Eligio la funcion logaritmica");
							st = MENU_PRINCIPAL;
							break;

						case LOG_LINEAL:
							puts("eligio la funcion logaritmica lineal");
							st = MENU_PRINCIPAL;
							break;

						case EXPONENCIAL:
							puts("eligio la funcion exponencial");
							st = MENU_PRINCIPAL;
							break;

						case HEAVISIDE:
							puts("eligio la funcion HEAVISIDE");
							st = MENU_PRINCIPAL;
							break;

						case MRUA:
							puts("eligio la funcion de movimiento rectilineo uniformemente variado");
							st = MENU_PRINCIPAL;
							break;

						case PARAB_HIP:
							puts("eligio la funcion de paraboloide hiperbolico");
							st = MENU_PRINCIPAL;
							break;

						default:
							printf("%s\n", ERR_INGRESO);
                        	st = MENU_PRINCIPAL;
                        	break;
                	}
                }

				break;

			case SALIDA:

				puts ("va a salir del programa");
				break;

			default:

				printf("%s\n", ERR_INGRESO);
                st = MENU_PRINCIPAL;
                break;

		}
	}

	return 0;
}
