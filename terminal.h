#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
typedef unsigned char uint8_t;


typedef struct ST_terminalData_t {

	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;
ST_terminalData_t TD;

//strcpy(TD.transactionDate , "12/12/2025");
ST_cardData_t CD;




typedef enum EN_terminalError_t {
	TERMIAL_OK , WRONG_DATE , EXPIRED_CARD , INVALID_CARD , INVALID_AMOUNT , EXCEED_MAX_AMOUNT , INVALID_MAX_AMOUNT ,

}EN_terminalError_t;

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);

void getTransactionDateTest(void);

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
void isCardExpiredTest(void);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
void getTransactionAmountTest(void);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
void isBelowMaxAmountTest(void);
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount);
void setMaxAmountTest(void);


ST_terminalData_t ACC1;
ST_terminalData_t ACC2;
ST_terminalData_t ACC3;
ST_terminalData_t ACC4;
ST_terminalData_t ACC5;

#endif
