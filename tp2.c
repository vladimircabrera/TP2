#include <stdio.h>
#include <math.h>
#include "defines.h"
#include "prototipos.h"



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
	float temp_i, temp_f, rango_muestra, rango_muestra_y, temp_iy, temp_fy;
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
                printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR;

                for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, senoidal(aux_a, aux_b, temp_i, aux_c));
                }
                
            	st = MENU_ENTRADA;
            break;

            case LOGARITMICA:

				printf("%s\n", MSJ_TIEMP_INIC);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL);
                scanf("%f", &temp_f);
                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;   
                printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR;

                 for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, logaritmica(temp_i));
                }
                
            	st = MENU_ENTRADA;
            break;

            case LOG_LINEAL:

            	printf("%s\n", MSJ_TIEMP_INIC);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL);
                scanf("%f", &temp_f);
                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;   
                printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR;

                 for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, loglineal(temp_i));
                }
                
            	st = MENU_ENTRADA;
            break;

            case EXPONENCIAL:

            	printf("%s\n", MSJ_TIEMP_INIC);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL);
                scanf("%f", &temp_f);
                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;   
                printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR;

                 for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, exponencial(temp_i));
                }
                
            	st = MENU_ENTRADA;
            break;

            case HEAVISIDE:

            	printf("%s\n", MSJ_TIEMP_INIC);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL);
                scanf("%f", &temp_f);
                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;   
                printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR;

                 for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, escalon(temp_i));
                }
                
            	st = MENU_ENTRADA;
            break;

            case MRUA:

            	printf("%s\n", MSJ_TIEMP_INIC);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL);
                scanf("%f", &temp_f);
                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;
                printf("%s\n", MSJ_POS_INICIAL);
                scanf("%f", &aux_a);
                printf("%s\n", MSJ_VEL_INICIAL);
                scanf("%f", &aux_b);
                printf("%s\n", MSJ_ACELERACION);
                scanf("%f", &aux_c);
                printf("\t%s\t%s\n", NOMBRE_VAR_1, FUNC_1_VAR;

                for(i=1; i<= n_muestras; temp_i+= rango_muestra, i++)
                {
                	printf("\t%.2f\t%.2f\n", temp_i, mrua(aux_a, aux_b, aux_c, temp_i));
                }
                
            	st = MENU_ENTRADA;
            break;

            case PARAB_HIP:

            	printf("%s\n", MSJ_TIEMP_INIC_X);
                scanf("%f", &temp_i);
                printf("%s\n", MSJ_TIEMP_FINAL_X);
                scanf("%f", &temp_f);

            	printf("%s\n", MSJ_TIEMP_INIC_Y);
                scanf("%f", &temp_iy);
                printf("%s\n", MSJ_TIEMP_FINAL_Y);
                scanf("%f", &temp_fy);

                printf("%s\n", MSJ_NUM_MUESTRAS);
                scanf("%li", &n_muestras);
                rango_muestra= (temp_f-temp_i)/n_muestras;
                rango_muestra_y= (temp_fy-temp_iy)/n_muestras;

                printf("%s\n", MSJ_VAR_A);
                scanf("%f", &aux_a);
                printf("%s\n", MSJ_VAR_B);
                scanf("%f", &aux_b);
                printf("\t%s\t%s\t%s\n", NOMBRE_VAR_1, NOMBRE_VAR_2, FUNC_2_VAR);

                for(i=1; i<= n_muestras; temp_i+= rango_muestra, temp_iy+= rango_muestra_y, i++)
                {
                	printf("\t%.2f\t%.2f\t%.2f\n", temp_i, temp_iy, paraboloide(aux_a, aux_b, temp_i, temp_iy));
                }
                
            	st = MENU_ENTRADA;
            break;

            case SALIDA:

            	return 1;
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

double logaritmica(float t){
/*y(x) = log(x)*/
	float resultado;
	resultado=log(t);
	return resultado;
}

double loglineal(float t){
/*y(n) = n log(n)*/
	float resultado;
	resultado=t*log(t);
	return resultado;
}

double exponencial(float t){
	/*y(x) = ex*/
	float resultado;
	resultado=exp(t);
	return resultado;
}

double escalon(float t){
/*y(x) =
0 si x < 0
1 si x ≥ 0*/
	float resultado;
	if (t<0){resultado=0;}
	else{resultado=1;}

	return resultado;
}

double mrua(float pos_inicial,float vel_inicial, float aceleracion, float t){
	/*x(t) = x0 + v0 · t + a/2 · t*t */
	float resultado;
	resultado=pos_inicial + vel_inicial*t+aceleracion/2*t*t;
	return resultado;
}

double paraboloide(int a, int b, float x, float y){
	float resultado;
	resultado=((x*x/a*a)-(y*y/b*b));
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
                        	printf("\a%s\n", ERR_INGRESO);
                        	st= MENU_ENTRADA;

                    }
    return st;
}

