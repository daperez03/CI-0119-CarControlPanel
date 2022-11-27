global pressure_simulation
  section .data
    param1: dq 0  
    
  section .text
    pressure_simulation:
      xor eax, eax
      cmp rdi, 0
      jle Fin
      mov [param1],rdi
      call Aleatorio
      cmp rax, 3
      jle decrementarPre
      mov rax, [param1]
      jmp Fin

    decrementarPre:
      mov rax, [param1]
      dec rax
      jmp Fin

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
    
    Fin:
      ret
