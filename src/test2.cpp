#include <iostream>

// 1. passagem por referencia usando ponteiro
void func1(int *x)
{
  *x = 10;
}

// 2. passagem por referencia usando valor
void func2(int &x)
{
  x = 10;
};

int main()
{
  int x = 10;
  int *p = &x;

  // Ponteiro guarda:
  // 1. Endereço: &x (0x00asdu12be12)
  // 2. Conteúdo: 10

  // TODO: explicar & e *
  // &p != &x;

  *p = 25;
}