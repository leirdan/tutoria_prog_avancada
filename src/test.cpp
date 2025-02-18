#include <iostream>
#include <cstdlib>

void realloc_incorreto()
{
  int *ptr1, *ptr2;

  ptr1 = (int *)calloc(10, sizeof(int));

  std::cout << "valor de p1: " << *ptr1 << "\n";
  std::cout << "endereco de p1: " << ptr1 << "\n";

  ptr2 = ptr1;

  ptr2 = (int *)realloc(ptr2, sizeof(int) * 100);

  std::cout << "valor de p1: " << *ptr1 << "\n";
  std::cout << "endereco de p1: " << ptr1 << "\n";
}

int *gerar_numeros(int tamanho)
{
  int v[10];
  for (int i = 0; i < tamanho; i++)
  {
    v[i] = 0;
  }

  return v; // Permitido!
}

void func1(int x, int y)
{
  x = 0;
  y = x + y;
}

void func2(int *x, int *y)
{
  *x = 0;
  *y = *x + *y;
}

void copia_e_referencia()
{
  int x = 10;
  int y = 20;
  func1(x, y);   // x = 10, y = 20
  func2(&x, &y); // x = 0, y = 20
  std::cout << x << y;
}

int main()
{
}