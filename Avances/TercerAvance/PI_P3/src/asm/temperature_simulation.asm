; TODO(Daniel) Este programa debe el dato a evaluar,la funcion de este es
;devolver un un decremento o el dato sin modficaciones, todo esto
;dependiendo de un una simulacion mediante un random, importante: las gasolina
;una vez se decremente no pueden volver a aumentar
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
      xor eax, eax
      cmp rdi, 0
      jle end
      push rdi
      mov rax, rsi
      mov rcx, 100
      xor rdx, rdx
      div rcx
      add rax, 6
      push rax
      call Aleatorio
      pop rdx
      cmp rdx, rax
      jge Incremento
      jmp Decremento
    Fin:

    Aleatorio: ;numero del 1 al 10
      mov rax, 201
      xor rdi, rdi
      syscall

      mov bl, al
      xor rax, rax
      mov al, bl
      mov edx, 0
      mov ecx, 11
      div ecx
      add edx, 1
      xor rax, rax
      mov al, dl
    ret

    Decremento:
      pop rax
      dec rax
      jmp end

    Incremento:
      pop rax
      inc rax
      jmp end

    end:
      ret

