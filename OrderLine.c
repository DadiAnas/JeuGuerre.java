#include <stdio.h>
#include <stdlib.h>
#include "orderline.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/***************************************************************************************************************************************/
/************************************************* Order Management Functions  *********************************************************/
/***************************************************************************************************************************************/

/*Help of this function is to create new Order */

Order* createOrder(int codeOrder,int quantite,Product* product){
  Order *new_Order=(Order*)malloc(sizeof(Order));
  /* check new create memory are allocate or not. */
  if(new_Order)
  {
      /*Assign data to newly created OrderLine.*/
  	new_Order->codeOrder=codeOrder;
    new_Order->quantite=quantite;
    new_Order->product=(Product*)malloc(sizeof(Product));
    new_Order->product=product;
    new_Order->subTotale = quantite * product->price;

    return new_Order;
  }
    else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
  }
  return new_Order;
}

 /* Help of this function is to display Order data */
void displayOrder(Order *temp){
    /*print Order list */
      printf("product code: %d designation: %s price: %.2lf ",temp->product->codeProduct,temp->product->designation,temp->product->price);
      printf("quantite: %d  ",temp->quantite);
      printf("subTotale: %.2lf  \n",temp->subTotale);

}


/*help of this function is to insert the given Order on end position of OrderLine linked list*/
void addOrderToList(OrderLine**Orderlist,int codeOrder,int quantite,Product* product){

    /* create new memory block using malloc function. */
    OrderLine*temp=NULL,*new_OrderLine=(OrderLine*)malloc(sizeof(OrderLine));
    new_OrderLine->Order=createOrder(codeOrder*100,quantite,product); // the code order is multiplied by 100 to get difference between customer order
    new_OrderLine->next=NULL;

    if(*Orderlist==NULL){
      /*When Order list are empty. Insert first OrderLine*/
      *Orderlist=new_OrderLine;
    }
    else{
      /*When Order list are not empty*/

      /*Order list first OrderLine address assign on temp pointer*/
      temp=*Orderlist;

      /*This will loop find last OrderLine of exist linked Order list*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;
      }

      /*assign this newly created OrderLine on end of list*/
      temp->next=new_OrderLine;

    }
}

/* modify an Order in the list */
void modifyOrder(OrderLine** OrderList,int codeOrder, int new_quantite,Product* new_product){
    if(OrderList==NULL){
    /*Order list is empty*/
    printf("Order list are empty\n");
  }
  else
  {
    OrderLine *temp=(*OrderList);
    while(temp){
      /*If search Order exist*/
      if(temp->Order->codeOrder == codeOrder){
        /*Order exist*/
        temp->Order=createOrder(codeOrder,new_quantite,new_product);
        return;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Order not exist*/
    printf("\n Given Order code %d is note exist to modify",codeOrder);

  }
}


/* Help of this function showing all element of single Order list*/
void displayOrdersList(OrderLine*temp,Client* client){
    printf("\n==================================================================");
	printf("\n\n=================\tYOUR ORDERS\t==================");
	printf("\n\n==================================================================\n\n");
  if(temp==NULL){
    /*Order list are empty*/
    printf("Empty Order list\n");
  }
  else
  {
    /*When Order list are not empty*/
    while(temp)
    {
        if(temp->Order->codeOrder==10*client->codeClient)
        {
            /*print Order list Order*/
            displayOrder(temp->Order);
            /*move next memory block*/
            temp=temp->next;
        }
        else temp=temp->next;
    }

  }
  printf("\n\n==================================================================\n\n");
}

/* Get an Order from the linked list OrderLine*/
Order *getOrder(OrderLine*temp,int codeOrder){

  if(temp==NULL){
    /*Order list are empty*/
    printf("Empty Order list\n");
  }
  else
  {
    while(temp){
      /*If search Order exist*/
      if(temp->Order->codeOrder == codeOrder){
        /*Order exist*/
        return temp->Order;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Order not exist*/
    printf("\n Given Order code [%d] are note exist",codeOrder);
    return temp->Order;

  }
}
 /*help of this function is to delete an order from the linked list in any position */
void deleteOrder(OrderLine** Orderlist,int codeOrder){

  if(*Orderlist!=NULL){
    int status=0;
    OrderLine *helper=*Orderlist,*temp=*Orderlist;

    /*If the order in the first position*/
    if((*Orderlist)->Order->codeOrder == codeOrder){

      *Orderlist=helper->next;
      helper->next=NULL;

      /*Free linked list Order*/
      free(helper);
      helper=NULL;

    }else{

      /*Find order in the linked list*/
      while(temp){

        if(temp->Order->codeOrder==codeOrder){
          /* order are exist*/
            status=1;
            break;
        }
        helper=temp;
        /*Point next memory block*/
        temp=temp->next;
      }
      if(status==1){

        helper->next=temp->next;

        /*Free order linked list */
        free(temp);
        temp=NULL;
      }else{
        printf("\n Delete Order with code =%d Not exist",codeOrder);
      }
    }


  }
  else{
    printf("\n Empty Linked list");
  }
}

/*Help of this function removing all Order list element.*/
void deleteAllOrder(OrderLine** Orderlist){

  if(*Orderlist){

    OrderLine*temp=*Orderlist;

    while(temp){

      /*Moving Orderlist pointer to on next memory block.*/
      *Orderlist=temp->next;

      /*before removing that linked OrderLine assign
       next pointer quantite are null.*/
      temp->next=NULL;

      /*Free Order list OrderLine element*/
      free(temp);

      temp=*Orderlist;
    }
    printf("\n\nFree OrderLines list of Orders \n");
  }
  else{
    /* When Order list is empty */
    printf("\n Order list is empty \n");
  }

}

