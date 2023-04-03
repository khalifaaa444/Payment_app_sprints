#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
typedef  unsigned char  uint8_t;
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t card_ExpirationData[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK=0,
    WRONG_NAME,
    WRONG_EXP_DATE,
    WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
void getCardHolderNameTEST(void);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
void getCardExpiryDateTest(void);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
void getCardPANTest(void);




ST_cardData_t customer1; //=
ST_cardData_t customer2 ;//= {"Mohamed sayed "  ,"5807055576043875" , "06/26"};
ST_cardData_t customer3 ;//= {"Osama mohamed osama" ,  "5807007666543875","09/29" };
ST_cardData_t customer4 ;//= {"abdulrahman mohamed" , "8989374688836851" , "08/25" };
ST_cardData_t customer5 ;//= {"mohamed abdelsalam" , "8989374688836851" , "03/27" };







#endif
