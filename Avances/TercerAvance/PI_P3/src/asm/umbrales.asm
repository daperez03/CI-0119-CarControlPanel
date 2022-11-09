global umbrales
  section .data
    data: dq 0
    min: dq 0
    max: dq 0
  section .text
    umbrales:
      mov [data], rdi
      cmp qword[data], rsi
      jl True
      cmp qword[data], rdx
      jg True
      jmp False
    True:
      xor eax, eax
      mov rax, 1
      jmp Fin
    False:
      xor eax, eax
      mov rax, 0
    Fin:
      ret