# include <stdio.h>
# include <math.h>
# include "defines.h"
# include "prototipos.h"



typedef enum {	MENU_ENTRADA,
				SENOIDAL,
				LOGARITMICA,
				LOG_LINEAL,
				EXPONENCIAL,
				HEAVISIDE,
				MRUA,
				PARAB_HIP,
				SALIDA} status_t;


status_t selec_menu (int);


int main (void)
{
	status_t st= MENU_ENTRADA;
	float temp_i, temp_f, rango_muestra, resultado;
	float aux_a, aux_b, aux_c;
	long int n_muestras;
	int user_choice, i;

printf("%s\n", MSJ_BIENVENIDA);

    while(st != SALIDA)
    {

        switch(st)
        {
            case MENU_ENTRADA:

				printf("%s\n", MSJ_SELECCION_ESTADO);
				printf("\t%i. %s\n\t%i. %s\n\t%i. %s\n\t%i. %s\n\t%i. %s\n\t%i. %s\n\t%i. %s\n\t%i. %s\n", SELEC_SIN, "SENOIDAL", SELEC_LOG, "LOGARITMICA", SELEC_LINEAL, "LOG LINEAL", SELEC_EXP, "EXPONENCIAL", SELEC_HEAV, "HEAVISIDE", SELEC_MRUA, "MRUA", SELEC_PARAB,"PARAB_HIP", SELEC_SALIR, "SALIDA");
				scanf("%i", &user_choice);
				
				st= selec_menu(user_choice);
                
            break;

            case SENOIDAL:

                printf("%s\n", MSJ_TIEMP_INIC);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL);
                scanf("%f", &temp_f);
                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;
                printf("%s\n", MSJ_AMPLITUD);
                scanf("%f", &aux_a);
                printf("%s\n", MSJ_FRECUENCIA);
                scanf("%f", &aux_b);
                printf("%s\n", MSJ_ANG_INIC);
                scanf("%f", &aux_c);
                printf("\t%s\t%s\n", "x", "f(x)");

                for(temp_i, i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, senoidal(aux_a, aux_b, temp_i, aux_c));
                }
                
            	st = MENU_ENTRADA;
            break;
        }
    }
return 1;
}


double senoidal(int amplitud, int frecuencia, float t, int angulo_inicial){
	/*y(t) = A · sin(2π · f · t + φ)*/
	float resultado;
	resultado=amplitud*sin(2*PI*frecuencia*t+angulo_inicial);
	return resultado;
}

status_t selec_menu (int a)
{
	status_t st;
	switch(a)
                    {
                        case SELEC_SIN:
                            st= SENOIDAL;
                        break;

                        case SELEC_LOG:
                        	st= LOGARITMICA;
                        break;

                        case SELEC_LINEAL:
                        	st= LOG_LINEAL;
                        break;

                        case SELEC_HEAV:
                        	st= HEAVISIDE;
                        break;

                        case SELEC_EXP:
                        	st= EXPONENCIAL;
                        break;

                        case SELEC_MRUA:
                        	st= MRUA;
                        break;

                        case SELEC_PARAB:
                        	st= PARAB_HIP;
                        break;

                        case SELEC_SALIR:
                        	st= SALIDA;
                        break;

                        default:
                        	printf("%s\n", ERR_INGRESO);
                        	st= MENU_ENTRADA;

                    }
    return st;
}
