; TODO(Daniel) Este programa debe el dato a evaluar,la funcion de este es
;devolver un un decremento o el dato sin modficaciones, todo esto
;dependiendo de un una simulacion mediante un random, importante: las gasolina
;una vez se decremente no pueden volver a aumentar
global gas_simulation
  section .data
    data: dq 0

  section .text
    gas_simulation:
      mov [data], rdi
      cmp qword[data], 0
      mov rax, [data]
      je Fin
      call Aleatorio
      cmp al, 11
      je Decremento
      mov rax, [data]
    jmp Fin

    Aleatorio:
      mov rax, 201
      xor rdi, rdi
      syscall

      mov bl, al
      xor rax, rax
      mov al, bl
      mov edx, 0
      mov ecx, 11
      div ecx
      add edx, 1; residuo es un numero de 0-10
      xor rax, rax
      mov al, dl
    ret

    Decremento:
      dec qword[data]
      mov rax, [data]
    Fin:
    ret
