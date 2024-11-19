#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int main(void)
{
  const int fd1 = open("arquivo.txt", O_RDONLY); //arquivo com 3 linhas
  const int fd2 = open("foobar.txt", O_RDONLY); //arquivo com 1 linha
  char  *line;

  if (fd1 == -1 || fd2 == -1)
  {
    printf("=OH NO\n");
    return(1);
  }
   printf("\n===>\n ");
  line = get_next_line(fd1); // leu todo o arquivo, mas só volta primeira linha
  printf("%s===>", line);
  printf("\n===>\n ");
  free(line);
  line = get_next_line(fd2); // leu todo o arquivo, mas só volta a única linha
  printf("\n===>\n ");
  printf("%s", line);
  printf("\n===>\n ");
  free(line);
  printf("\n===>\n ");
  line = get_next_line(fd1); // não precisa ler pq já leu tudo 6 linhas acima, então só retorna a próxima linha
  printf("%s", line);
  printf("\n===>\n ");
  free(line);
  close(fd1);
  close(fd2);
  // leak de memória pq ainda falta limpar 1 linha q ficou na gnl, mas é só um exemplo, normalmente quando vcs usarem a gnl vão ler até a função voltar NULL
}