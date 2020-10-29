#include<math.h>
typedef struct{
    double x,y;
}complex;

complex adicao(complex a, complex b){
    complex c;
    c.x = a.x + b.x;
    c.y = a.y +b.y;
    return c;
}

complex sqr(complex a){
    complex c;
    c.x = a.x*a.x - a.y*a.y;
    c.y = 2*a.y*a.x; 
}

double mod(complex a){
    return sqrt(a.x*a.x + a.y*a.y);
}

complex mapear(int largura, int altura, double raio, int x, int y){
    complex c;
    int l;
    if (largura<altura) l=largura;
    else l= altura;
    c.x = 2*raio*(x - largura/2.0)/l;
    c.y = 2*raio*(y - altura/2.0)/l;
    return c;  
}