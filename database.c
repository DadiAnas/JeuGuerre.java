#include "database.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/****************************************************************************************************************************/
/********************************************* DataBase  Functions  *********************************************************/
/****************************************************************************************************************************/

/* ****************************************  Import data from files  ********************************************************/
// import customers data from customersDB
void importCustomersData(ClientElement** CustomersList)
{
    FILE *fCustomers=fopen("customersDB","r");
    if(fCustomers)
    {
        int code;
        char* nom=(char*)malloc(25);
        char* prenom=(char*)malloc(25);
        char* telephone=(char*)malloc(25);
        while(fscanf(fCustomers,"%d %s %s %s",&code,nom,prenom,telephone) != EOF)
        {
            addClientToList(CustomersList,code,nom,prenom,telephone);
        }
        fclose(fCustomers);
    }
}

void importProductData(ProductElement** ProductList)
{
    FILE *fproducts=fopen("productsDB","r");
    if(fproducts)
    {
        int code;
        double price;
        char* designation=(char*)malloc(25);
        while(fscanf(fproducts,"%d %s %lf",&code,designation,&price) != EOF)
        {
            addProductToList(ProductList,code,designation,price);
        }
        fclose(fproducts);
    }
}
void importSalesData(SalesList** SaleList,OrderLine* OrderList,ClientElement* ClientList)
{
    FILE *fsales=fopen("salesDB","r");
    if(fsales)
    {
        int code,clientCode,day,month,year;
        Date* date=(Date*)malloc(sizeof(Date));
        Client* client=(Client*)malloc(sizeof(Client));
        while(fscanf(fsales,"%d %d %d %d %d",&code,&day,&month,&year,&clientCode) != EOF)
        {
            (date->jour)=day;
            (date->mois)=month;
            (date->annee)=year;
            client=getClient(ClientList,clientCode);
            addSaleToSalesList(SaleList,code,date,OrderList,client);
        }
        fclose(fsales);
    }
}

void importOrdersData(OrderLine** OrderList,ProductElement* ProductList)
{
    FILE *forder=fopen("orderDB","r");
    if(forder)
    {
        int code,qte,productCode;
        double subtotal;
        Product* product=(Product*)malloc(sizeof(Product));
        while(fscanf(forder,"%d %d %lf %d",&code,&qte,&subtotal,&productCode) != EOF)
        {
            product=getProduct(ProductList,productCode);
            addOrderToList(OrderList,code,qte,product);
        }
        fclose(forder);
    }
}
// save data in database file
void saveProductsData(ProductElement* productList)
{
    FILE *f=fopen("productsDB","w");
    ProductElement *ptr;
    if(f==NULL) printf("Error opening products database\n");
    else  if(productList != NULL)
    {
        for(ptr=productList;ptr!=NULL;ptr=ptr->next)
        {
            fprintf(f,"%d %s %lf\n",ptr->product->codeProduct,ptr->product->designation,ptr->product->price);
        }
    }
    fclose(f);
    printf("The product data has been saved\n");
}

void importAllData(ProductElement** ProductList,ClientElement** CustomerList,OrderLine** OrderList,SalesList** SalesList,PaymentElement** PaymentList)
{
    importProductData(ProductList);
    importCustomersData(CustomerList);
    importOrdersData(OrderList,*ProductList);
    importSalesData(SalesList,*OrderList,*CustomerList);
}

// save data in customersDB file

void saveCustomersData(ClientElement* customerList)
{
    FILE *f=fopen("customersDB","w");
    ClientElement *ptr;
    if(f==NULL) printf("Error opening customers database\n");
    else  if(customerList != NULL)
    {
        for(ptr=customerList;ptr!=NULL;ptr=ptr->next)
        {
            fprintf(f,"%d %s %s %s \n",ptr->client->codeClient,ptr->client->nom,ptr->client->prenom,ptr->client->telephone);
        }
    }
    fclose(f);
    printf("The customer data has been saved\n");
}

// save data in salesDB file

void saveSalesData(SalesList* SaleList)
{
    FILE *fsale=fopen("salesDB","w");
    SalesList *ptr;
    if(fsale==NULL) printf("Error opening sales database\n");
    else  if(SaleList != NULL)
    {
        for(ptr=SaleList;ptr!=NULL;ptr=ptr->next)
        {
            fprintf(fsale,"%d %d %d %d %d\n",ptr->vente->codeVente,ptr->vente->date->jour,ptr->vente->date->mois,ptr->vente->date->annee,ptr->vente->client->codeClient);
        }
    }
    fclose(fsale);
    printf("The sales data has been saved\n");
}

// save data in orderlineDB file
void saveOrdersData(OrderLine* orderList)
{
    FILE *forder=fopen("orderlineDB","w");
    OrderLine *ptr;
    if(forder==NULL) printf("Error opening orderline database\n");
    else  if(orderList != NULL)
    {
        for(ptr=orderList;ptr!=NULL;ptr=ptr->next)
        {
            fprintf(forder,"%d %d %lf %d\n",ptr->Order->codeOrder,ptr->Order->quantite,ptr->Order->subTotale,ptr->Order->product->codeProduct);
        }
    }
    fclose(forder);
    printf("The product data has been saved\n");
}

void freeMemory(ClientElement* ClientList,OrderLine* OrderList,ProductElement* ProductList,SalesList* SalesList,PaymentElement* PaymentList)
{
    deleteAllClient(&ClientList);
    deleteAllOrder(&OrderList);
    deleteAllProduct(&ProductList);
    deleteAllSales(&SalesList);
}
