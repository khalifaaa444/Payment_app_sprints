#include"card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    uint8_t Name_length=0;
    uint8_t i=0;
    while (cardData->cardHolderName[i])
    {
        Name_length++;
        i++;
    }
    if (Name_length>24||Name_length<20)
    {
        return WRONG_NAME;
    }
    else
    {
        return CARD_OK;
    }
}

void getCardHolderNameTEST(void)
{
    uint8_t i=0;
    ST_cardData_t str;
    printf("Tester Name: Mohamed Sayed\n");
    printf("Function Name: getCardHolderName\n");
    for(i=1; i<4; i++)
    {
        printf("Test Case %d:\n",i);
        printf("Input Data: ");
        scanf(" %[^\n]s",str.cardHolderName);
        if (i==1)
        {
            printf("Expected Result: Card is OK                         //20<The length of named<24\n");
            if (getCardHolderName(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardHolderName(&str)==WRONG_NAME)
            {
                printf("Actual Result: Wrong Name On The Card\n");
            }
        }

        else if (i==2)
        {
            printf("Expected Result: Wrong Name On The Card              //The length of named<20\n");
            if (getCardHolderName(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardHolderName(&str)==WRONG_NAME)
            {
                printf("Actual Result: Wrong Name On The Card\n");
            }
        }
        else
        {
            printf("Expected Result: Wrong Name On The Card             //The length of named>24\n");
            if (getCardHolderName(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardHolderName(&str)==WRONG_NAME)
            {
                printf("Actual Result:   Wrong Name On The Card\n");
            }
        }
        printf("*******************************\n");

    }
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    uint8_t ExpirationData_length=0;
    uint8_t i=0;
    while (cardData->card_ExpirationData[i])
    {
        ExpirationData_length++;
        i++;
    }
    if (ExpirationData_length>5||ExpirationData_length<5||cardData->card_ExpirationData[0]>'1'||cardData->card_ExpirationData[2]!='/')
    {

        return WRONG_EXP_DATE;

    }
    else if (cardData->card_ExpirationData[0]=='1'&&cardData->card_ExpirationData[1]>'2')
    {
        return WRONG_EXP_DATE;
    }
    else
    {
        return CARD_OK;
    }
}
void getCardExpiryDateTest(void)
{
    uint8_t i=0;
    ST_cardData_t str;
    printf("Tester Name: Mohamed Sayed\n");
    printf("Function Name: getCardExpiryDate\n");
    for(i=1; i<6; i++)
    {
        printf("Test Case %d:\n",i);
        printf("Input Data: ");
        scanf(" %[^\n]s",str.card_ExpirationData);
        if (i==1)
        {
            printf("Expected Result: Card is OK                         //The Expiry data format and length is valid\n");
            if (getCardExpiryDate(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardExpiryDate(&str)==WRONG_EXP_DATE)
            {
                printf("Actual Result: Wrong ExpiryDate On The Card\n");
            }
        }

        else if (i==2)
        {
            printf("Expected Result: Wrong Expiry Date On The Card                       //The Expiry data length <5\n");
            if (getCardExpiryDate(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardExpiryDate(&str)==WRONG_EXP_DATE)
            {
                printf("Actual Result: Wrong Expiry Date On The Card\n");
            }
        }
        else if (i==3)
        {
            printf("Expected Result: Wrong Expiry Date On The Card                       //The Expiry data length >5\n");
            if (getCardExpiryDate(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardExpiryDate(&str)==WRONG_EXP_DATE)
            {
                printf("Actual Result: Wrong Expiry Date On The Card\n");
            }
        }
        else if (i==4)
        {
            printf("Expected Result: Wrong Expiry Date On The Card                       //The format of Expiry data Invalid\n");
            if (getCardExpiryDate(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardExpiryDate(&str)==WRONG_EXP_DATE)
            {
                printf("Actual Result: Wrong ExpiryDate On The Card\n");
            }
        }
        else
        {
            printf("Expected Result: Wrong Expiry Date On The Card                       //The format of Expiry data Invalid\n");
            if (getCardExpiryDate(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardExpiryDate(&str)==WRONG_EXP_DATE)
            {
                printf("Actual Result: Wrong ExpiryDate On The Card\n");
            }
        }
        printf("*******************************\n");

    }
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    uint8_t PAN_length=0;
    uint8_t i=0;
    //cardData->primaryAccountNumber
    //printf("")
    while (cardData->primaryAccountNumber[i])
    {
        PAN_length++;
        i++;
    }
   // printf("\n%d\n",PAN_length);
    if (PAN_length>19||PAN_length<16)
    {
        return WRONG_PAN;
    }
    else
    {
        return CARD_OK;
    }
}

void getCardPANTest(void)
{
    uint8_t i=0;
    ST_cardData_t str;
    printf("Tester Name: Mohamed Sayed\n");
    printf("Function Name: getCardPAN\n");
    for(i=1; i<4; i++)
    {
        printf("Test Case %d:\n",i);
        printf("Input Data: ");
        scanf(" %[^\n]s",str.primaryAccountNumber);
        if (i==1)
        {
            printf("Expected Result: Card is OK                         //16<The length of primary account number<20\n");
            if (getCardPAN(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardPAN(&str)==WRONG_PAN)
            {
                printf("Actual Result: Wrong Pan On The Card\n");
            }
        }

        else if (i==2)
        {
            printf("Expected Result: Wrong Pan On The Card                       //The length of primary account number<16\n");
            if (getCardPAN(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardPAN(&str)==WRONG_PAN)
            {
                printf("Actual Result: Wrong Pan On The Card\n");
            }
        }
        else
        {
            printf("Expected Result: Wrong Pan On The Card                       //The length of primary account number>19\n");
            if (getCardPAN(&str)==CARD_OK)
            {
                printf("Actual Result: Card is OK\n");
            }
            else if (getCardPAN(&str)==WRONG_PAN)
            {
                printf("Actual Result: Wrong Pan On The Card\n");
            }
        }
        printf("*******************************\n");

    }
}




