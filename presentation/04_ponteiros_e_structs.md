---
presentation:
 progress: true
 keyboard: true
 center: true 
 controls: false
 margin: 0.3

---

<!-- slide -->
# PONTEIROS PARA STRUCTS

<!-- slide -->
Relembrando o que é uma struct (ou estrutura)...

```cpp
struct Ponto {
  int coordenadaX;
  int coordenadaY;
};

struct Personagem {
  uint vida;
  uint defesa;
  uint ataque;
  char *nome;
};
```

Nada mais é que um tipo definido pelo programador para agrupar dados relacionados e que compõem uma entidade.

<!-- slide -->
Ao inicializarmos uma `struct`, temos que lembrar que o programa alocará uma região **contínua** de memória para guardar todos os dados dela.

Suponha que temos o seguinte código...

```cpp
Personagem p = { 10, 10, 10, "Sherlock" };
cout << "Vida do personagem: " << p.vida << "\n";
// Lembrar que é com . que acessamos um dado de uma struct!
```

Então, o inteiro que representa a vida do personagem estaria alocado na posição fictícia `0xabc1`, o que representa a defesa estaria em `0xabc5`, e etc.

<!-- slide -->
Relembrados os principais detalhes da `struct`, faço uma pergunta: "posso alocar uma `struct` na `heap` e ter um ponteiro para ela?"

Claro!

<!-- slide -->
Para manipular uma `struct` na `heap`, fazemos...

```cpp
// Alocando memória para a struct
Personagem * p = (Personagem *) malloc(sizeof(Personagem));

// Usando a struct
p->vida = 10;
p->defesa = 10;
p->ataque = 10;
p->nome = "Sherlock";

// Liberando a memória alocada
free(p);
```

Simples! Mas e aquele `->`?

<!-- slide -->
## OPERADOR ->

O operador `->` é usado para acessarmos o conteúdo dos campos das `structs`; por trás dos panos, o `->` **derreferencia** o ponteiro e **acessa** o campo desejado.

Sem o `->`, teríamos que fazer sempre...

```cpp
Personagem *p = (Personagem *) malloc(sizeof(Personagem));
// Derreferenciamos para acessar a struct,
// depois acessamos o campo 'vida' da struct.
(*p).vida = 10;

// Podemos fazer isso aqui, que é mais direto
p->vida = 10;
```

Não sei você, mas prefiro o `->`...

<!-- slide -->
Por isso, utilizamos o operador `->` quando temos um **ponteiro para struct**, e operador `.` quando temos **a struct diretamente**.

<!-- slide -->
# EXERCÍCIOS
<!-- slide -->
## Calcular Distância Entre 2 Pontos

Crie uma `struct` de nome `Ponto` com os campos `x` e `y`, ambos do tipo `double`, que representam as coordenadas do ponto no plano cartesiano.

Após isso, aloque dinamicamente dois pontos. Então, leia do usuário as coordenadas dos dois pontos. Depois, calcule a distância dos dois pontos pela fórmula da distância euclidiana e exiba a distância. Por fim, desaloque a memória pros dois pontos e finalize o programa.
<!-- slide -->
Exemplo de saída:

```txt
Digite a coordenada x do ponto 1: 1.0
Digite a coordenada y do ponto 1: 2.0

Digite a coordenada x do ponto 2: 4.0
Digite a coordenada y do ponto 2: 6.0

A distância entre os pontos é: 5.00
```

Vamos pro próximo!

<!-- slide -->
## Controle de Produtos

Primeiro, crie uma `struct` de nome `Produto` com os campos nome (de tipo `char *`), preço (de tipo `float`) e quantidade (de tipo `int`). Depois, crie as seguintes funções:

- Função para alocar e inicializar um vetor de produtos a partir de dados inseridos pelo usuário, e retorná-lo;
- Função para listar todos os produtos cadastrados;
- Função para calcular e exibir o valor total do estoque (o preço de todos os produtos, basicamente);

<!-- slide -->
Então, na sua função `main`, você deve chamar as funções definidas para 1) criar o vetor, 2) exibí-los e 3) exibir o valor total do estoque. Ao final, libere a memória alocada para o vetor.

<!-- slide -->
Exemplo de saída:

```txt
Quantos produtos irá cadastrar? 3

Digite o nome do produto 1: Caneta
Digite o preço do produto 1: 2.5
Digite a quantidade do produto 1: 100

Digite o nome do produto 2: Caderno
Digite o preço do produto 2: 15.0
Digite a quantidade do produto 2: 50

Digite o nome do produto 3: Livro
Digite o preço do produto 3: 40.0
Digite a quantidade do produto 3: 20

Produtos cadastrados:
1. Caneta - R$ 2.50 - 100 unidades
2. Caderno - R$ 15.00 - 50 unidades
3. Livro - R$ 40.00 - 20 unidades

Valor total do estoque: R$ 3500.00
```
