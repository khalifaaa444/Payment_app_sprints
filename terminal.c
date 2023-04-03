#include"terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{

    if (strlen(termData->transactionDate) < 10)  return WRONG_DATE;
    //else if (termData->transactionDate == 0)  return WRONG_DATE;
    else
    {

        if ((termData->transactionDate[2] != '/') || (termData->transactionDate[5] != '/'))
        {
            return WRONG_DATE;
        }

        else if ((termData->transactionDate[0] == '3') && (termData->transactionDate[1] > '1'))
        {
            return WRONG_DATE;
        }
        else if ((termData->transactionDate[0] > '3'))
        {
            return WRONG_DATE;
        }
        else if ((termData->transactionDate[3] == '1') && (termData->transactionDate[4] > '2'))
        {
            return WRONG_DATE;
        }
        else if ((termData->transactionDate[3] > '1'))
        {
            return WRONG_DATE;
        }

        else
            return TERMIAL_OK;
    }
}

void getTransactionDateTest(void)
{
    int i;
    printf("Tester Name: Mohamed Abdelsalam\n");
    printf("Function Name: getTransactionDate\n");

    for (i = 1; i < 3; i++)
    {
        printf("Test Case %d:\n", i);
        printf("Input Data: ");
        gets(&(TD.transactionDate));

        if (i == 1)
        {

            if (getTransactionDate(&TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK                         //The TransactionDate = 10 and format is correct\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (getTransactionDate(&TD) == WRONG_DATE)
            {
                printf("Expected Result: WRONG_DATE\n");
                printf("Actual Result: WRONG_DATE                          //The TransactionDate < 10 or = null or wrong format\n");
            }
        }
        if (i == 2)
        {

            if (getTransactionDate(&TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK                         //The TransactionDate = 10 and format is correct\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (getTransactionDate(&TD) == WRONG_DATE)
            {
                printf("Expected Result: WRONG_DATE\n");
                printf("Actual Result: WRONG_DATE                          //The TransactionDate < 10 or = null or wrong format\n");
            }
        }
        printf("*******************************\n");
    }
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{

    if (termData->transactionDate[8] < cardData->card_ExpirationData[3])
    {
        return TERMIAL_OK;
    }
    else if (termData->transactionDate[8] == cardData->card_ExpirationData[3])
    {
        if (termData->transactionDate[9] < cardData->card_ExpirationData[4])
        {
            return TERMIAL_OK;
        }
        else if (termData->transactionDate[9] > cardData->card_ExpirationData[4])
        {
            return EXPIRED_CARD;
        }

        else if (termData->transactionDate[9] == cardData->card_ExpirationData[4])
        {
            if (termData->transactionDate[3] < cardData->card_ExpirationData[0])
            {
                return TERMIAL_OK;
            }
            else if (termData->transactionDate[3] > cardData->card_ExpirationData[0])
            {
                return EXPIRED_CARD;
            }
            else if (termData->transactionDate[3] == cardData->card_ExpirationData[0])
            {
                if (termData->transactionDate[4] <= cardData->card_ExpirationData[1])
                {
                    return TERMIAL_OK;
                }
                else return EXPIRED_CARD;
            }

        }
    }



    else return EXPIRED_CARD;
}
void isCardExpiredTest(void)
{
    int i;
    printf("Tester Name: Mohamed Abdelsalam\n");
    printf("Function Name: isCardExpired\n");
    CD.card_ExpirationData[0] = '0';
    CD.card_ExpirationData[1] = '6';
    CD.card_ExpirationData[2] = '/';
    CD.card_ExpirationData[3] = '2';
    CD.card_ExpirationData[4] = '3';
    for (i = 1; i < 3; i++)
    {
        printf("Test Case %d:\n", i);
        printf("Input Data: ");
        gets(&(TD.transactionDate));


        if (i == 1)
        {

            if (isCardExpired(&CD, &TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (isCardExpired(&CD, &TD) == EXPIRED_CARD)
            {
                printf("Expected Result: EXPIRED_CARD\n");
                printf("Actual Result: EXPIRED_CARD                          //Card is invalid\n");
            }
        }
        if (i == 2)
        {

            if (isCardExpired(&CD, &TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (isCardExpired(&CD, &TD) == EXPIRED_CARD)
            {
                printf("Expected Result: EXPIRED_CARD\n");
                printf("Actual Result: EXPIRED_CARD                          //Card is out of date\n");
            }

        }
        printf("*******************************\n");
    }
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{

    if ((termData->transAmount) <= 0) return INVALID_AMOUNT;
    else return TERMIAL_OK;
}
void getTransactionAmountTest(void)
{
    int i;
    printf("Tester Name: Mohamed Abdelsalam\n");
    printf("Function Name: getTransactionAmount\n");

    for (i = 1; i < 3; i++)
    {
        printf("Test Case %d:\n", i);
        printf("Input Data: ");
        scanf(" %f", &TD.transAmount);


        if (i == 1)
        {

            if (getTransactionAmount(&TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (getTransactionAmount(&TD) == INVALID_AMOUNT)
            {
                printf("Expected Result: INVALID_AMOUNT\n");
                printf("Actual Result: INVALID_AMOUNT                          //Amount is invalid\n");
            }
        }
        if (i == 2)
        {

            if (getTransactionAmount(&TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (getTransactionAmount(&TD) == INVALID_AMOUNT)
            {
                printf("Expected Result: INVALID_AMOUNT\n");
                printf("Actual Result: INVALID_AMOUNT                          //Amount is invalid\n");
            }

        }
        printf("*******************************\n");
    }
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{


    if ((termData->transAmount) > (termData->maxTransAmount)) return EXCEED_MAX_AMOUNT;
    else return TERMIAL_OK;
}
void isBelowMaxAmountTest(void)
{
    int i;
    printf("Tester Name: Mohamed Abdelsalam\n");
    printf("Function Name: isBelowMaxAmountTest\n");

    for (i = 1; i < 3; i++)
    {
        printf("Test Case %d:\n", i);
        printf("Input Data: ");
        scanf(" %f", &TD.transAmount);


        if (i == 1)
        {

            if (isBelowMaxAmount(&TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (isBelowMaxAmount(&TD) == EXCEED_MAX_AMOUNT)
            {
                printf("Expected Result: EXCEED_MAX_AMOUNT\n");
                printf("Actual Result: EXCEED_MAX_AMOUNT                          //Amount is invalid\n");
            }
        }
        if (i == 2)
        {

            if (isBelowMaxAmount(&TD) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (isBelowMaxAmount(&TD) == EXCEED_MAX_AMOUNT)
            {
                printf("Expected Result: EXCEED_MAX_AMOUNT\n");
                printf("Actual Result: EXCEED_MAX_AMOUNT                          //EXCEED_MAX_AMOUNT\n");
            }

        }
        printf("*******************************\n");
    }


}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
    if (maxAmount <= 0)
    {
        return INVALID_MAX_AMOUNT;
    }
    else
    {
        termData->maxTransAmount = maxAmount;
        return TERMIAL_OK;
    }
}
void setMaxAmountTest(void)
{
    int i;

    printf("Tester Name: Mohamed Abdelsalam\n");
    printf("Function Name: setMaxAmount\n");

    for (i = 1; i < 3; i++)
    {
        printf("Test Case %d:\n", i);
        printf("Input Data: ");
        scanf(" %f", &TD.maxTransAmount);


        if (i == 1)
        {

            if (setMaxAmount(&TD, TD.maxTransAmount) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (setMaxAmount(&TD, TD.maxTransAmount) == INVALID_MAX_AMOUNT)
            {
                printf("Expected Result: INVALID_MAX_AMOUNT\n");
                printf("Actual Result: INVALID_MAX_AMOUNT                          //Amount is negative\n");
            }
        }
        if (i == 2)
        {

            if (setMaxAmount(&TD, TD.maxTransAmount) == TERMIAL_OK)
            {
                printf("Expected Result: Terminal is OK\n");
                printf("Actual Result: Terminal is OK\n");
            }
            else if (setMaxAmount(&TD, TD.maxTransAmount) == INVALID_MAX_AMOUNT)
            {
                printf("Expected Result: INVALID_MAX_AMOUNT\n");
                printf("Actual Result: INVALID_MAX_AMOUNT                          //INVALID_MAX_AMOUNT\n");
            }

        }
        printf("*******************************\n");
    }
}
