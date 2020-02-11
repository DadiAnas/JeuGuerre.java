#include "sales.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/**************************************************************************************************************************************/
/************************************************* Sale Management Functions  *********************************************************/
/**************************************************************************************************************************************/


/*Help of this function is to create new Vente */

Vente* createSale(int codeVente,Date* date,OrderLine* OrderList ,Client* client){
  Vente *new_Vente=(Vente*)malloc(sizeof(Vente));
  /* check new create memory are allocate or not. */
  if(new_Vente)
  {
      /*Assign data to newly created Vente.*/
    new_Vente->codeVente=codeVente;
    new_Vente->OrderList=(OrderLine*)malloc(sizeof(OrderLine));
    new_Vente->OrderList=OrderList;
    new_Vente->date=(Date *)malloc(sizeof(Date));
    new_Vente->date= date;
    new_Vente->client=client;
    return new_Vente;
  }
    else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
    return new_Vente;
  }
}
 /*Help of this function is to display Sale data */
void displaySale(Vente *temp){
    /*print Sale */

      printf("Sale code: %d  ",temp->codeVente);
      printf("date: %d/%d/%d  ",temp->date->jour,temp->date->mois,temp->date->annee);
      printf("Client code: %d  ",temp->client->codeClient);
      printf("total: %.2lf  \n",temp->totale);

}

/*help of this function is to insert the given Sale on end position of SalesList*/
void addSaleToSalesList(SalesList** DB,int codeVente,Date* date,OrderLine* OrderList,Client* client){

    /* create new memory block using malloc function. */
    SalesList *temp=NULL,*new_Vente=(SalesList*)malloc(sizeof(SalesList));
    new_Vente->vente=createSale(codeVente,date,OrderList,client);
    new_Vente->vente->totale=calculeTotale(*DB,client);
    new_Vente->next=NULL;

    if(*DB==NULL){
      /*When SalesList is empty. Insert first Sale*/
      *DB=new_Vente;
    }
    else{
      /*When Sales list is not empty*/
      temp=*DB;

      /*This will loop find last Sale in SalesList*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;
      }

      /*assign this newly created Sale on end of DB*/
      temp->next=new_Vente;

    }
}

/*help of this function is to insert the given Sale on end position of SalesList by user*/
void AutoaddSaleToSalesList(SalesList** DB,OrderLine* OrderList,Client* client){
    /*get today details */
    Date* date=getTodayDate();
    printf("\n%d\n",date->annee);
    /* create new memory block using malloc function. */
    SalesList *temp=NULL,*new_Vente=(SalesList*)malloc(sizeof(SalesList));
    int codeVente=1;

    if(*DB==NULL){
      /*When SalesList is empty. Insert first Sale*/
      new_Vente->vente=createSale(codeVente,date,OrderList,client);
      new_Vente->vente->totale=calculeTotale(*DB,client);
      new_Vente->next=NULL;
      printf("\nI'm in autoaddsale Salelist is empty, Sale will have the code %d\n",codeVente);
      *DB=new_Vente;
    }
    else{
      /*When Sales list is not empty*/

      /*This will loop find last Sale in SalesList and its code*/
      for(temp=*DB, codeVente=0;temp!=NULL;temp=temp->next,codeVente++)
      codeVente++;
      /*assign this newly created Sale on end of DB*/
      printf("\nI'm in autoaddsale Salelist is not empty, Sale will have the code %d\n",codeVente);
      new_Vente->vente=createSale(codeVente,date,OrderList,client);
      new_Vente->vente->totale=calculeTotale(*DB,client);
      new_Vente->next=NULL;
      temp->next=new_Vente;
    }
}

/* Help of this function showing all element of single Sale list*/
void displaySales(SalesList *temp){
    printf("\n==================================================================");
	printf("\n\n=====================\tTHE SALES LIST \t==========================");
	printf("\n\n==================================================================\n\n");
  if(temp==NULL){
    /*Vente list are empty*/
    printf("Empty linked Sale List\n");
  }
  else
  {
    /*When DB are not empty*/
    while(temp)
    {
      /*print Sale */
      displaySale(temp->vente);
      /*move next memory block*/
      temp=temp->next;
    }

  }
  printf("\n\n==================================================================\n\n");
}

