#include "product.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------     Functions section  here       ---------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*****************************************************************************************************************************************/
/************************************************* Product Management Functions  *********************************************************/
/*****************************************************************************************************************************************/

/*Help of this function is to create new Product */

Product* createProduct(int codeProduct,char* designation,double price){
  Product *new_Product=(Product*)malloc(sizeof(Product));
  /* check new create memory are allocate or not. */
  if(new_Product)
  {
      /*Assign data to newly created ProductElement.*/
    new_Product->codeProduct=codeProduct;
    new_Product->designation=(char*)malloc(sizeof(char)*25);
    new_Product->designation=designation;
    new_Product->price=price;

    return new_Product;
  }
    else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
    return NULL;
  }
}
 /*Help of this function is to display product data */
void displayProduct(Product *temp){
    /*print product list product*/
      printf("code: %d  ",temp->codeProduct);
      printf("designation: %s  ",temp->designation);
      printf("prix: %.2lf  \n",temp->price);
}

/*help of this function is to insert the given product on end position of ProductElement linked list*/
void addProductToList(ProductElement**Productlist,int codeProduct,char* designation,double price){

    /* create new memory block using malloc function. */
    ProductElement*temp=NULL,*new_ProductElement=(ProductElement*)malloc(sizeof(ProductElement));
    new_ProductElement->product=createProduct(codeProduct,designation,price);
    new_ProductElement->next=NULL;

    if(*Productlist==NULL){
      /*When product list are empty. Insert first ProductElement*/
      *Productlist=new_ProductElement;
    }
    else{
      /*When product list are not empty*/

      /*product list first ProductElement address assign on temp pointer*/
      temp=*Productlist;

      /*This will loop find last ProductElement of exist linked product list*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;
      }

      /*assign this newly created ProductElement on end of list*/
      temp->next=new_ProductElement;

    }
}


/* Help of this function showing all element of single product list*/
void displayProductsList(ProductElement*temp){
    printf("\n==================================================================");
	printf("\n\n=================\tTHE STOCK ITEMS ARE\t==================");
	printf("\n\n==================================================================\n\n");
  if(temp==NULL){
    /*product list are empty*/
    printf("Empty linked product List\n");
  }
  else
  {
    /*When product list are not empty*/
    while(temp)
    {
      /*print product list product*/
      displayProduct(temp->product);
      /*move next memory block*/
      temp=temp->next;
    }

  }
  printf("\n==================================================================\n");
}

/* Get a product from the list */
Product *getProduct(ProductElement*temp,int productCode){

  if(temp==NULL){
    /*product list are empty*/
    printf("Empty Product List\n");
  }
  else
  {
    while(temp){
      /*If search product exist*/
      if(temp->product->codeProduct==productCode){
        /*product exist*/
        return temp->product;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*product not exist*/
    printf("\n Given product code [%d] is not exist",productCode);
    return NULL;
  }
}

/* modify a Product in the list */
void modifyProduct(ProductElement** ProductList,int productCode,char* designation, double new_price){
  if(ProductList==NULL){
    /*Product list are empty*/
    printf("Product list are empty\n");
  }
  else
  {
    ProductElement *temp=(*ProductList);
    while(temp){
      /*If search Product exist*/
      if(temp->product->codeProduct==productCode){
        /*Product exist*/
        temp->product=createProduct(productCode,designation,new_price);
        return;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*Product not exist*/
    printf("\n Given Product code %d are note exist to modify",productCode);

  }
}

 /*help of this function is to delete a product from the linked list in any position */
void deleteProduct(ProductElement** Productlist,int productCode){

  if(*Productlist!=NULL){
    int status=0;
    ProductElement *helper=*Productlist,*temp=*Productlist;

    /*If Delete First linked list element*/
    if((*Productlist)->product->codeProduct==productCode){

      *Productlist=helper->next;
      helper->next=NULL;

      /*Free linked list Product*/
      free(helper);
      helper=NULL;

    }else{

      /*Find delete Product*/
      while(temp){

        if(temp->product->codeProduct==productCode){
          /*Delete Product are exist*/
            status=1;
          break;
        }
        helper=temp;
        /*Point next memory block*/
        temp=temp->next;
      }
      if(status==1){

        helper->next=temp->next;

        /*Free linked list Product*/
        free(temp);
        temp=NULL;
      }else{
        printf("\n Delete product with code =%d Not exist",productCode);
      }
    }


  }
  else{
    printf("\n Empty Linked list");
  }
}

/*Help of this function removing all product list element.*/
void deleteAllProduct(ProductElement**Productlist){

  if(*Productlist){

    ProductElement*temp=*Productlist;

    while(temp){

      /*Moving Productlist pointer to on next memory block.*/
      *Productlist=temp->next;

      /*before removing that linked ProductElement assign
       next pointer codeProduct are null.*/
      temp->next=NULL;

      /*Free product listProductElement element*/
      free(temp);

      temp=*Productlist;
    }
    printf("\n\nFree ProductElements list of products \n");
  }
  else{
    /* When product list is empty */
    printf("\n product list is empty \n");
  }

}

int productIsExist(ProductElement*temp,int productCode){

  if(temp==NULL){
    /*product list are empty*/
    return 0;
  }
  else
  {
    while(temp){
      /*If search product exist*/
      if(temp->product->codeProduct==productCode){
        /*product exist*/
        return 1;
      }
      /*Move next pointer*/
      temp=temp->next;
    }
    /*product not exist*/
    return 0;

  }
}

