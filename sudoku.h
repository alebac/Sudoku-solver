#include<stdio.h>
#include<stdlib.h>

void stampaGriglia( int griglia[10][10] );
void inserisciGriglia( int griglia[10][10] );
int controllo( int griglia[10][10] );
int controlloLinee( int griglia[10][10] );
int controlloColonne( int griglia[10][10] );
int controlloQuadrati( int griglia[10][10] );
int pieno( int griglia[10][10] );
int finito( int griglia[10][10] );
void azzeraPossibilita( int possibilita[10][10][10] );
void stampaPossibilita( int possibilita[10][10][10] );  
void togliPossibilitaPiene( int griglia[10][10], int possibilita[10][10][10] );
void togliPossibilitaLinee( int griglia[10][10], int possibilita[10][10][10] );
void togliPossibilitaColonne( int griglia[10][10], int possibilita[10][10][10] );
void togliPossibilitaQuadrati( int griglia[10][10], int possibilita[10][10][10] );
void togliPossibilita( int griglia[10][10], int possibilita[10][10][10] );
int unica( int i, int j, int possibilita[10][10][10] );
int lasola( int i, int j, int possibilita[10][10][10] );
void inserisci( int griglia[10][10], int possibilita[10][10][10] );
int unicaPerRiga( int i, int n, int possibilita[10][10][10] );
int colonnaUnicaPerRiga( int i, int n, int possibilita[10][10][10] );
void inserisciDifficile( int griglia[10][10], int possibilita[10][10][10] );

void stampaGriglia( int griglia[10][10] )
{
   int i, j;
   for( i = 1; i < 10; ++i ) {
      for( j = 1; j < 10; ++j )
         printf("%d ", griglia[i][j] );
      printf("\n");
   }
   printf("\n");   
}

void inserisciGriglia( int griglia[10][10] )
{
   int i, j;
   for( i = 1; i < 10; ++i ) 
      for( j = 1; j < 10; ++j )
         scanf("%d", &griglia[i][j] );
}

int controlloLinee( int griglia[10][10] )               // se il numero inserito è sbagliato restituisce 1
{
   int i, j, a;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
      if( griglia[i][j] != 0 ) 
      for( a = 1; a < 10; ++a ) 
         if( griglia[i][j] == griglia[i][a] && a != j )
            return 0; 
   return 1;
}


int controlloColonne( int griglia[10][10] )               // se il numero inserito è sbagliato restituisce 1
{
   int i, j, a;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
      if( griglia[i][j] != 0 ) 
      for( a = 1; a < 10; ++a ) 
         if( griglia[i][j] == griglia[a][j] && a != i )
            return 0; 
   return 1;
}

