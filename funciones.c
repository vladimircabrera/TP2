#include <stdio.h>
#include <math.h>
#define PI 3.14



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
double paraboloide(int a, int b, float t){
	float resultado;
	resultado=(t*t/a*a)-(t*t/b*b);
	return resultado;
}

int muestras(int tiempoinicial, int tiempofinal, int numero_muestras, int opcion){
	float s=(tiempofinal-tiempoinicial)/numero_muestras, resultado, t;
	int amplitud, frecuencia, angulo_inicial;
	int pos_inicial, vel_inicial, aceleracion;
	int a, b,i=0;


		switch(opcion){
			case 1:

				puts("amplitud:");
				scanf("%d", &amplitud);
				puts("frecuencia:");
				scanf("%d", &frecuencia);
				puts("angulo inicial:");
				scanf("%d", &angulo_inicial);
			for (i = 0; i < numero_muestras; i++){
				t=tiempoinicial+numero_muestras*i*s;
				resultado=senoidal(amplitud, frecuencia,t, angulo_inicial);
				printf("%lf\n", resultado);
				}
			break;
			case 2:
			for ( i = 0; i < numero_muestras; i++)
				{t=tiempoinicial+numero_muestras*i*s;
				resultado=logaritmica(t);
				printf("%lf\n", resultado);}
			break;
			case 3:
			for (i = 0; i < numero_muestras; i++)
				{t=tiempoinicial+numero_muestras*i*s;
				resultado=loglineal(t);
				printf("%lf\n", resultado);}
			break;
			case 4:
				for (i = 0; i < numero_muestras; i++)
					{t=tiempoinicial+numero_muestras*i*s;
					resultado=exponencial(t);
					printf("%lf\n", resultado);}
				break;
			case 5:
				for (i = 0; i < numero_muestras; i++)
					{t=tiempoinicial+numero_muestras*i*s;
					resultado=escalon(t);
					printf("%lf\n", resultado);}
				break;
			case 6:

				puts("pos_inicial:");
				scanf("%d", &pos_inicial);
				puts("vel_inicial:");
				scanf("%d", &vel_inicial);
				puts("aceleracion:");
				scanf("%d", &aceleracion);
				for (i = 0; i < numero_muestras; i++)
					{t=tiempoinicial+numero_muestras*i*s;
					resultado=mrua(pos_inicial,vel_inicial, aceleracion, t);
					printf("%lf\n", resultado);}
				break;
			case 7:

				puts("a:");
				scanf("%d", &a);
				puts("b:");
				scanf("%d", &b);
				for (i = 0; i < numero_muestras; i++)
					{t=tiempoinicial+numero_muestras*i*s;
					resultado=paraboloide(a,b,t);
					printf("%lf\n", resultado);}
				break;
		}

}


void main(void){
	int tinicial, tfinal, num,opc;
	puts("Tiempo inicial:");
	scanf("%d", &tinicial);
	puts("Tiempo Final:");
	scanf("%d", &tfinal);
	puts("Numero de muestras:");
	scanf("%d", &num);
	puts("Funcion:");
	scanf("%d", &opc);
	muestras(tinicial,tfinal,num,opc);
	/*logaritmica(1,5,3);*/
}
