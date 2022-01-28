Para compilar e executar o programa, abra a pasta no terminal e digite:

$ flex -o src/lex.yy.c src/flex.l
$ bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
$ gcc -o tradutor -g src/syntax.tab.c src/lex.yy.c lib/*.c -Wall -Wpedantic

Para executar os testes digite algumas da seguintes instruções

$ ./tradutor tests/teste-correto1.c
$ ./tradutor tests/teste-correto2.c
$ ./tradutor tests/teste-incorreto1.c
$ ./tradutor tests/teste-incorreto2.c
