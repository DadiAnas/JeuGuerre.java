#include "customer.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/***************************************************************************************************************************************/
/************************************************* Customer Management Functions  *******************************************************/
/***************************************************************************************************************************************/

/*Help of this function is to create new Client */

Client* createClient(int codeClient,char* nom,char* prenom,char* telephone){
  Client *new_Client=(Client*)malloc(sizeof(Client));
  /* check new create memory are allocate or not. */
  if(new_Client)
  {
      /*Assign data to newly created ClientElement.*/
    new_Client->codeClient=codeClient;
    new_Client->nom=(char*)malloc(sizeof(char)*25);
    new_Client->nom=nom;
    new_Client->prenom=(char*)malloc(sizeof(char)*25);
    new_Client->prenom=prenom;
    new_Client->telephone=(char*)malloc(sizeof(char)*25);
    new_Client->telephone=telephone;

    return new_Client;
  }
    else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
    return NULL;
  }
}

 /* Help of this function is to display client data */
void displayClient(Client *temp){
    /*print Client list */
      printf("code: %d  ",temp->codeClient);
      printf("nom: %s  ",temp->nom);
      printf("prenom: %s  ",temp->prenom);
      printf("telephone: %s \n",temp->telephone);
}


/*help of this function is to insert the given client on end position of ClientElement linked list*/
void addClientToList(ClientElement**Clientlist,int codeClient,char* nom,char* prenom,char* telephone){

    /* create new memory block using malloc function. */
    ClientElement*temp=NULL,*new_ClientElement=(ClientElement*)malloc(sizeof(ClientElement));
    new_ClientElement->client=createClient(codeClient,nom,prenom,telephone);
    new_ClientElement->next=NULL;

    if(*Clientlist==NULL){
      /*When Client list are empty. Insert first ClientElement*/
      *Clientlist=new_ClientElement;
    }
    else{
      /*When Client list are not empty*/

      /*Client list first ClientElement address assign on temp pointer*/
      temp=*Clientlist;

      /*This will loop find last ClientElement of exist linked Client list*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;
      }

      /*assign this newly created ClientElement on end of list*/
      temp->next=new_ClientElement;

    }
}

/* modify a Client in the list */
void modifyClient(ClientElement** clientList,int find_Client,char* new_nom, char*new_prenom, char* new_telephone){
  if(clientList==NULL){
    /*Client list are empty*/
    printf("Client list are empty\n");
  }
  else
  {
    ClientElement *temp=(*clientList);
    while(temp){
      /*If search Client exist*/
      if(temp->client->codeClient==find_Client){
        /*Client exist*/
        temp->client=createClient(find_Client,new_nom,new_prenom,new_telephone);
        return;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Client not exist*/
    printf("\n Given Client code %d are note exist to modify",find_Client);

  }
}


/* Help of this function showing all element of single Client list*/
void displayClientsList(ClientElement*temp){
    printf("\n==================================================================");
	printf("\n\n======================\t CLIENTS LIST \t==========================");
	printf("\n\n==================================================================\n\n");
  if(temp==NULL){
    /*Client list are empty*/
    printf("Empty linked Client List\n");
  }
  else
  {
    /*When Client list are not empty*/
    while(temp)
    {
      /*print Client list Client*/
      displayClient(temp->client);
      /*move next memory block*/
      temp=temp->next;
    }

  }
  printf("\n\n==================================================================\n\n");
}

/* Get a Client from the linked list ClientElement*/
Client *getClient(ClientElement*temp,int find_Client){

  if(temp==NULL){
    /*Client list are empty*/
    printf("Empty Client List\n");
  }
  else
  {
    while(temp){
      /*If search Client exist*/
      if(temp->client->codeClient==find_Client){
        /*Client exist*/
        return temp->client;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Client not exist*/
    printf("\n Given Client code [%d] are note exist",find_Client);
    return NULL;
    }
}
 /*help of this function is to delete a client from the linked list in any position */
void deleteClient(ClientElement** Clientlist,int delete_value){

  if(*Clientlist!=NULL){
    int status=0;
    ClientElement *helper=*Clientlist,*temp=*Clientlist;

    /*If the client in the first position*/
    if((*Clientlist)->client->codeClient==delete_value){

      *Clientlist=helper->next;
      helper->next=NULL;

      /*Free linked list Client*/
      free(helper);
      helper=NULL;

    }else{

      /*Find Client in the linked list*/
      while(temp){

        if(temp->client->codeClient==delete_value){
          /*Delete Client are exist*/
            status=1;
          break;
        }
        helper=temp;
        /*Point next memory block*/
        temp=temp->next;
      }
      if(status==1){

        helper->next=temp->next;

        /*Free linked list Client*/
        free(temp);
        temp=NULL;
      }else{
        printf("\n Delete Client with code =%d Not exist",delete_value);
      }
    }


  }
  else{
    printf("\n Empty Linked list");
  }
}

/*Help of this function removing all Client list element.*/
void deleteAllClient(ClientElement**Clientlist){

  if(*Clientlist){

    ClientElement*temp=*Clientlist;

    while(temp){

      /*Moving Clientlist pointer to on next memory block.*/
      *Clientlist=temp->next;

      /*before removing that linked ClientElement assign
       next pointer codeClient are null.*/
      temp->next=NULL;

      /*Free Client listClientElement element*/
      free(temp);

      temp=*Clientlist;
    }
    printf("\n\nFree ClientElements list of Clients \n");
  }
  else{
    /* When Client list is empty */
    printf("\n Client list is empty \n");
  }

}

int customerIsExist(ClientElement*temp,int codeCustomer){

  if(temp==NULL){
    /*Customers List is empty*/
    return 0;
  }
  else
  {
    while(temp){
      /*If search customer exist*/
      if(temp->client->codeClient==codeCustomer){
        /*sale exist*/
        return 1;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Customer not exist*/
    return 0;

  }
}

