#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getNumLength(long);
int getFirstDigit(long);
int getTwoFirstDigits(long);

int main (void)
{
    long CCNum = get_long("Introduce your credit card number:\n");
    int CCFirstNum = getFirstDigit(CCNum);
    int CCFirstNums = getTwoFirstDigits(CCNum);
    int CCLength = getNumLength(CCNum);

    int evenSum = 0;
    int oddSum = 0;

    int count = 1;

    while (CCNum > 0)
    {
        int currNum = CCNum % 10;

        if (count % 2 == 0)
        {
            int product = currNum * 2;

            if (product >= 10)
            {
                while (product > 0)
                {
                    int digit = product % 10;
                    evenSum += digit;
                    product /= 10;
                }
            }
            else
            {
                evenSum += product;
            }
        }
        else
        {
            oddSum += currNum;
        }

        CCNum /= 10;
        count++;
    }

    bool isValid = (evenSum + oddSum) % 10 == 0;

    if (isValid)
    {
        if ((CCFirstNums == 34 || CCFirstNums == 37) && CCLength == 15)
        {
            printf("AMEX\n");
        }
        else if (CCFirstNum == 4 && (CCLength == 13 || CCLength == 16))
        {
            printf("VISA\n");
        }
        else if ((CCFirstNums == 51 || CCFirstNums == 52 || CCFirstNums == 53 || CCFirstNums == 54 || CCFirstNums == 55) && CCLength == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int getNumLength(long num)
{
    int count = 0;

    while (num != 0)
    {
        num /= 10;
        count++;
    }

    return count;
}

int getFirstDigit(long num)
{
	while (num >= 10)
	{
		num = num / 10;
	}

	return num;
}

int getTwoFirstDigits(long num)
{
	while (num >= 100)
	{
		num = num / 10;
	}

	return num;
}
