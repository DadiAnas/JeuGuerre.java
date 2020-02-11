#include "menu.h"
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------     Functions declaration section here       -----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*****************************************************************************************************************************************/
/****************************************************  Functions declaration *********************************************************/
/*****************************************************************************************************************************************/

int cfileexists(const char * );
void saveProductsData(ProductElement*);
void importProductData(ProductElement**);
void saveCustomersData(ClientElement* );
void importCustomersData(ClientElement** );
void saveSalesData(SalesList* );
void importSalesData(SalesList** ,OrderLine* ,ClientElement* );
void saveOrdersData(OrderLine* orderList);
void importOrdersData(OrderLine**,ProductElement*);
void importAllData(ProductElement**,ClientElement**,OrderLine**,SalesList**,PaymentElement**);
void freeMemory(ClientElement*,OrderLine*,ProductElement*,SalesList*,PaymentElement*);



