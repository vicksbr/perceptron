# Perceptron
Implementação do perceptron em linguagem C


Dependências:
   GSL - GNU Scientific Library
   

Passos)

Para ambientes que utilizem o gerenciador apt

  apt-get install gsl-bin libgsl-dev libgsl2
  
Para compilar linkando as bibliotecas necessárias

  gcc -o teste Main.c -lgsl -lgslcblas -lm


########################################################################################

Caso algum problema, verificar as bibliotecas instaladas com o comando ldconfig -p | grep gsl 

Meus resultados:

libgslcblas.so.0 (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libgslcblas.so.0
libgsl.so.19 (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libgsl.so.19

########################################################################################

Não consegui ainda configurar o makefile pelo Netbeans 
