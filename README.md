# TrabalhoDeCompiladores2
Trabalho referente à disciplina de Compiladores no semestre 2023.1. 

Alunas: Gabriela Pinheiro e Karina Lemos 

### Input
O código de entrada deverá ser inserido no arquivo entrada.txt

A pasta Exemplos possui diferentes exemplos de códigos que podem ser usados. 

### **Este trabalho necessita o uso do Bison3** 

## Como rodar o lex e o bison:
 ### Linux/Mac:
    make
### Windows:    
Este comando considera que o usuário tenha instalado o pacote [WinFlexBison](https://community.chocolatey.org/packages/winflexbison3).

    make win

Caso contrário, é possível usar o comando anterior.
### Rodar somente o scanner (Depois de já ter sido gerado):
    make scan

### Rodar somente o scanner imprimindo a árvore no terminal (Depois de já ter sido gerado):
    make scan_terminal

## Output 
Em caso de erros a saída é uma mensagem de erro
  #### Erro léxico ou sintático:
  - Linha x: sintax error

  #### Erro semântico:
  ##### Verificação de tipos
  - Linha x: Operação inválida entre os tipos "nome do tipo" e "nome do tipo"
  
  Consideramos apenas operações inválidas entre os tipos:
  - Float e char
  - Int e char
  ##### Contexto de identificadores
  - Linha x: Identicador 'nome do identificador' nao declarado anteriormente 
  - Linha x: Identificador 'nome do identificador' já declarado anteriormente

Em caso de nenhum erro a saída é uma árvore escrita no arquivo saida.txt.

## Atuação de cada membro
- [x] Scanner + parser bottom-up -> Karina e Gabriela

- [x] Transformação de laços de repetição em desvios incondicionais (goto) -> Gabriela

- [x] Verificação de tipos -> Gabriela

- [x] Contexto de identificadores -> Karina


## Restrições de implementação
Existem duas restrições de implementações conhecidas neste trabalho:
- Não é feita a checagem do tipo e quantidade dos argumentos ao se usar uma função. Só se verifica se eles já foram declarados.
- Não existe distinção entre um indentificador que delimite uma função de uma variável. Logo, ao se executar uma função não se verifica se aquele identificador representa uma função ou variável. 
