; n(Daniel) Este programa debe el dato a evaluar,la funcion de este es
;devolver un un decremento o el dato sin modficaciones, todo esto
;dependiendo de un una simulacion mediante un random, importante: las gasolina
;una vez se decremente no pueden volver a aumentar
global temperature_simulation
  section .data
    param1: dq 0
    param2: dq 0
    probability: dq 0

  section .text
    temperature_simulation:
      mov [param1], rdi
      mov [param2], rsi
      xor eax, eax
      mov rax, [param2]
      mov rcx, 100
      div rcx
      mov qword[probability], rax
      add qword[probability], 5
      call Aleatorio
      cmp qword[probability], rax
      jge Incremento
      jmp Decremento
    Fin:

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
      add edx, 1; residuo es un numero de 1-10
      xor rax, rax
      mov al, dl
    ret

    Decremento:
      dec qword[param1]
      mov rax, [param1]
    ret

    Incremento:
      inc qword[param1]
      mov rax, [param1]
    ret
