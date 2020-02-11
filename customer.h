#include "librairies.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Structeres section here      ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************************************************************************/
/************************************************* Customer Management Structures ******************************************************/
/***************************************************************************************************************************************/

/* Customer Structere */
typedef struct {
  int codeClient; /* customer code */
  char* nom; /* First name */
  char* prenom; /* Last name*/
  char* telephone; /* Phone number */
}Client;

/*Structure of linked list for customer*/
typedef struct ClientElement{
  Client *client;// data field, Client
  struct ClientElement *next;// pointer field
}ClientElement;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Functions declaration section here       -----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/***************************************************************************************************************************************/
/************************************************* Customer Management Functions declaration *******************************************/
/***************************************************************************************************************************************/

//Functions to Manipulate Customers
Client* createClient(int,char*,char*,char*);
void displayClient(Client *);
//Functions to Manipulate customers list
void modifyClient(ClientElement**, int, char*,char*,char*);
void addClientToList(ClientElement**,int,char*,char*,char*);
int customerIsExist(ClientElement*,int);
void displayClientsList(ClientElement*);
Client *getClient(ClientElement *, int);
void deleteClient (ClientElement **, int);
void deleteAllClient(ClientElement**);
int customerIsExist(ClientElement*,int);
void saveCustomersData(ClientElement*);
