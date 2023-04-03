#include <stdio.h>
#include "terminal.h"
#include "card.h"
#include "server.h"
#include "app.h"
#include<time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int statee;

int main() {

		printf("Press '1' for testing mode: ");
		scanf("%d",&statee);
		if(statee == 1)
		{
		    appStart1();
		}
		else
        {
            appStart2();
        }

		return 0;
}

