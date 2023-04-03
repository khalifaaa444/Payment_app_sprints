#include "server.h"

/* Create a global array of ST_accountsDB_t for the valid accounts database. */
ST_accountsDB_t accountsDB[255] =
    {

    {20000.0, RUNNING, "123456789123456789"},
    {100000.0, BLOCKED, "5807055576043875"},
    {500.9, RUNNING, "580705557604387522"},
    {13250.5, BLOCKED, "8988945615422221"},
    {200660.0, RUNNING, "8989644615431111"},
    {21.0, BLOCKED, "8989644615436177"},
    {199000.0, RUNNING, "1000644780536129"},
    {199000.0, BLOCKED, "987654321987654321"},
    {5000.0, RUNNING, "580795557604387522"},
    {13200.0, RUNNING, "123456123456123456"},

    };

/* Create a global array of ST_transaction_t */

ST_transaction_t transactionsDB [255] = {0};
uint32_t sequenceNum = 0;

int i;

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
/* Implementation of recieveTransactionData function
* 1. This function will take all transaction data and validate its data, it contains all server logic.
* 2. It checks the account details and amount availability.
* 3. If the account does not exist return FRAUD_CARD, if the amount is not available will return DECLINED_INSUFFECIENT_FUND
*    if the account is blocked will return DECLINED_STOLEN_CARD,
*    if a transaction can't be saved will return INTERNAL_SERVER_ERROR , else returns APPROVED.
* 4. It will update the database with the new balance.
*/
{


    ST_accountsDB_t ptr;

    if(isValidAccount((&(transData->cardHolderData)), &ptr) == ACCOUNT_NOT_FOUND)
    {

        return FRAUD_CARD;
    }

    if(isAmountAvailable((&(transData->terminalData)), &ptr) == LOW_BALANCE)
    {

        return DECLINED_INSUFFECIENT_FUND;
    }
    if(isBlockedAccount(&ptr) == BLOCKED_ACCOUNT)
    {
        return DECLINED_STOLEN_CARD;
    }
    if(sequenceNum == 255)
    {
        return INTERNAL_SERVER_ERROR;
    }
    for( i =0; i<VALID_ACCOUNTS_NUM; i++)
    {
        if(strcmp (transData->cardHolderData.primaryAccountNumber, accountsDB[i].primaryAccountNumber) == 0)
        {
            accountsDB[i].balance -= transData->terminalData.transAmount;
        }
    }
    transData->transState = APPROVED;
    saveTransaction(transData);
    return APPROVED;

}


EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountRefrence)
/*
* 1. This function will take card data and validate if the account related to this card exists or not.
* 2. It checks if the PAN exists or not in the server's database (searches for the card PAN in the DB).
* 3. If the PAN doesn't exist will return ACCOUNT_NOT_FOUND and the account reference will be NULL,
     else will return SERVER_OK and return a reference to this account in the DB.
*/
{
    for( i =0; i< VALID_ACCOUNTS_NUM ; i++)
    {
        if(strcmp (cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber) == 0)
        {
            accountRefrence = &(accountsDB[i]);
          //*accountRefrence = &(accountsDB[i]);
          //printf("inside fun : acc ref = %p\n", accountRefrence);
            return SERVER_OK;
        }
        else
        {
            // do nothing
        }
    }

    // not found
    accountRefrence = NULL;
    return ACCOUNT_NOT_FOUND;

}

// testing the previous function
void isValidAccountTest(void)
{
    ST_cardData_t *ptr;
    ST_cardData_t temp1 = { "Osama Abdelmonem", "8989374688836851","10/25" };
    ST_cardData_t temp2 = { "Mohamed Ahmed", "8989374688836841", "02/29" };

    // happy case

    printf("Tester Name: Osama Abdelmonem\n");
    printf("Function Name: isValidAccount\n");
    printf("Test Case 1: account exists\n");
    printf("Input Data: PAN = 8989374688836851\n");
    printf("Expected Result: 0 -> SERVER_OK\n");
    printf("Actual Result: %d\n", isValidAccount(&temp1, ptr));

    // worst case
    printf("Test Case 2: account doesn't exists\n");
    printf("Input Data: PAN = 8989374688836841\n");
    printf("Expected Result: 3 -> ACCOUNT_NOT_FOUND\n");
    printf("Actual Result: %d\n", isValidAccount(&temp2, ptr));

}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
/*
* 1. This function takes a reference to the account into the database and verifies if it is blocked or not.
* 2. If the account is running it will return SERVER_OK, else if the account is blocked it will return BLOCKED_ACCOUNT.
*/

{
    return accountRefrence->state == RUNNING ? SERVER_OK : BLOCKED_ACCOUNT;
}

// testing the previous function
void isBlockedAccountTest(void)
{
    // happy case

    printf("Tester Name: Osama Abdelmonem\n");
    printf("Function Name: isBlockedAccount\n");
    printf("Test Case 1: account is running\n");
    printf("Input Data: account no. 1 in database \n");
    printf("Expected Result: 0 -> SERVER_OK\n");
    printf("Actual Result: %d\n", isBlockedAccount(&accountsDB[0]));

    // worst case
    printf("Test Case 2: account is blocked\n");
    printf("Input Data: PAN = account  no.2 in database\n");
    printf("Expected Result: 5 -> BLOCKED_ACCOUNT\n");
    printf("Actual Result: %d\n", isBlockedAccount( &accountsDB[1]));

}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
/*
* 1. This function will take terminal data and a reference to the account in the database and check if the account has a sufficient amount to withdraw or not.
* 2. It checks if the transaction's amount is available or not.
* 3. If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return SERVER_OK.
*/
{
  if((int) (termData->transAmount) < (int) (accountRefrence->balance))
  {
      return SERVER_OK;

  }
  else
  {
      return LOW_BALANCE;
  }
}