int controlloQuadrati( int griglia[10][10] )               // se il numero inserito è sbagliato restituisce 1
{
   int i, j, a, b;

   for( i = 1; i < 10; ++i ) {
   for( j = 1; j < 10; ++j ) {
      if( i < 4 && j < 4 && griglia[i][j] != 0) {                       // quadrato alto sinistra
         for( a = 1; a < 4; ++a ) 
         for( b = 1; b < 4; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;              
      }
      if( i < 4 && j > 3 && j < 7 && griglia[i][j] != 0) {              // quadrato alto centro
         for( a = 1; a < 4; ++a ) 
         for( b = 4; b < 7; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;            
      }
      if( i < 4 && j > 6 && griglia[i][j] != 0) {                       // quadrato alto destra
         for( a = 1; a < 4; ++a ) 
         for( b = 7; b < 10; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;                     
      }
      if( i > 3 && i < 7 && j < 4 && griglia[i][j] != 0) {              // quadrato centro sinistra
         for( a = 4; a < 7; ++a ) 
         for( b = 1; b < 4; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;                
      }
      if( i > 3 && i < 7 && j > 3 && j < 7 && griglia[i][j] != 0) {     // quadrato centro centro
         for( a = 4; a < 7; ++a ) 
         for( b = 4; b < 7; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] )
            return 0;                
      }
      if( i > 3 && i < 7 && j > 6 && griglia[i][j] != 0) {              // quadrato centro destra
         for( a = 4; a < 7; ++a ) 
         for( b = 7; b < 10; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;          
      }
      if( i > 6 && j < 4 && griglia[i][j] != 0) {                       // quadrato basso sinistra
         for( a = 7; a < 10; ++a ) 
         for( b = 1; b < 4; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] )
            return 0;              
      }
      if( i > 6 && j > 3 && j < 7 && griglia[i][j] != 0) {              // quadrato basso centro
         for( a = 7; a < 10; ++a ) 
         for( b = 4; b < 7; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;                 
      }
      if( i > 6 && j > 6 && griglia[i][j] != 0) {                       // quadrato basso destra
         for( a = 7; a < 10; ++a ) 
         for( b = 7; b < 10; ++b )      
         if( ( a != i && b != j ) && griglia[i][j] == griglia[a][b] ) 
            return 0;                   
      }
   }} // fine for per ogni casella
   return 1;
}

int controllo( int griglia[10][10] )               // se il numero inserito è sbagliato restituisce 0
{
   if( controlloLinee( griglia ) && controlloColonne( griglia ) && controlloQuadrati( griglia ) ) 
      return 1;
   return 0;
}

int pieno( int griglia[10][10] ) 
{
   int i, j;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
      if( griglia[i][j] == 0 ) 
            return 0; 
   return 1;  

}

int finito( int griglia[10][10] ) 
{
   if( controllo( griglia ) && pieno( griglia ) )
      return 1;
   else
      return 0;   
}

void azzeraPossibilita( int possibilita[10][10][10] )
{
   int i, j, k;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
   for( k = 1; k < 10; ++k )
      possibilita[i][j][k] = k; 
}

void stampaPossibilita( int possibilita[10][10][10] )
{
   int i, j, k, a = 1;

   for( i = 1; i < 10; ++i ) {
   for( j = 1; j < 10; ++j ) {
   printf("%2d: ", a++);
   for( k = 1; k < 10; ++k ) {
      if( possibilita[i][j][k] != 0 ) {
         printf("%d ", possibilita[i][j][k] ); 
      }
   }
   if( a % 9 == 1 ){
      printf("\n");
   }
   printf("\n");
   }}
}

void togliPossibilitaPiene( int griglia[10][10], int possibilita[10][10][10] )
{
   int i, j, a;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
      if( griglia[i][j] != 0 ) 
      for( a = 1; a < 10; ++a ) 
         possibilita[i][j][a] = 0;
}

void togliPossibilitaLinee( int griglia[10][10], int possibilita[10][10][10] )
{
   int i, j, a;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
      if( griglia[i][j] != 0 ) 
      for( a = 1; a < 10; ++a ) 
         possibilita[i][a][ griglia[i][j] ] = 0;
}

void togliPossibilitaColonne( int griglia[10][10], int possibilita[10][10][10] )
{
   int i, j, a;

   for( i = 1; i < 10; ++i ) 
   for( j = 1; j < 10; ++j ) 
      if( griglia[i][j] != 0 ) 
      for( a = 1; a < 10; ++a ) 
         possibilita[a][j][ griglia[i][j] ] = 0;
}

void togliPossibilitaQuadrati( int griglia[10][10], int possibilita[10][10][10] )     // possibilita[a][b][ griglia[i][j] ] = 0;         
{
   int i, j, a, b;

   for( i = 1; i < 10; ++i ) {
   for( j = 1; j < 10; ++j ) {
      if( i < 4 && j < 4 && griglia[i][j] != 0) {                       // quadrato alto sinistra
         for( a = 1; a < 4; ++a ) 
         for( b = 1; b < 4; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;              
      }
      if( i < 4 && j > 3 && j < 7 && griglia[i][j] != 0) {              // quadrato alto centro
         for( a = 1; a < 4; ++a ) 
         for( b = 4; b < 7; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;               
      }
      if( i < 4 && j > 6 && griglia[i][j] != 0) {                       // quadrato alto destra
         for( a = 1; a < 4; ++a ) 
         for( b = 7; b < 10; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;                         
      }
      if( i > 3 && i < 7 && j < 4 && griglia[i][j] != 0) {              // quadrato centro sinistra
         for( a = 4; a < 7; ++a ) 
         for( b = 1; b < 4; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;                    
      }
      if( i > 3 && i < 7 && j > 3 && j < 7 && griglia[i][j] != 0) {     // quadrato centro centro
         for( a = 4; a < 7; ++a ) 
         for( b = 4; b < 7; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;                   
      }
      if( i > 3 && i < 7 && j > 6 && griglia[i][j] != 0) {              // quadrato centro destra
         for( a = 4; a < 7; ++a ) 
         for( b = 7; b < 10; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;           
      }
      if( i > 6 && j < 4 && griglia[i][j] != 0) {                       // quadrato basso sinistra
         for( a = 7; a < 10; ++a ) 
         for( b = 1; b < 4; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;                
      }
      if( i > 6 && j > 3 && j < 7 && griglia[i][j] != 0) {              // quadrato basso centro
         for( a = 7; a < 10; ++a ) 
         for( b = 4; b < 7; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;                     
      }
      if( i > 6 && j > 6 && griglia[i][j] != 0) {                       // quadrato basso destra
         for( a = 7; a < 10; ++a ) 
         for( b = 7; b < 10; ++b )      
            possibilita[a][b][ griglia[i][j] ] = 0;                    
      }
   }} // fine for per ogni casella
}

void togliPossibilita( int griglia[10][10], int possibilita[10][10][10] )
{
   togliPossibilitaPiene( griglia, possibilita );
   togliPossibilitaQuadrati( griglia, possibilita );
   togliPossibilitaColonne( griglia, possibilita );
   togliPossibilitaLinee( griglia, possibilita );
}

int unica( int i, int j, int possibilita[10][10][10] )
{
   int a, c = 0;
   for( a = 1; a < 10; ++a ) {
      if( possibilita[i][j][a] != 0 ) {
         c++;
      }
   }
   if ( c == 1 ) return 1;
   else return 0;
}

int lasola( int i, int j, int possibilita[10][10][10] )
{
   int a, c = 0;
   for( a = 1; a < 10; ++a ) {
      if( possibilita[i][j][a] != 0 ) {
         c = possibilita[i][j][a];
      }
   }
   return c;
}

void inserisci( int griglia[10][10], int possibilita[10][10][10] )
{
   int i, j;

   for( i = 1; i < 10; ++i ) {
   for( j = 1; j < 10; ++j ) {
      if( unica( i, j, possibilita ) )  { 
         griglia[i][j] = lasola( i, j, possibilita );
      }
   }}
}

int unicaPerRiga( int i, int n, int possibilita[10][10][10] )
{
   int a, j, c = 0;
   for( j = 1; j < 10; ++j ) {
   for( a = 1; a < 10; ++a ) {
      if( possibilita[i][j][a] == n ) {
         c++;
      }
   }}
   if ( c == 1 ) return 1;
   else return 0;
}

int colonnaUnicaPerRiga( int i, int n, int possibilita[10][10][10] )
{
   int a, j;
   for( j = 1; j < 10; ++j ) {
   for( a = 1; a < 10; ++a ) {
      if( possibilita[i][j][a] == n ) {
         return j;
      }
   }}
   return 0;
}

void inserisciDifficile( int griglia[10][10], int possibilita[10][10][10] )
{
   int i, j, n;

   for( i = 1; i < 10; ++i ) {
   for( j = 1; j < 10; ++j ) {
   for( n = 1; n < 10; ++n ) {
      if( unicaPerRiga( i, n, possibilita ) )  { 
         griglia[i][colonnaUnicaPerRiga( i, n, possibilita )] = n;
      }
   }}}
}
