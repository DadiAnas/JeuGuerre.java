#include "payment.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*****************************************************************************************************************************/
/************************************************* Payment  Functions  *******************************************************/
/*****************************************************************************************************************************/

/*Help of this function is to create new Payment */

Payment* createPayment(int codePayment,double amount,char* type,Date* date,Vente* sale){
  Payment *new_Payment=(Payment*)malloc(sizeof(Payment));
  /* check new create memory are allocate or not. */
  if(new_Payment)
  {
      /*Assign data to newly created PaymentElement.*/
    new_Payment->codePayment=codePayment;
    new_Payment->type=(char*)malloc(sizeof(char)*25);
    new_Payment->type=type;
    new_Payment->amount=amount;
    new_Payment->date=(Date *)malloc(sizeof(Date));
    new_Payment->date= date;
    new_Payment->sale=sale;

    return new_Payment;
  }
    else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
    return NULL;
  }
}

 /* Help of this function is to display Payment data */
void displayPayment(Payment *temp){
    /*print Payment list */
      printf("code: %d  ",temp->codePayment);
      printf("amount: %.2lf  ",temp->amount);
      printf("type: %s ",temp->type);
      printf("date: %d/%d/%d \n",temp->date->jour,temp->date->mois,temp->date->annee);
}


/*help of this function is to insert the given Payment on end position of PaymentElement linked list*/
void addPaymentToList(PaymentElement**Paymentlist,int codePayment,double amount,char* type,Date* date,Vente* sale){

    /* create new memory block using malloc function. */
    PaymentElement*temp=NULL,*new_PaymentElement=(PaymentElement*)malloc(sizeof(PaymentElement));
    new_PaymentElement->Payment=createPayment(codePayment,amount,type,date,sale);
    new_PaymentElement->next=NULL;

    if(*Paymentlist==NULL){
      /*When Payment list are empty. Insert first PaymentElement*/
      *Paymentlist=new_PaymentElement;
    }
    else{
      /*When Payment list are not empty*/

      /*Payment list first PaymentElement address assign on temp pointer*/
      temp=*Paymentlist;

      /*This will loop find last PaymentElement of exist linked Payment list*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;
      }

      /*assign this newly created PaymentElement on end of list*/
      temp->next=new_PaymentElement;

    }
}

/* modify a Payment in the list */
void modifyPayment(PaymentElement** PaymentList,int paymentCode,double amount, char*type, Date* date,Vente* sale){
  if(PaymentList==NULL){
    /*Payment list are empty*/
    printf("Payment list are empty\n");
  }
  else
  {
    PaymentElement *temp=(*PaymentList);
    while(temp){
      /*If search Payment exist*/
      if(temp->Payment->codePayment==paymentCode){
        /*Payment exist*/
        temp->Payment=createPayment(paymentCode,amount,type,date,sale);
        return;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Payment not exist*/
    printf("\n Given Payment code %d are note exist to modify",paymentCode);
    return NULL;
  }
}


/* Help of this function showing all element of single Payment list*/
void displayPaymentsList(PaymentElement*temp){
    printf("\n==================================================================");
	printf("\n\n======================\t PaymentS LIST \t==========================");
	printf("\n\n==================================================================\n\n");
  if(temp==NULL){
    /*Payment list are empty*/
    printf("Empty linked Payment List\n");
  }
  else
  {
    /*When Payment list are not empty*/
    while(temp)
    {
      /*print Payment list Payment*/
      displayPayment(temp->Payment);
      /*move next memory block*/
      temp=temp->next;
    }

  }
  printf("\n\n==================================================================\n\n");
}

/* Get a Payment from the linked list PaymentElement*/
Payment *getPayment(PaymentElement*temp,int find_Payment){

  if(temp==NULL){
    /*Payment list are empty*/
    printf("Empty Payment List\n");
  }
  else
  {
    while(temp){
      /*If search Payment exist*/
      if(temp->Payment->codePayment==find_Payment){
        /*Payment exist*/
        return temp->Payment;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Payment not exist*/
    printf("\n Given Payment code [%d] are note exist",find_Payment);
    return NULL;
    }
}
 /*help of this function is to delete a Payment from the linked list in any position */
void deletePayment(PaymentElement** Paymentlist,int paymentCode){

  if(*Paymentlist!=NULL){
    int status=0;
    PaymentElement *helper=*Paymentlist,*temp=*Paymentlist;

    /*If the Payment in the first position*/
    if((*Paymentlist)->Payment->codePayment==paymentCode){

      *Paymentlist=helper->next;
      helper->next=NULL;

      /*Free linked list Payment*/
      free(helper);
      helper=NULL;

    }else{

      /*Find Payment in the linked list*/
      while(temp){

        if(temp->Payment->codePayment==paymentCode){
          /*Delete Payment are exist*/
            status=1;
          break;
        }
        helper=temp;
        /*Point next memory block*/
        temp=temp->next;
      }
      if(status==1){

        helper->next=temp->next;

        /*Free linked list Payment*/
        free(temp);
        temp=NULL;
      }else{
        printf("\n Delete Payment with code =%d Not exist",paymentCode);
      }
    }


  }
  else{
    printf("\n Empty Linked list");
  }
}

/*Help of this function removing all Payment list element.*/
void deleteAllPayment(PaymentElement**Paymentlist){

  if(*Paymentlist){

    PaymentElement*temp=*Paymentlist;

    while(temp){

      /*Moving Paymentlist pointer to on next memory block.*/
      *Paymentlist=temp->next;

      /*before removing that linked PaymentElement assign
       next pointer codePayment are null.*/
      temp->next=NULL;

      /*Free Payment listPaymentElement element*/
      free(temp);

      temp=*Paymentlist;
    }
    printf("\n\nFree PaymentElements list of Payments \n");
  }
  else{
    /* When Payment list is empty */
    printf("\n Payment list is empty \n");
  }

}

int PaymentIsExist(PaymentElement*temp,int codePayment){

  if(temp==NULL){
    /*Payments List is empty*/
    return 0;
  }
  else
  {
    while(temp){
      /*If search Payment exist*/
      if(temp->Payment->codePayment==codePayment){
        /*sale exist*/
        return 1;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Payment not exist*/
    return 0;

  }
}