// testing the above function
void isAmountAvailableTest(void)
{
    ST_terminalData_t temp_terminal_data = {1000.0, 100.0 , "11/26"};

    // 1000 is lower than 2000 and greater than 500
    // happy case

    printf("Tester Name: Osama Abdelmonem\n");
    printf("Function Name: isAmountAvailable\n");
    printf("Test Case 1: amount is available\n");
    printf("Input Data: sufficient amount in terminal \n");
    printf("Expected Result: 0 -> SERVER_OK\n");
    printf("Actual Result: %d\n", isAmountAvailable(&temp_terminal_data, &accountsDB[0]));

    // worst case
    printf("Test Case 2: insufficient amount in terminal\n");
    printf("Input Data: PAN = account  no.2 in database\n");
    printf("Expected Result: 4 -> LOW_BALANCE\n");
    printf("Actual Result: %d\n", isAmountAvailable(&temp_terminal_data, &accountsDB[8]));

}


EN_serverError_t saveTransaction(ST_transaction_t *transData)

{
    if(sequenceNum == 255)
    {
        return SERVER_OK;
    }


    transactionsDB [sequenceNum].cardHolderData = transData->cardHolderData;
    transactionsDB [sequenceNum].terminalData   = transData->terminalData;
    transactionsDB [sequenceNum].transState     = transData->transState;
    transData->transactionSequenceNumber          = sequenceNum;

    sequenceNum = sequenceNum +1;
    listSavedTransactions();
    return SERVER_OK;

}
// testing the previous function
void saveTransactionTest(void)
{
    ST_transaction_t temp_transaction;
    strcpy(temp_transaction.cardHolderData.card_ExpirationData, "11/26");
    strcpy(temp_transaction.cardHolderData.cardHolderName, "Osama Abdelmonem");
    strcpy(temp_transaction.terminalData.transactionDate, "11/2023");
    strcpy(temp_transaction.cardHolderData.primaryAccountNumber, "8989374688836851");
    temp_transaction.terminalData.maxTransAmount = 8000.0;
    temp_transaction.terminalData.transAmount= 2000.0;
    temp_transaction.transState = APPROVED;
    saveTransaction(&temp_transaction);

    ST_transaction_t temp2_transaction;
    strcpy(temp2_transaction.cardHolderData.card_ExpirationData, "02/29");
    strcpy(temp2_transaction.cardHolderData.cardHolderName, "Mohamed Ahmed");
    strcpy(temp2_transaction.terminalData.transactionDate, "03/2024");
    strcpy(temp2_transaction.cardHolderData.primaryAccountNumber, "8989300088836851");
    temp2_transaction.terminalData.maxTransAmount = 30000.0;
    temp2_transaction.terminalData.transAmount= 700.0;
    temp2_transaction.transState = FRAUD_CARD;

    saveTransaction(&temp2_transaction);
}

void listSavedTransactions(void)
{int i;
    for ( i =0; i < sequenceNum; i++)
    {
        printf("#########################\n");
        printf("Transaction Sequence Number: %d\n", i);
        printf("Transaction Date: %s\n", transactionsDB[i].terminalData.transactionDate);
        printf("Transaction Amount: %f\n", transactionsDB[i].terminalData.transAmount);
        printf("Transaction State: ");

        switch (transactionsDB[i].transState)
        {
            case APPROVED: printf("APPROVED\n");
            break;
            case DECLINED_INSUFFECIENT_FUND: printf("DECLINED_INSUFFECIENT_FUND\n");
            break;
            case FRAUD_CARD: printf("FRAUD_CARD\n");
            break;
            case INTERNAL_SERVER_ERROR: printf("INTERNAL_SERVER_ERROR\n");
        }

        printf("Terminal Max Amount: %f\n", transactionsDB[i].terminalData.maxTransAmount);
        printf("Card Holder Name: %s\n", transactionsDB[i].cardHolderData.cardHolderName);
        printf("PAN: %s\n", transactionsDB[i].cardHolderData.primaryAccountNumber);
        printf("Card Expiration Date: %s\n", transactionsDB[i].cardHolderData.card_ExpirationData);
        printf("#########################\n");

    }
}

//testing the above function
void listSavedTransactionsTest(void)
{

    ST_transaction_t temp_transaction;
    strcpy(temp_transaction.cardHolderData.card_ExpirationData, "11/26");
    strcpy(temp_transaction.cardHolderData.cardHolderName, "Osama Abdelmonem");
    strcpy(temp_transaction.terminalData.transactionDate, "11/2023");
    strcpy(temp_transaction.cardHolderData.primaryAccountNumber, "8989374688836851");
    temp_transaction.terminalData.maxTransAmount = 8000.0;
    temp_transaction.terminalData.transAmount= 2000.0;
    temp_transaction.transState = APPROVED;
    saveTransaction(&temp_transaction);

    ST_transaction_t temp2_transaction;
    strcpy(temp2_transaction.cardHolderData.card_ExpirationData, "02/29");
    strcpy(temp2_transaction.cardHolderData.cardHolderName, "Mohamed Ahmed");
    strcpy(temp2_transaction.terminalData.transactionDate, "03/2024");
    strcpy(temp2_transaction.cardHolderData.primaryAccountNumber, "8989300088836851");
    temp2_transaction.terminalData.maxTransAmount = 30000.0;
    temp2_transaction.terminalData.transAmount= 700.0;
    temp2_transaction.transState = FRAUD_CARD;

    saveTransaction(&temp2_transaction);

}

