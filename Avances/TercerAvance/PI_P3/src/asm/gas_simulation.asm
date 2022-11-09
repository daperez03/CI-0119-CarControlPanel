; TODO(Daniel) Este programa debe el dato a evaluar,la funcion de este es
;devolver un un decremento o el dato sin modficaciones, todo esto
;dependiendo de un una simulacion mediante un random, importante: las gasolina
;una vez se decremente no pueden volver a aumentar
global gas_simulation
  section .data

  section .text
    gas_simulation:
      xor eax, eax
      cmp rdi, 3
      jle Fin
      xor eax, eax
      mov rax, rsi
      mov rcx, 100
      xor rdx, rdx
      div rcx
      add rax, 1
      sub rdi, rax
      mov rax, rdi
    Fin:
      ret
