global anticollision_simulation
  anticollision_simulation:
    call Aleatorio
    cmp rax, 1
    je True
  jmp False


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

  True:
    mov rax, 1
  jmp Fin

  False:
    mov rax, 0
  jmp Fin

  Fin:
    ret