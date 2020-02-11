#include "database.h"


int main(){

   ProductElement* ProductList=NULL;
   ClientElement* ClientList=NULL;
 	OrderLine* OrderList=NULL;
 	SalesList* SalesList=NULL;
   PaymentElement* PaymentList=NULL;

   /* import data from files if exist*/
   importAllData(&ProductList,&ClientList,&OrderList,&SalesList,&PaymentList);
   /* Menu */
   menu(ProductList,ClientList,OrderList,SalesList);
 	/* Free memory */
    freeMemory(ClientList,OrderList,ProductList,SalesList,PaymentList);
    return 0;
}