/* Get a Sale from the data base */
Vente *getSales(SalesList* temp,int codeVente){

  if(temp==NULL){
    /*Sale list are empty*/
    printf("Empty Vente List\n");
  }
  else
  {
    while(temp){
      /*If search Sale exist*/
      if(temp->vente->codeVente==codeVente){
        /*Sale exist*/
        return temp->vente;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Sale doesn't exist*/
    printf("\n Given Sale code [%d] is note exist",codeVente);
  }
  return temp->vente;
}

/* modify a Sale in the list */
void modifySales(SalesList** DB,int codeVente,Date* date,OrderLine* OrderLine ,Client* client){
  if(DB==NULL){
    /*Sales list is empty*/
    printf("Sales list is empty\n");
  }
  else
  {
    SalesList *temp=(*DB);
    while(temp){
      /*If search Sale exist*/
      if(temp->vente->codeVente == codeVente){
        /*Sale exist*/
        temp->vente=createSale(codeVente,date,OrderLine,client);
        temp->vente->totale=calculeTotale(*DB,client);
        return;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Sale doesn't exist*/
    printf("\n Given Sale code %d is note exist to modify",codeVente);

  }
}

 /*help of this function is to delete a Sale from the linked list in any position */
void deleteSale(SalesList** DB,int codeVente){

  if(*DB!=NULL){
    int status=0;
    SalesList *helper=*DB,*temp=*DB;

    /*If the Sale Element is the First element in DB*/
    if((*DB)->vente->codeVente==codeVente){

      *DB=helper->next;
      helper->next=NULL;

      /*Free linked list */
      free(helper);
      helper=NULL;

    }else{

      /*Find Sale to delete*/
      while(temp){

        if(temp->vente->codeVente==codeVente){
          /*Sale is exist*/
            status=1;
          break;
        }
        helper=temp;
        /*Point next memory block*/
        temp=temp->next;
      }
      if(status==1){

        helper->next=temp->next;

        /*Free SalesList*/
        free(temp);
        temp=NULL;
      }else{
        printf("\n Vente with code =%d doesn't exist",codeVente);
      }
    }


  }
  else{
    printf("\n Empty Linked list");
  }
}

/*Help of this function removing all Sales list element.*/
void deleteAllSales(SalesList** DB){

  if(*DB){

    SalesList* temp=*DB;

    while(temp){

      /*Moving SalesList pointer to on next memory block.*/
      *DB=temp->next;

      /*before removing that  Sales SalesList linked list assign
       that next pointer are null.*/
      temp->next=NULL;

      /*Free Sales SalesList element*/
      free(temp);

      temp=*DB;
    }
    printf("\n\nFree SalesList of Sales \n");
  }
  else{
    /* When DB is empty */
    printf("\n Sale list is empty \n");
  }

}

double calculeTotale(SalesList *DB,Client* client){
    SalesList* pt;
    int OrderCode,ClientOrdercode;
    double totale=0;
    for(pt=DB;pt!=NULL;pt=pt->next)
    {
        OrderCode = pt->vente->OrderList->Order->codeOrder;
        ClientOrdercode = (client->codeClient)*100;
        if ( OrderCode == ClientOrdercode )
        {
            totale+=pt->vente->OrderList->Order->subTotale;
        }
    }
    return totale;
}

int dateValide(int dd,int mm, int yy){
    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)) return 1;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)) return 1;
            else if((dd>=1 && dd<=28) && (mm==2)) return 1;
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))) return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

Date* getTodayDate()
{
    Date* date=(Date*)malloc(sizeof(Date));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    date->jour = tm.tm_mday;
    date->mois = (tm.tm_mon + 1);
    date->annee= (tm.tm_year + 1900);

    return date;
}

int saleIsExist(SalesList*temp,int codeVente){

  if(temp==NULL){
    /*SalesList is empty*/
    return 0;
  }
  else
  {
    while(temp){
      /*If search sale exist*/
      if(temp->vente->codeVente==codeVente){
        /*sale exist*/
        return 1;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Sale not exist*/
    return 0;

  }
}

