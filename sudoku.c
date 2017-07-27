/* risolve i SUDOKU
 * approccio euristico
 * con l'intelligenza si risolve tutto
 */

#include "sudoku.h"
 
void ricorsiva( int griglia[10][10], int possibilita[10][10][10] );

int main()
{
   int griglia[10][10] = { {0,0,0,0,0,0,0,0,0,0}, {0,0,9,0,0,0,0,0,0,5}, {0,0,0,6,0,2,0,0,0,0},{0,7,0,0,1,0,3,0,4,0}, {0,3,8,0,0,0,4,0,0,0}, {0,0,2,0,0,7,0,0,9,0}, {0,0,0,0,3,0,0,0,7,8}, {0,0,1,0,5,0,8,0,0,9}, {0,0,0,0,0,6,0,2,0,0}, {0,6,0,0,0,0,0,0,1,0} };
   
   int possibilita[10][10][10];
   
   stampaGriglia( griglia );

   azzeraPossibilita( possibilita );

   ricorsiva( griglia, possibilita );

   return 0;
}

void ricorsiva( int griglia[10][10], int possibilita[10][10][10] )
{
   if( finito( griglia ) ){
      printf("Ecco la soluzione:\n");
      stampaGriglia( griglia );
   }
   else {
      togliPossibilita( griglia, possibilita );
      inserisci( griglia, possibilita );
      togliPossibilita( griglia, possibilita );
      inserisciDifficile( griglia, possibilita );
      ricorsiva( griglia, possibilita );
   }
}
