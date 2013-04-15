/* * * * * * * * * *
 * client.c
 * Created by: [NAME]
 * * * * * * * * * *
 * Description: 
 * Methods for spawning clients that depend on the proj2 dvd return
 * and checking out library.
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "proj2.h"
#include "printing.h"

/* Data Types */
typedef struct thread_data_struct {
   const char title[50];
   unsigned int copies;
} thread_data;

/* Function Prototypes */
void print_usage(void);

int main(int argc, char **argv)
{
   //allocate memory for variables
   int err;
   unsigned int i;
   unsigned int database_size;
   FILE *database_file;
   char movie_name[50];
   unsigned int movie_quantity;
   pthread_t *clients;

   if( argc != 4 )
      PRINT_USAGE(argv[0]);

   //take in input   
   unsigned int numClients = (unsigned int)atoi(argv[1]);
   double probability = strtod(argv[2]);
   unsigned int numTransactions = (unsigned int)atoi(argv[3]);
   
   //make sure all conditions are met
   if( probability > 1 || probability < 0 )
      PRINT_USAGE_EXTENDED(argv[0]);
   
   //fill the database
   if(!(database_file = fopen("database.db","r"))
      PRINT_ERR("Error opening the database");
   fscanf(database_file,"%d", &database_size);
   for( i = 0; i < database_size; ++i )
   {
      fscanf(database_file,"%s %d", movie_name, movie_quantity);
      memcpy(database[i].title, movie_name, 50);
      database[i].count = movie_quantity;
   }

   clients = (pthread_t *)malloc(numClients*sizeof(pthread_t));
   for( i = 0; i < numClients; ++i )
   {
      clients[i] = create_client();
      pthread_create(&clients[i]);
   }

   for( i = 0; i < numClients; ++i )
      pthread_join(clients[i]);

   return 0;
}

void *client_action(void *p)
{
   unsigned int i;
   thread_data *data = p;
   srand(time());
   for( i = 0; i < data->num_transactions; ++i )
   {
      if(random() > RAND_MAX*data->probability)
         continue;
      else
         continue;
   }
}
