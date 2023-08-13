#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

// Calling functions at the end, after main.
void clear();
void jgvelha();
void csfunction(int i, int j, int cvtr[3][3]);
void trerow(int v[11]);

int main()
{
  clear();
  int i, j, mnselect;
  int cvtr[3][3];
  int v[11];
  int random = 4;
  int cont1, cont2;
  setlocale(LC_ALL, "");

  do
  {
    std::cout << "Bem-vindo ao Juego da Velha BINÁRIO!!\n";
    std::cout << "As posições de cada compartimento no juego estão indicadas\n";
    std::cout << "a seguir:..\n";
    jgvelha();
    printf("Selecione o caractere '0' para bolinhas e '1' para cruzinhas.");
    std::cout << "\nAperte '1' se deseja prosseguir..\n";
    scanf("%d", &mnselect);
    clear();
  } while (mnselect != 1); // Set mnselect value to 1 in order to exit the menu.
  // x---------------x
  // Reset every value of cvtr[i][j] to random integer >= 0.
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      cvtr[i][j] = random;
      random++;
    }
  }
  random = 4;
  // x--------------x
  for (mnselect = 1; mnselect < 10; mnselect++)
  {
    v[mnselect] = random;
    random++;
  }
  mnselect = 1;
  jgvelha();
  v[10] = 1;
  do
  { // Beggining of "do_while" type of repetition.
    printf("\n Selecione _posição_ + _caractere escolhido_:");
    scanf("%d %d", &i, &j); // in the matrix to the coordenates choosen.
    csfunction(i, j, cvtr);
    mnselect = 1;
    for (i = 0; i < 3; i++)
    { //"mnselect" = 1 i.e. vector begins in 1 instead of 0.
      for (j = 0; j < 3; j++)
      {
        v[mnselect] = cvtr[i][j]; //<---- 'Error'.
        mnselect++;
      }
    }
    v[10] = 1;
    trerow(v);
  } while (v[10] == 1);
  return 0;
}

void jgvelha()
{ // UI of "jogo da velha".
  std::cout << " 0,0 | 0,1 | 0,2 \n";
  std::cout << "-----|-----|-----\n";
  std::cout << " 1,0 | 1,1 | 1,2 \n";
  std::cout << "-----|-----|-----\n";
  std::cout << " 2,0 | 2,1 | 2,2\n";
}

void clear()
{
  system("clear");
}

void csfunction(int i, int j, int cvtr[3][3])
{ //"Choosing function" attributes a position
  switch (i + j)
  { // in the matrix to the coordenates choosen.
  case 0:
    scanf("%d", &cvtr[0][0]);
    break;
  default:
    scanf("%d", &cvtr[i][j]);
    break;
  case 4:
    scanf("%d", &cvtr[2][2]);
  }
}

void trerow(int v[11])
{
  if (v[1] == v[2] && v[2] == v[3])
  {
    v[10]++;
  }
  else if (v[1] == v[4] && v[4] == v[7])
  {
    v[10]++;
  }
  else if (v[1] == v[5] && v[5] == v[9])
  {
    v[10]++;
  }
  else if (v[4] == v[5] && v[5] == v[6])
  {
    v[10]++;
  }
  else if (v[7] == v[8] && v[8] == v[9])
  {
    v[10]++;
  }
  else if (v[3] == v[5] && v[5] == v[7])
  {
    v[10]++;
  }
  else if (v[2] == v[5] && v[5] == v[8])
  {
    v[10]++;
  }
  else if (v[3] == v[6] && v[6] == v[9])
  {
    v[10]++;
  }
}