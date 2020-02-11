#include "orderline.h"

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Structeres section here      ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/***************************************************************************************************************************************/
/*********************************************** Sales  Management Structures **********************************************************/
/***************************************************************************************************************************************/

/* Date Structere */
typedef struct{
    int jour; /* Day */
    int mois; /* Month */
    int annee; /* Year */
}Date;


/* Sale structure */
typedef struct{
    int codeVente; /* Sale Code */
    double totale; /* Sales total */
    Date *date; /* date JJ/MM/YYYY */
    OrderLine *OrderList; /* Linked list of orders */
    Client *client; /* belongs to one customer */
}Vente;

typedef struct SalesList
{
	Vente *vente;
	struct SalesList *next;

}SalesList;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Functions declaration section here       -----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/***************************************************************************************************************************************/
/************************************************* Sale Management Functions declaration ***********************************************/
/***************************************************************************************************************************************/

//Functions to Manipulate Sales
Vente* createSale(int,Date*,OrderLine*, Client*);
void displaySale(Vente *);
//Functions to Manipulate Sales list
double calculeTotale(SalesList *,Client*);
void modifySales(SalesList**, int,Date*,OrderLine*, Client*);
int saleIsExist(SalesList*,int );
void addSaleToSalesList(SalesList**,int,Date*,OrderLine*, Client*);
void AutoaddSaleToSalesList(SalesList** DB,OrderLine* OrderList,Client* client);
void displaySales(SalesList*);
Vente *getSales(SalesList *, int);
void deleteSale (SalesList **, int);
void deleteAllSales(SalesList**);
int dateValide(int,int,int);
Date* getTodayDate();
