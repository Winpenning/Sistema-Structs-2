# Sistema-Structs-2

Usar ponteiros e alocação dinâmica para criar vetores das 3 structs na main. Ex:

Autor *autores[20];

Livro *livros[20];

Personagem *personagens[20];

Dentro das structs também utilizar ponteiros para o vetor da estrutura interna. Ex:

typedef struct _autor{

   int id;

   char titulo[30];

   Livro livros[20];

   int numLivros;

}

No menu inserir opções de atribuir itens de uma estrutura para outra. Ex:

7 - Adicionar livro para autor.

8 - Adicionar personagem para livro.

O mesmo personagem pode ser utilizado para multiplios livros.
