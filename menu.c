#include "database.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*****************************************************************************************************************************************/
/****************************************************** Menu Functions  ******************************************************************/
/*****************************************************************************************************************************************/

void menu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList){

    char pass[10],pass2[10];
    int j,p,p1;
    system("color E");
    storemenu:
    p=p1=3;
    system("cls");
    system("color E");
    printf("\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO DADI STORE MANAGEMENT ============|");
    getchar();
    system("cls");
    printf("\n\t\t   DADI  STORE MANAGEMENT SYSTEM\n");
    printf("=============================================================");
    printf("\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu \n\n\t\t   4. Exit");
    printf("\n\n=============================================================\n");
    printf("\n\nEnter Your Choice:");
    scanf("%d",&j);
    getchar();
	if(j==1)
	{
    	/* Password Section */
    	dealerpass:
		system("cls");
    	printf("\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ");
    	gets(pass);
		if(strcmp(pass,"dadi")==0 && p>=0)
		{ /* the password is correct */
		    system("cls");
		    system("color A");
		    printf("\n\n\n\n\n\n\n\t\t\t\t\tCongrats!!Access Granted!!");
    		getchar();
    		system("cls");

    		/* Dealer Menu */
    		system("color E");
    		dealerMenu(ProductList,ClientList,OrderList,SalesList);

		}
    	else if(p>0)
    	{ /* Password isn't correct */
    	    system("color C");
    	    MessageBeep(-1);
        	printf("\n\nSorry!! Please Provide Valid Password...\nYou have %d attempts remaining\n",p--);
            getchar();
            goto dealerpass;
    	}
    	else goto storemenu;
	}
	if(j==2)
	{
	    system("color E");
        liveCustMenu(ProductList,ClientList,OrderList,SalesList);
	}
	if(j==3)
    {
        dealerpass1:
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ");
		gets(pass2);
		if(strcmp(pass2,"dadi")==0 && p1>=0)
		{ /* Employee menu */
		    system("cls");
		    system("color A");
		    printf("\n\n\n\n\n\n\n\t\t\t\t\tCongrats!!Access Granted!!");
    		getchar();
    		system("color E");
    		system("cls");
			employeeMenu(ProductList,ClientList,OrderList,SalesList);
        }
        else if(p1>0)
        {
            system("color C");
            MessageBeep(-1);
        	printf("\n\nSorry!! Please Provide Valid Password...\nYou have %d attempts remaining\n",p1--);
            getchar();
            goto dealerpass1;
        }
        else goto storemenu;
	}
	else if(j==4) Exit();
	else
	{
    	goto storemenu;
	}
	getchar();
}


void dealerMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList)
{
    int i;
        dealermenu: /* dealer menu */
      		system("cls");
        	printf("=================================================================");
        	printf("\n\n\t\t\t    DEALER MENU\n1. Manage Products\n2. Manage Customers\n3. Manage Sales\n4. Return to store menu\n5. Exit");
        	printf("\n\n\n==========================END OF MENU=============================");
        	printf("\n\n Enter your Choice :\t");
        	scanf("%d",&i);
    		if(i==1)
    		{ /* product menu */

        		productMenu(ProductList,ClientList,OrderList,SalesList);
    		}
    		else if (i==2)
    		{ /*Customers Menu */
        		customersMenu(ProductList,ClientList,OrderList,SalesList);
    		}
    		else if (i==3)
    		{   /*sales menu*/
        		salesMenu(ProductList,ClientList,OrderList,SalesList);
        	}
    		else if (i==5) Exit();
     		else if(i==4) menu(ProductList,ClientList,OrderList,SalesList);
    		else
    		{
        		goto dealermenu;
        	}
}

void productMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList)
{
    int i;
    productmenu:
        		system("cls");
        		printf("=================================================================");
        		printf("\n\n\t\t\t    PRODUCT MENU\n1. Add new product\n2. Display stock\n3. Modify Products\n4. Remove an item\n5. Return to dealer menu\n6. Exit:");
        		printf("\n\n\n==========================END OF MENU=============================");
        		printf("\n\n Enter your Choice :\t");
        		scanf("%d",&i);
        		if(i==1) // Add new product
        		{

            		int code;
            		char* Design=(char *)malloc(sizeof(char)*40);
            		double price;
            		newprod:
            		system("cls");
            		displayProductsList(ProductList);
            		printf("Enter the product code:");
            		scanf("%d",&code);
            		getchar();
            		if (productIsExist(ProductList,code))
                    {
                        codeexist:
                        printf("\n\nChosen code already exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                        scanf("%d",&i);
                        if(i==1) goto newprod;
                        else if( i==2 ) goto productmenu;
                        else goto codeexist;
                    }
                    else
                    {
                        printf("Enter the product designation:");
                        gets(Design);
                        printf("Enter the product price:");
                        scanf("%lf",&price);
                        addProductToList(&ProductList,code,Design,price);
                        saveProductsData(ProductList);
                        getchar();
                        goto productmenu;
                    }

        		}

        		else if(i==2) //Display stock
        		{
            		system("cls");
            		displayProductsList(ProductList);
            		getchar();
            		getchar();
            		goto productmenu;
        		}
        		else if(i==3) // Modify Products
        		{

            		int code;
            		Product *product;
            		char* Design=(char *)malloc(sizeof(char)*40);
            		double price;
            		modifprod:
            		system("cls");
            		displayProductsList(ProductList);
            		printf("Enter the code of product you want to modify:");
            		scanf("%d",&code);
            		getchar();
            		if (!productIsExist(ProductList,code))
                    {
                        codenotexist:
                        printf("\n\nChosen code not exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                        scanf("%d",&i);
                        if(i==1) goto modifprod;
                        else if( i==2 ) goto productmenu;
                        else goto codenotexist;
                    }
                    else
                    {
                    modifprod1:
            		product=getProduct(ProductList,code);
            		printf("Enter the new code :");
            		scanf("%d",&code);
            		if (productIsExist(ProductList,code) && code!=product->codeProduct)
                    {
                        codeexist1:
                        printf("\n\nChosen code already exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                        scanf("%d",&i);
                        if(i==1) goto modifprod1;
                        else if( i==2 ) goto productmenu;
                        else goto codeexist1;
                    }
                    else
                    {
            		product->codeProduct = code;
            		getchar();
            		printf("Enter the new designation:");
            		gets(Design);
            		printf("Enter the new price:");
            		scanf("%lf",&price);
            		modifyProduct(&ProductList,code,Design,price);
            		saveProductsData(ProductList);
            		goto productmenu;
                    }
                    }
        		}
        		else if(i==4) // remove an item
        		{
        		    system("cls");
            		int code;
            		displayProductsList(ProductList);
            		printf("Enter the code of product you want to remove:");
            		scanf("%d",&code);
            		deleteProduct(&ProductList,code);
            		saveProductsData(ProductList);
            		getchar();
            		goto productmenu;
        		}
        		else if(i==5) dealerMenu(ProductList,ClientList,OrderList,SalesList);
        		else if(i==6) Exit();//exit
                else goto productmenu;
}

void customersMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList)
{
    int i;
    customermenu: /*Customers menu*/
        		system("cls");
     		    printf("=================================================================");
        		printf("\n\n\t\t\t    CLIENT MENU\n1. Add new client\n2. Display customers list\n3. Modify Client\n4. Remove a Client\n5. Return to dealer menu\n6. Exit:");
        		printf("\n\n\n==========================END OF MENU=============================");
        		printf("\n\n Enter your Choice :\t");
        		scanf("%d",&i);
        		getchar();
        		if(i==1) // Add customer
        		{

                        int code;
                        char* nom=(char *)malloc(sizeof(char)*20);
                        char* prenom=(char *)malloc(sizeof(char)*20);
                        char* telephone=(char *)malloc(sizeof(char)*20);
                        newcust:
                        system("cls");
                        displayClientsList(ClientList);
                        printf("Enter the client code:");
                        scanf("%d",&code);
                        getchar();
                        if (customerIsExist(ClientList,code))
                        {
                            codeexist:
                            printf("\n\nChosen code already exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                            scanf("%d",&i);
                            getchar();
                            if(i==1) goto newcust;
                            else if( i==2 ) goto customermenu;
                            else goto codeexist;
                        }
                        else
                        {
                        printf("Enter the first name:");
                        gets(nom);
                        printf("Enter the last name:");
                        gets(prenom);
                        printf("Enter the phone number:");
                        gets(telephone);
                        addClientToList(&ClientList,code,nom,prenom,telephone);
                        saveCustomersData(ClientList);
                        goto display;
                        }
        		}
        		else if(i==2) //Display Customers list
        		{
        		    display:
        		    system("cls");
        		    displayClientsList(ClientList);
        		    getchar();
            		goto customermenu;
        		}
        		else if(i==3) // Modify customers
        		{

            		int code;
            		Client *client;
            		char* nom=(char *)malloc(sizeof(char)*20);
            		char* prenom=(char *)malloc(sizeof(char)*20);
            		char* telephone=(char *)malloc(sizeof(char)*20);
                    system("cls");
            		displayClientsList(ClientList);
            		printf("Enter the code of client you want to modify:");
            		scanf("%d",&code);
            		getchar();
            		client=getClient(ClientList,code);
            		modifcust:
            		printf("Enter the new code :");
            		scanf("%d",&code);
            		getchar();
            		if (customerIsExist(ClientList,code) && code!=client->codeClient)
                    {
                        codeexist1:
                        printf("\n\nChosen code already exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                        scanf("%d",&i);
                        getchar();
                        if(i==1) goto modifcust;
                        else if( i==2 ) goto customermenu;
                        else goto codeexist1;
                    }
                    else
                    {
            		client->codeClient = code;
            		printf("Enter the new first name:");
            		gets(nom);
           			printf("Enter the new last name:");
            		gets(prenom);
            		printf("Enter the new phone number:");
            		gets(telephone);
            		modifyClient(&ClientList,code,nom,prenom,telephone);
            		saveCustomersData(ClientList);
            		goto display;
            		}
        		}
        		else if(i==4) // remove a customer
        		{
            		system("cls");
            		int code;
            		displayClientsList(ClientList);
            		printf("Enter the code of client you want to remove:");
            		scanf("%d",&code);
            		getchar();
            		deleteClient(&ClientList,code);
            		saveCustomersData(ClientList);
            		goto customermenu;
        		}
        		else if(i==5) dealerMenu(ProductList,ClientList,OrderList,SalesList);
        		else if(i==6) Exit();// exit
        		else goto customermenu;
}

void salesMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SaleList)
{
    int i;
    salemenu: /*sales menu*/
        			system("cls");
        			printf("=================================================================");
               		printf("\n\n\t\t\t    SALES MENU\n1. Add new sale\n2. Display sales\n3. Modify sales\n4. Remove a sale\n5. Return to dealer menu \n6. Exit:");
                	printf("\n\n\n==========================END OF MENU=============================");
                	printf("\n\n Enter your Choice :\t");
        			scanf("%d",&i);
        			getchar();
        			if(i==1) // Add new sale
       				{
                        /* Declaration */
                        newsale:
                			system("cls");
                			int code,productCode,clientCode,quantite;
                			char ajouter;
                			Product* product;
                			Client *client;
                			Date* date=(Date *)malloc(sizeof(Date));
                		/* Display SalesList */
                			displaySales(SaleList);
                		/* get Information from dealer */
                			printf("Enter the sale code:");
                			scanf("%d",&code);
                			getchar();
                        if (saleIsExist(SaleList,code))
                        {
                            salesexist:
                            printf("\n\nChosen Sale already exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                            scanf("%d",&i);
                            getchar();
                            if(i==1) goto newsale;
                            else if( i==2 ) goto salemenu;
                            else goto salesexist;
                        }
                        else{ /* Sales is not exist */
                            enterdate:
                			printf("Enter the date(if today is 01/01/2019 enter 01 01 2019):");
                			scanf("%d %d %d",&date->jour,&date->mois,&date->annee);
                			getchar();
                			if (!dateValide(date->jour,date->mois,date->annee))
                            {
                                printf("\nDate invalid\n\n"); goto enterdate;
                            }
                            system("cls");
                			displayClientsList(ClientList);
                			printf("Enter the client code:");
                			scanf("%d",&clientCode);
                			getchar();
                			    system("cls");
                			    displayProductsList(ProductList);
                			    printf("Enter the product code:");
                    			scanf("%d",&productCode);
                    			product=getProduct(ProductList,productCode);
                    			printf("Enter the product amount:");
                    			scanf("%d",&quantite);
                    			getchar();
                    			printf("add the sale(Y/N):");
                    			ajouter=getchar();
                    			if(ajouter == 'Y' || ajouter == 'y')
                    			{
                    			    addOrderToList(&OrderList,clientCode,quantite,product);
                    			    client=getClient(ClientList,clientCode);
                        			addSaleToSalesList(&SaleList,code,date,OrderList,client);
                        			modifyOrder(&OrderList,clientCode,quantite,product);
                        			modifySales(&SaleList,code,date,OrderList,client);
                        			saveOrdersData(OrderList);
                        			saveSalesData(SaleList);
                        			printf("\nThe sale added with success!\n");
                        			getchar();
                        			goto salemenu;
                    			}
                    			else
                    			{
                    			    printf("\nYou didn't add the sale !\n\nPress Enter to return");
                        			getchar();
                        			goto salemenu;
                    			}
                        } /* End else of sale is not exist */
        			}
        			else if(i==2) // Display sales
        			{
            			system("cls");
            			displaySales(SaleList);
            			getchar();
            			goto salemenu;
        			}
        			else if(i==3) // modify sales
        			{
        			    /* Declaration */
                        modifsale:
                			system("cls");
                			int code,productCode,clientCode,quantite;
                			char Modify;
                			Product* product;
                			Client *client;
                			Date* date=(Date *)malloc(sizeof(Date));
                		/* Display SalesList */
                			displaySales(SaleList);
                		/* get Information from dealer */
                			printf("Enter the sale code:");
                			scanf("%d",&code);
                			getchar();
                        if (!saleIsExist(SaleList,code))
                        {
                            salesnotexist:
                            printf("\n\nChosen Sale doesn't exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
                            scanf("%d",&i);
                            getchar();
                            if(i==1) goto modifsale;
                            else if( i==2 ) goto salemenu;
                            else goto salesnotexist;
                        }
                        else{ /* Sales is exist */
                			getchar();
                			enternewdate:
                            system("cls");
                            displaySales(SaleList);
                			printf("Enter the new date (if today is 01/01/2019 enter 01 01 2019):");
                			scanf("%d %d %d",&date->jour,&date->mois,&date->annee);
                			getchar();
                			if (!dateValide(date->jour,date->mois,date->annee))
                            {
                                printf("\nDate invalid\n\n"); goto enternewdate;
                            }
                            system("cls");
                			displayClientsList(ClientList);
                			printf("Enter the new client code:");
                			scanf("%d",&clientCode);
                			getchar();
                			    system("cls");
                			    displayProductsList(ProductList);
                			    printf("Enter the new product code:");
                    			scanf("%d",&productCode);
                    			getchar();
                    			product=getProduct(ProductList,productCode);
                    			printf("Enter the new product amount:");
                    			scanf("%d",&quantite);
                    			getchar();
                    			printf("Modify the order(Y/N):");
                    			Modify=getchar();
                    			if(Modify == 'Y' || Modify == 'y')
                    			{
                    			    modifyOrder(&OrderList,clientCode,quantite,product);
                    			    client=getClient(ClientList,clientCode);
                        			modifySales(&SaleList,code,date,OrderList,client);
                        			saveOrdersData(OrderList);
                        			saveSalesData(SaleList);
                        			goto salemenu;
                    			}
                    			else
                    			{
                        			goto salemenu;
                    			}
                        } /* End else of sale is not exist */
        			}
        			else if(i==4) // remove a sale
        			{
            			system("cls");
            			int code;
            			displaySales(SaleList);
            			printf("Enter the code of sale you want to remove:");
           				scanf("%d",&code);
           				getchar();
            			deleteSale(&SaleList,code);
            			saveSalesData(SaleList);
            			goto salemenu;
        			}
        			else if(i==5) dealerMenu(ProductList,ClientList,OrderList,SaleList); // Return to dealer menu
        			else if(i==6) Exit();// exit
        			else goto salemenu; // wrong choice
}
//
//void PaymentMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList,PaymentElement* PaymentList)
//{
//    /* Declaration */
//    int i,newPurchase;
//    int code,amount,clientCode,productCode,quantite;
//    char *type=(char*)malloc(sizeof(25));
//    char ajouter;
//    Product* product;
//    Client *client;
//    Date* date=(Date *)malloc(sizeof(Date));
//    Vente *sale=(Vente*)malloc(sizeof(Vente));
//    Paymentmenu: /*Payments menu*/
//    			system("cls");
//       			printf("=================================================================");
//           		printf("\n\n\t\t\t    PAYMENT MENU\n1. Add new payment\n2. Display payments\n3. Modify payments\n4. Remove a payment\n5. Return to dealer menu \n6. Exit:");
//               	printf("\n\n\n==========================END OF MENU=============================");
//              	printf("\n\n Enter your Choice :\t");
//       			scanf("%d",&i);
//                getchar();
//       			if(i==1) // Add new Payment
//                {
//                    system("cls");
//                    displaySales(SalesList);
//                    printf("1.purchase a new sale\n2.Purchase an old sale");
//                    printf("\n\n Enter your Choice :\t");
//                    scanf("%d",&newPurchase);
//                    getchar();
//                    if(newPurchase==1) /* purchase a new sale */
//                    {
//
//                        newPayment:
//                			system("cls");
//                		/* Display PaymentsList */
//                			displayPaymentsList(PaymentList);
//                		/* get Information from dealer */
//                			printf("Enter the Payment code:");
//                			scanf("%d",&code);
//                            getchar();
//                        if (PaymentIsExist(PaymentList,code))
//                        {
//                            Paymentsexist:
//                            printf("\n\nChosen Payment already exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
//                            scanf("%d",&i);
//                            getchar();
//                            if(i==1) goto newPayment;
//                            else if( i==2 ) goto Paymentmenu;
//                            else goto Paymentsexist;
//                        }
//                        else{ /* Payments is not exist */
//
//                			enterdate:
//                			printf("Enter the date(if today is 01/01/2019 enter 01 01 2019):");
//                			scanf("%d %d %d",&date->jour,&date->mois,&date->annee);
//                			getchar();
//                			if (!dateValide(date->jour,date->mois,date->annee))
//                            {
//                                printf("\nDate invalid\n\n"); goto enterdate;
//                            }
//                            system("cls");
//                			displayClientsList(ClientList);
//                			printf("Enter the client code:");
//                			scanf("%d",&clientCode);
//                			getchar();
//                			    system("cls");
//                			    displayProductsList(ProductList);
//                			    printf("Enter the product code:");
//                    			scanf("%d",&productCode);
//                    			product=getProduct(ProductList,productCode);
//                    			printf("Enter the product amount:");
//                    			scanf("%d",&quantite);
//                    			getchar();
//                                printf("Enter type of payment:");
//                                gets(type);
//                    			printf("add the Payment(Y/N):");
//                    			ajouter=getchar();
//                    			if(ajouter == 'Y' || ajouter == 'y')
//                    			{
//                    			    addOrderToList(&OrderList,clientCode,quantite,product);
//                    			    client=getClient(ClientList,clientCode);
//                        			addPaymentToList(&PaymentList,code,amount,type,date,sale);
//                        			modifyOrder(&OrderList,clientCode,quantite,product);
//                        			modifyPayments(&PaymentList,code,date,OrderList,client);
//                        			savePaymentsData(PaymentList);
//                        			printf("\nThe Payment added with success!\n");
//                        			getchar();
//                        			getchar();
//                        			goto Paymentmenu;
//                    			}
//                    			else
//                    			{
//                    			    printf("\nYou didn't add the Payment !\n\nPress Enter to return");
//                        			getchar();
//                        			getchar();
//                        			goto Paymentmenu;
//                    			}
//                            } /* End else of Payment is not exist */
//                        }
//                        else if(newPurchase==2) /* Purchase an old sale */
//                        {
//
//                        }
//        			}
//        			else if(i==2) // Display Payments
//        			{
//            			system("cls");
//            			displayPayments(PaymentList);
//            			getchar();
//            			getchar();
//            			goto Paymentmenu;
//        			}
//        			else if(i==3) // modify Payments
//        			{
//        			    /* Declaration */
//                        modifPayment:
//                			system("cls");
//                			int code,productCode,clientCode,quantite;
//                			char Modify;
//                			Product* product;
//                			Client *client;
//                			Date* date=(Date *)malloc(sizeof(Date));
//                		/* Display PaymentsList */
//                			displayPayments(PaymentList);
//                		/* get Information from dealer */
//                			printf("Enter the Payment code:");
//                			scanf("%d",&code);
//                        if (!PaymentIsExist(PaymentList,code))
//                        {
//                            Paymentsnotexist:
//                            printf("\n\nChosen Payment doesn't exist!!\n\n1. Enter another code \n2. Go to previews menu\n\nEnter your choice:");
//                            scanf("%d",&i);
//                            if(i==1) goto modifPayment;
//                            else if( i==2 ) goto Paymentmenu;
//                            else goto Paymentsnotexist;
//                        }
//                        else{ /* Payments is exist */
//                			getchar();
//                			enternewdate:
//                            system("cls");
//                            displayPayments(PaymentList);
//                			printf("Enter the new date (if today is 01/01/2019 enter 01 01 2019):");
//                			scanf("%d %d %d",&date->jour,&date->mois,&date->annee);
//                			getchar();
//                			if (!dateValide(date->jour,date->mois,date->annee))
//                            {
//                                printf("\nDate invalid\n\n"); goto enternewdate;
//                            }
//                            system("cls");
//                			displayClientsList(ClientList);
//                			printf("Enter the new client code:");
//                			scanf("%d",&clientCode);
//                			getchar();
//                			    system("cls");
//                			    displayProductsList(ProductList);
//                			    printf("Enter the new product code:");
//                    			scanf("%d",&productCode);
//                    			product=getProduct(ProductList,productCode);
//                    			printf("Enter the new product amount:");
//                    			scanf("%d",&quantite);
//                    			getchar();
//                    			printf("Modify the order(Y/N):");
//                    			Modify=getchar();
//                    			if(Modify == 'Y' || Modify == 'y')
//                    			{
//                    			    modifyOrder(&OrderList,clientCode,quantite,product);
//                    			    client=getClient(ClientList,clientCode);
//                        			modifyPayments(&PaymentList,code,date,OrderList,client);
//                        			savePaymentsData(PaymentList);
//                        			goto Paymentmenu;
//                    			}
//                    			else
//                    			{
//                        			goto Paymentmenu;
//                    			}
//                        } /* End else of Payment is not exist */
//        			}
//        			else if(i==4) // remove a Payment
//        			{
//            			system("cls");
//            			int code;
//            			displayPayments(PaymentList);
//            			printf("Enter the code of Payment you want to remove:");
//           				scanf("%d",&code);
//            			deletePayment(&PaymentList,code);
//            			getchar();
//            			goto Paymentmenu;
//        			}
//        			else if(i==5) dealerMenu(ProductList,ClientList,OrderList,PaymentList); // Return to dealer menu
//        			else if(i==6) Exit();// exit
//        			else goto Paymentmenu; // wrong choice
//
//}
void employeeMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList)
{
    int i;
    empmenu:
			system("cls");
			printf("=================================================================");
			printf("\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Return to store menu\n4. Exit");
			printf("\n\n\n==========================END OF MENU=============================");
			printf("\n\n Enter your Choice :\t");
			scanf("%d",&i);
			if(i==1)
			{
				system("cls");
				getchar();
				displayProductsList(ProductList);
				getchar();
				goto empmenu;
			}
			else if(i==2)
			{
	    		int code;
	    		int quantite;
	    		system("cls");
	    		displayProductsList(ProductList);
				printf("Enter the product code:");
				scanf("%d",&code);
				//Product* product=getProduct(ProductList,code);
				printf("Enter amount to add:");
				scanf("%d",&quantite);
				//modifyProduct(&ProductList,code,product->designation,product->price);
				//refill();
				goto empmenu;
			}
			else if(i==3) menu(ProductList,ClientList,OrderList,SalesList);
            else if(i==4) Exit();
            else goto empmenu;
}

void liveCustMenu(ProductElement *ProductList,ClientElement *ClientList,OrderLine* OrderList,SalesList* SalesList)
{
    oldCustomerOrNot:
    system("cls");
    int i,custCode;
    Client* client;
    char addOrder,oldCustomer;
    printf("Hello Dear Customer,\n\n");
    printf("Are you an old customer in our store ?(Y/N):");
    oldCustomer=getchar();
    if(oldCustomer=='y' || oldCustomer=='Y')
    {
        system("cls");
        printf("Please enter your code:");
        scanf("%d",&custCode);
        getchar();
        client=getClient(ClientList,custCode);
    }
    else if (oldCustomer=='n' || oldCustomer=='N')
    {
        char* nom=(char *)malloc(sizeof(char)*25);
        char* prenom=(char *)malloc(sizeof(char)*25);
        char* telephone=(char *)malloc(sizeof(char)*25);
        newcustomer:
            system("cls");
            printf("Please enter a code to connect with next time:");
            scanf("%d",&custCode);
            getchar();
            if (customerIsExist(ClientList,custCode))
            { // customer code already exist
                printf("\nThis code already exist!\n");
                getchar();
                goto newcustomer;
            }
            else
            { // customer isn't exist in SalesList
                printf("Enter your first name:");
                gets(nom);
                printf("Enter your last name:");
                gets(prenom);
                printf("Enter your phone number:");
                gets(telephone);
                addClientToList(&ClientList,custCode,nom,prenom,telephone);
                saveCustomersData(ClientList);
            }
            client=getClient(ClientList,custCode);
    }
    else
    {
        goto oldCustomerOrNot;
    }
    custmenu:
            system("cls");
            printf("=================================================================");
            printf("\n\n\t\t\t    CUSTOMER MENU\n1. display your orders\n2. Add an order\n3. Purchase\n4. return to store menu\n5. Exit");
            printf("\n\n\n==========================END OF MENU=============================");
            printf("\n\n Enter your Choice :\t");
            scanf("%d",&i);
            getchar();
            if (i==1)
            {
                system("cls");
                displayOrdersList(OrderList,client);
                getchar();
                goto custmenu;
            }
			else if (i==2)
			{
				//withdraw();
				system("cls");
				displayOrdersList(OrderList,client);
				int codeProduct,amount;
				displayProductsList(ProductList);
				printf("Choose the product:");
				scanf("%d",&codeProduct);
                printf("Enter the amount:");
                scanf("%d",&amount);
                getchar();
                printf("Add the order (Y/N):");
                addOrder=getchar();
                if (addOrder=='y' || addOrder=='Y')
                {
                        addOrderToList(&OrderList,custCode,amount,getProduct(ProductList,codeProduct));
                        saveOrdersData(OrderList);
                }
				goto custmenu;
			}
			else if(i==3)
			{
				AutoaddSaleToSalesList(&SalesList,OrderList,client);
			}
			else if(i==4) menu(ProductList,ClientList,OrderList,SalesList);
			else if(i==5) Exit();
    		else goto custmenu;
}
void Exit()
{
    system("cls");
    printf("\n\n\n\t\t\t\tThank you!");
    printf("\n\t\t\t  Developed by:\n\n\n\n\n");
    system("color 9");
    printf("                                                                              \n                                                                              \nDDDDDDDDDDDDD                  AAA               DDDDDDDDDDDDD      IIIIIIIIII\nD::::::::::::DDD              A:::A              D::::::::::::DDD   I::::::::I\nD:::::::::::::::DD           A:::::A             D:::::::::::::::DD I::::::::I\nDDD:::::DDDDD:::::D         A:::::::A            DDD:::::DDDDD:::::DII::::::II\n  D:::::D    D:::::D       A:::::::::A             D:::::D    D:::::D I::::I  \n  D:::::D     D:::::D     A:::::A:::::A            D:::::D     D:::::DI::::I  \n  D:::::D     D:::::D    A:::::A A:::::A           D:::::D     D:::::DI::::I  \n  D:::::D     D:::::D   A:::::A   A:::::A          D:::::D     D:::::DI::::I  \n  D:::::D     D:::::D  A:::::A     A:::::A         D:::::D     D:::::DI::::I  \n  D:::::D     D:::::D A:::::AAAAAAAAA:::::A        D:::::D     D:::::DI::::I  \n  D:::::D     D:::::DA:::::::::::::::::::::A       D:::::D     D:::::DI::::I  \n  D:::::D    D:::::DA:::::AAAAAAAAAAAAA:::::A      D:::::D    D:::::D I::::I  \nDDD:::::DDDDD:::::DA:::::A             A:::::A   DDD:::::DDDDD:::::DII::::::II\nD:::::::::::::::DDA:::::A      ++       A:::::A  D:::::::::::::::DD I::::::::I\nD::::::::::::DDD A:::::A    ;++++++;     A:::::A D::::::::::::DDD   I::::::::I\nDDDDDDDDDDDDD   AAAAAAA     ;++++++;      AAAAAAADDDDDDDDDDDDD      IIIIIIIIII             \n                           #+++++++++                \n                          .+#++++++++                \n                          #+++++'+++++               \n                          ++';;;::;;++               \n                          +;;:::::::;+               \n                         `';::::::;;;+               \n                         .';::::::;;;+               \n                         :;;:::::;;:;+               \n                         ;''++';'+'':+:              \n                         ;'''';:''++;''              \n                         ;;;;;;::;;;;;;              \n                         :;:::::::::::               \n                          :::;:::;::;,               \n                           ;':;';;;;;                \n                           ;;''''';;.                \n                           :;;;;';''                 \n                           `;;;;;;;;                 \n                           ,;;:::;';:                \n                          ,.;;'''';;.+               \n                         '+.;;;';;;;.++.             \n                       :+++..;;;;;:..+++#:           \n                     '+++++...:;;:...+++++++`        \n                  :#+++++++..``,``...++++++++++#,    \n               .+++++++++++..:'';'...++++++++++++    \n               ++++++++++++::;'';'::.++++++++++++    \n               #+++++++++++:.,+';'...++++++++++++:   \n               +#++++++++++;..,'',...++++++++++###   \n              `++++++++++++'..,;;,...++++++++#####   \n              ,++++++++++++'..:'';...+++++++######:  \n              +++#++++++++++..:'''..,+++++++#####++  \n              #++#++++++++++..:'''..,+++++++#######  \n              ++++++++++++++..:''',.,+++++++#######  \n             `##++#+++++++++..;'';;.,+++++++#######  \n             ,##+##+++++++++..:''';..++++++########  \n             :##+##+++++++++..:''''.,++#+++########  \n             ,##+##+++++++++,.:'''+.,+++++########+  \n             :#####+++++++++,,:;;''.:+++++########+` ");
    getchar();
    exit(0);
}

