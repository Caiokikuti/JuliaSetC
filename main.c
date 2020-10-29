#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

void juliaSet(int largura, complex c, int alturam, double raio, int iter){
    int x,y,z,i;
    complex z0, z1;

    for(x=0;x<largura;x++){
        for(y=0;y<altura;y++){
            z0 = mapear(largura, altura, x y);
            for(i = 1;i <= iter;i++){
                z1 = add(sqr(z0), c);
                if(mod(z1)>raio){
                    putpixel(x,y, i%15+1);
                }
                z0 = z1;
            }
            if(i>iter) putpixel(x,y,0);
        }
    }
}

int main(){
    int altura = 600;
    int largura = 600;

    complex c;
    c.x = -0.1;
    c.y = 0.8;

    initwindow(largura, altura, "juliaSet");
    juliaSet(largura, altura, c, 16, 100);

}