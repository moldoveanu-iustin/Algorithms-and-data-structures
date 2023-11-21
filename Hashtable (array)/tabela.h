#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

void HASH_INIT(int T[], int m);
void HASH_PRINT(int T[], int m);
void HASH_INSERT(int T[], int k, int m);
int HASH_PROBEF(int k, int i, int m);
int HASH_PRIM(int k, int m);
int HASH_SEARCH (int T[], int k, int m);
int HASH_DELETE (int T[], int k, int m);

#endif // TABELA_H_INCLUDED
