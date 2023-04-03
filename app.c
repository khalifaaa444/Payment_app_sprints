#include "app.h"

void appStart2()
{




    printf("****************************************\n");
printf("\n\n MAX Amount = 8000 EGP \n\n");
printf("\n\n****************************************\n\n\n");







printf("\n\n\n\n");
printf("***************TEST      ONE  ***************");
printf("\n\n");

strcpy(customer1.cardHolderName,"Ebrahem Mostafa Ebrahem" );
strcpy(customer1.card_ExpirationData,"09/25");
strcpy(customer1.primaryAccountNumber,"123456789123456789");


strcpy(ACC1.transactionDate,"2/4/2023");
ACC1.transAmount = 2300.0;
ACC1.maxTransAmount = 8000.0;


ST_transaction_t GP1;


GP1.cardHolderData = customer1;
GP1.terminalData = ACC1;


EN_cardError_t errorDate = getCardExpiryDate(&customer1);
EN_cardError_t check_name =  getCardHolderName(&customer1);
EN_cardError_t errorPan = getCardPAN(&customer1);


        if(check_name == CARD_OK)
        {
            printf("NAME IS  valid \nHello Mr.%s \n", customer1.cardHolderName);
        }

        else
        {
            printf("Wrong Name Card\n");
        }




		/*************************** Get Card PAN Number ***************************/



			if (errorPan == CARD_OK)
            {
				printf("Card Pan is valid \n");
			}
            else
            {
                printf("PAN is not valid \n");
            }


		/*************************** Get Card Expiry Date ***************************/

		if (errorDate == CARD_OK)
        {
			printf("Expiry date IS  valid \n");
        }
		else
		{
		    printf("Expiry date IS NOT valid \n");
		}




/*************************************Terminal**************************************/



    EN_terminalError_t check_dateee;
    check_dateee =  isCardExpired(&customer1, &ACC1);

    if(isCardExpired(&customer1, &ACC1) == 0)
    {
        printf("Card is valid\n");
    }
    else
    {

        printf("Card is not Valid\n");
    }


  EN_terminalError_t check_amount = isBelowMaxAmount(&ACC1);

    setMaxAmount(&ACC1, 8000);

    if(check_amount == TERMIAL_OK)
    {
        printf("Amount Accepted\n");
    }
    else
    {
        printf("Amount is out of the range");
    }


////////////////////////////////////SERVER//////////////////////////////////////


EN_transState_t check_rec =  recieveTransactionData(&GP1);
printf("\n");
printf("%s\n",GP1.cardHolderData.primaryAccountNumber);
if(check_rec == APPROVED)
{
    printf("process is success \n");
}
else
{
    printf("\n%d\n",check_rec);
    printf("process is not done \n");
}


printf("\n\n\n\n");
printf("***************TEST      TWO   ***************");
printf("\n\n");

/*********************************************  TEST ______ TWO   ****************************************************************************/




strcpy(customer2.cardHolderName,"Mohamed sayed Amr Ahmed" );
strcpy(customer2.card_ExpirationData,"06/26");
strcpy(customer2.primaryAccountNumber,"580705557604387522");


strcpy(ACC2.transactionDate,"2/4/2023");
ACC2.transAmount = 9000.0;
ACC2.maxTransAmount = 8000.0;


ST_transaction_t GP2;


GP2.cardHolderData = customer2;
GP2.terminalData = ACC2;


EN_cardError_t errorDate2 = getCardExpiryDate(&customer2);
EN_cardError_t check_name2 =  getCardHolderName(&customer2);
EN_cardError_t errorPan2 = getCardPAN(&customer2);


        if(check_name2 == CARD_OK)
        {
            printf("NAME IS  valid \nHello Mr.%s \n", customer2.cardHolderName);
        }

        else
        {
            printf("Wrong Name Card\n");
        }




		/*************************** Get Card PAN Number ***************************/



			if (errorPan2 == CARD_OK)
            {
				printf("Card Pan is valid \n");
			}
            else
            {
                printf("PAN is not valid \n");
            }


		/*************************** Get Card Expiry Date ***************************/

		if (errorDate2 == CARD_OK)
        {
			printf("Expiry date IS  valid \n");
        }
		else
		{
		    printf("Expiry date IS NOT valid \n");
		}




/*************************************Terminal**************************************/



    EN_terminalError_t check_dateee2;
    check_dateee2 =  isCardExpired(&customer2, &ACC2);

    if(isCardExpired(&customer2, &ACC2) == 0)
    {
        printf("Card is valid\n");
    }
    else
    {

        printf("Card is not Valid\n");
    }


  EN_terminalError_t check_amount222= isBelowMaxAmount(&ACC2);

    setMaxAmount(&ACC2, 8000);

    if(check_amount222 == TERMIAL_OK)
    {
        printf("Amount Accepted\n");
    }
    else
    {
        printf("Amount is out of the range");
    }


////////////////////////////////////SERVER//////////////////////////////////////


EN_transState_t check_rec2 =  recieveTransactionData(&GP2);
printf("\n");
printf("%s\n",GP2.cardHolderData.primaryAccountNumber);
if(check_rec2 == APPROVED)
{
    printf("process is Approved \n");
}
else
{
    //printf("\n%d\n",check_rec2);
    printf("transaction decline \n");
}





printf("\n\n\n\n");
printf("***************TEST      THREE   ***************");
printf("\n\n");



/****************************************TEST __   THREE ******************************************************************/





strcpy(customer3.cardHolderName,"mohamed mahmoud ahmed");
strcpy(customer3.card_ExpirationData,"06/28");
strcpy(customer3.primaryAccountNumber,"580705557604387522");


strcpy(ACC3.transactionDate,"02/04/2023");
ACC3.transAmount = 2000.0;
ACC3.maxTransAmount = 8000.0;


ST_transaction_t GP3;


GP3.cardHolderData = customer3;
GP3.terminalData = ACC3;


EN_cardError_t errorDate3 = getCardExpiryDate(&customer3);
EN_cardError_t check_name3 =  getCardHolderName(&customer3);
EN_cardError_t errorPan3 = getCardPAN(&customer3);


        if(check_name3 == CARD_OK)
        {
            printf("NAME IS  valid \nHello Mr.%s \n", customer3.cardHolderName);
        }

        else
        {
            printf("Wrong Name Card\n");
        }




		/*************************** Get Card PAN Number ***************************/



			if (errorPan3 == CARD_OK)
            {
				printf("Card Pan is valid \n");
			}
            else
            {
                printf("PAN is not valid \n");
            }


		/*************************** Get Card Expiry Date ***************************/

		if (errorDate3 == CARD_OK)
        {
			printf("Expiry date IS  valid \n");
        }
		else
		{
		    printf("Expiry date IS NOT valid \n");
		}




/*************************************Terminal**************************************/



    EN_terminalError_t check_dateee3;
    check_dateee3 =  isCardExpired(&customer3, &ACC3);

    if(isCardExpired(&customer3, &ACC3) == 0)
    {
        printf("Card is valid\n");
    }
    else
    {

        printf("Card is not Valid\n");
    }


  EN_terminalError_t check_amount33= isBelowMaxAmount(&ACC3);

    setMaxAmount(&ACC3, 8000);

    if(check_amount33 == TERMIAL_OK)
    {
        printf("Amount Accepted\n");
    }
    else
    {
        printf("Amount is out of the range");
    }


////////////////////////////////////SERVER//////////////////////////////////////


EN_transState_t check_rec3 =  recieveTransactionData(&GP3);
printf("\n");
printf("%s\n",GP3.cardHolderData.primaryAccountNumber);
if(check_rec3 == APPROVED)
{
    printf("process is Approved \n");
}
else
{
    //printf("\n%d\n",check_rec2);
    printf("transaction decline \n");
}


printf("\n\n\n\n");
printf("***************TEST      FOUR   ***************");
printf("\n\n");


/***************************************   Test _____ FOUR   ***************************************************/





strcpy(customer4.cardHolderName,"abdulrahman mohamed amr");
strcpy(customer4.card_ExpirationData,"01/22");
strcpy(customer4.primaryAccountNumber,"123456123456123456");


strcpy(ACC4.transactionDate,"02/04/2023");
ACC4.transAmount = 2000.0;
ACC4.maxTransAmount = 8000.0;


ST_transaction_t GP4;


GP4.cardHolderData = customer4;
GP4.terminalData = ACC4;


EN_cardError_t errorDate4 = getCardExpiryDate(&customer4);
EN_cardError_t check_name4 =  getCardHolderName(&customer4);
EN_cardError_t errorPan4 = getCardPAN(&customer4);


        if(check_name4 == CARD_OK)
        {
            printf("NAME IS  valid \nHello Mr.%s \n", customer4.cardHolderName);
        }

        else
        {
            printf("Wrong Name Card\n");
        }




		/*************************** Get Card PAN Number ***************************/



			if (errorPan4 == CARD_OK)
            {
				printf("Card Pan is valid \n");
			}
            else
            {
                printf("PAN is not valid \n");
            }


		/*************************** Get Card Expiry Date ***************************/

		if (errorDate4 == CARD_OK)
        {
			printf("Expiry date IS  valid \n");
        }
		else
		{
		    printf("Expiry date IS NOT valid \n");
		}




/*************************************Terminal**************************************/



    EN_terminalError_t check_dateee4;
    check_dateee4 =  isCardExpired(&customer4, &ACC4);

    if(isCardExpired(&customer4, &ACC4) == 0)
    {
        printf("Card is valid\n");
    }
    else
    {

        printf("Card is not Valid\n");
    }


  EN_terminalError_t check_amount44= isBelowMaxAmount(&ACC4);

    setMaxAmount(&ACC4, 8000);

    if(check_amount44 == TERMIAL_OK)
    {
        printf("Amount Accepted\n");

EN_transState_t check_rec4 =  recieveTransactionData(&GP4);
printf("\n");
printf("%s\n",GP4.cardHolderData.primaryAccountNumber);
if(check_rec4 == APPROVED)
{
    printf("process is Approved \n");
}
else
{
    //printf("\n%d\n",check_rec2);
    printf("transaction decline \n");
}


    }
    else
    {
        printf("transaction decline\n");
    }



printf("\n\n\n\n");
printf("***************TEST      FIVE   ***************");
printf("\n\n");

/****************************************TEST __   FIVE ******************************************************************/





strcpy(customer5.cardHolderName,"Eslam mohamed ebrahem");
strcpy(customer5.card_ExpirationData,"06/28");
strcpy(customer5.primaryAccountNumber,"987654321987654321");


strcpy(ACC5.transactionDate,"02/04/2023");
ACC5.transAmount = 2000.0;
ACC5.maxTransAmount = 8000.0;


ST_transaction_t GP5;


GP5.cardHolderData = customer5;
GP5.terminalData = ACC5;


EN_cardError_t errorDate5 = getCardExpiryDate(&customer5);
EN_cardError_t check_name5 =  getCardHolderName(&customer5);
EN_cardError_t errorPan5 = getCardPAN(&customer5);


        if(check_name5 == CARD_OK)
        {
            printf("NAME IS  valid \nHello Mr.%s \n", customer5.cardHolderName);
        }

        else
        {
            printf("Wrong Name Card\n");
        }




		/*************************** Get Card PAN Number ***************************/



			if (errorPan5 == CARD_OK)
            {
				printf("Card Pan is valid \n");
			}
            else
            {
                printf("PAN is not valid \n");
            }


		/*************************** Get Card Expiry Date ***************************/

		if (errorDate5 == CARD_OK)
        {
			printf("Expiry date IS  valid \n");
        }
		else
		{
		    printf("Expiry date IS NOT valid \n");
		}




/*************************************Terminal**************************************/



    EN_terminalError_t check_dateee5;
    check_dateee5 =  isCardExpired(&customer5, &ACC5);

    if(isCardExpired(&customer5, &ACC5) == 0)
    {
        printf("Card is valid\n");
    }
    else
    {

        printf("Card is not Valid\n");
    }


  EN_terminalError_t check_amount55= isBelowMaxAmount(&ACC5);

    setMaxAmount(&ACC5, 8000);

    if(check_amount55 == TERMIAL_OK)
    {
        printf("Amount Accepted\n");
    }
    else
    {
        printf("Amount is out of the range");
    }


////////////////////////////////////SERVER//////////////////////////////////////


EN_transState_t check_rec5 =  recieveTransactionData(&GP5);
printf("\n");
printf("%s\n",GP5.cardHolderData.primaryAccountNumber);
if(check_rec5 == APPROVED)
{
    printf("process is Approved \n");
}
else
{
    //printf("\n%d\n",check_rec2);
    printf("transaction decline \n");
}

printf("\n\n\n\n");
printf("***************Final***************");


}



void appStart1(void)
{

    		printf("Testing Mode Activated \n");

		//while (scanf("%d", &tryagain) == 1) {
//getCardExpiryDateTest
		getCardHolderNameTEST();

		printf("\n");
//getCardPANTest
		getCardPANTest();
		printf("\n");

		getCardExpiryDateTest();
		printf("\n");
		getchar();


		getTransactionDateTest();
		printf("\n");
        getchar();
		 isCardExpiredTest();
//isCardExpiredTest
		printf("\n");

		getTransactionAmountTest();
		printf("\n");

		setMaxAmountTest();
		printf("\n");

		isBelowMaxAmountTest();
		printf("\n");


		isValidAccountTest();
		printf("\n");

		isBlockedAccountTest();
		printf("\n");

		isAmountAvailableTest();
		printf("\n");



		saveTransactionTest();
		printf("Thank You \n");



	}


