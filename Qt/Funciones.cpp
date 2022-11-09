#include <iostream>
/* TODO(Randy) Este programa debe recibir los umbrales y dato a evaluar,
la funcion de este es devolver un boleano al respecto si estos umbrales
han sido sobrepasados*/
//extern int umbrales(int data, int min, int max);
/* TODO(Daniel) Este programa debe el dato a evaluar,la funcion de este es
devolver un un decremento o el dato sin modficaciones, todo esto
dependiendo de un una simulacion mediante un random, importante: las gasolina
una vez se decremente no pueden volver a aumentar*/
extern "C" int gas_simulation(int data);
/* TODO(Daniel) Este programa debe el dato a evaluar,la funcion de este es
devolver un un decremento, incremento o el dato sin modficaciones, todo esto
dependiendo de un una simulacion mediante un random*/
extern "C" int temperature_simulation(int data);
/* TODO(Randy) Este programa debe el dato a evaluar,la funcion de este es
devolver un un decremento o el dato sin modficaciones, todo esto
dependiendo de un una simulacion mediante un random, importante: las llantas
una vez se desinflen no pueden volver a inflarce*/
//extern "C" int pressure_simulation(int data);

// Implementamos a partir de aca, debemos guiarnos del ejemplo inferior

int main() {
  int64_t gas = 100;
  int64_t temperatura = 100;
  while (gas != 0) {
    std::cout << "Gas: ";
    gas = gas_simulation(gas);
    std::cout << gas << std::endl;
    std::cout << "Temperatura: ";
    temperatura = temperature_simulation(temperatura);
    std::cout << temperatura << std::endl;
  }
  return EXIT_SUCCESS;
}



// Ejemplo de ensambla en C:
/*extern "C" int func();
asm(
   R"(
      .globl func
         .type func, @function
         func:
         .cfi_startproc
         movl $7, %eax
         ret
         .cfi_endproc
   )"
);
 
int main() {
   int n = func();
   // extended inline assembly
   asm (
      "leal (%0,%0,4),%0"
      : "=r" (n)
      : "0" (n)
   );
    std::cout << "7*5 = " << n << std::endl; // flush is intentional
 
    // standard inline assembly
    asm (
      "movq $60, %rax\n\t" // the exit syscall number on Linux
      "movq $2,  %rdi\n\t" // this program returns 2
      "syscall"
   );
}*/
