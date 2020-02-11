#include "sales.h"
//#include "menu.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Structeres section here      ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/***************************************************************************************************************************************/
/************************************************* Payment Management Structures *******************************************************/
/***************************************************************************************************************************************/

typedef struct{ //un paiement
    int codePayment;
    double amount;
    char *type ;
    Date *date;
    Vente *sale ; //apartient à une vente
}Payment;

typedef struct PaymentElement{ //une liste chainée de paiements
    Payment *Payment;
    struct PaymentElement *next;
} PaymentElement ;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Functions declaration section here       -----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*****************************************************************************************************************************************/
/**************************************************** Payment Functions declaration *********************************************************/
/*****************************************************************************************************************************************/



//Functions to Manipulate Payments
Payment* createPayment(int,double,char*,Date*,Vente*);
void displayPayment(Payment *);
//Functions to Manipulate Payments list
void modifyPayment(PaymentElement**, int, double,char*,Date*,Vente*);
void addPaymentToList(PaymentElement**,int,double,char*,Date*,Vente*);
int PaymentIsExist(PaymentElement*,int);
void displayPaymentsList(PaymentElement*);
Payment *getPayment(PaymentElement *, int);
void deletePayment (PaymentElement **, int);
void deleteAllPayment(PaymentElement**);
int PaymentIsExist(PaymentElement*,int);
void savePaymentsData(PaymentElement*);
