#pragma once
#ifndef APP_H_
#define APP_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "card.h"
#include "terminal.h"
#include "server.h"
/*
typedef struct Customers
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t card_ExpirationData[6];
}ST_Customers_t;
*/




//customer1.cardHolderName="Ebrahem mostafa Ebrahem";
//strcpy(&(customer1->cardHolderName),"Ebrahem mostafa Ebrahem");
//strcpy(customer2.cardHolderName,"Mohamed sayed amr ahmed");
//strcpy(customer3.cardHolderName,);
//strcpy(customer4.cardHolderName,);
//strcpy(customer5.cardHolderName,);

//strcpy(customer1.primaryAccountNumber,);
//strcpy(customer2.primaryAccountNumber,"5807055576043875");
//strcpy(customer3.primaryAccountNumber,"5807007666543875");
//strcpy(customer4.primaryAccountNumber,"8989374688836851");
//strcpy(customer5.primaryAccountNumber,"8989374688836851");

//strcpy(customer1.card_ExpirationData,);
//strcpy(customer2.card_ExpirationData,);
//strcpy(customer3.card_ExpirationData,"09/29");
//strcpy(customer4.card_ExpirationData,"08/25");
//strcpy(customer5.card_ExpirationData,"03/27");


/*
typedef struct Acc_Customers {

	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_AccCustomers_t;

ST_AccCustomers_t ACC1;
ST_AccCustomers_t ACC2;
ST_AccCustomers_t ACC3;
ST_AccCustomers_t ACC4;
ST_AccCustomers_t ACC5;

*/
void appStart1(void);
void appStart2(void);

#endif
