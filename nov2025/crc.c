#include <stdio.h>
#include <string.h>

char data[200], concatdata[220], src_crc[20], dest_crc[20], frame[300];
char divisor[20];
char divident[40];
char zero_crc[20] = "0000000000000000";

void crc_cal(int node)
{
    int i, j;
    int n = strlen(divisor);                       /* generator length (should be 17) */
    int total_bits;
    char *source = (node == 0) ? concatdata : frame;

    total_bits = strlen(source);                    /* number of bits available to process */

    for (j = n; j <= total_bits; j++)
    {
        if (divident[0] == '1')
        {
            for (i = 1; i < n; i++)
            {
                if (divident[i] == divisor[i])
                    divident[i - 1] = '0';
                else
                    divident[i - 1] = '1';
            }
        }
        else
        {
            for (i = 1; i < n; i++)
                divident[i - 1] = divident[i];
        }

        /* pick next bit: if j < total_bits use source[j], else use '0' */
        divident[n - 1] = (j < total_bits) ? source[j] : '0';
    }

    divident[n - 1] = '\0';

    if (node == 0)
        strcpy(src_crc, divident);
    else
        strcpy(dest_crc, divident);
}

int main()
{
    int i;

    printf("Enter the 17-bit generator bits: ");
    if (scanf("%17s", divisor) != 1) return 1;
    if (strlen(divisor) != 17)
    {
        printf("Generator must be exactly 17 bits\n");
        return 0;
    }

    printf("\nAt Source Node\nEnter the message bits: ");
    if (scanf("%199s", data) != 1) return 1;

    strcpy(concatdata, data);
    strcat(concatdata, "0000000000000000"); /* append 16 zeros */

    for (i = 0; i < 17; i++)
        divident[i] = concatdata[i];
    divident[17] = '\0';

    crc_cal(0);

    printf("\nData: %s\n", data);
    printf("CRC: %s\n", src_crc);
    printf("Transmitted Frame: %s%s\n", data, src_crc);

    printf("\nAt Destination Node\nEnter received frame: ");
    if (scanf("%299s", frame) != 1) return 1;

    for (i = 0; i < 17; i++)
        divident[i] = frame[i];
    divident[17] = '\0';

    crc_cal(1);

    if (strcmp(dest_crc, zero_crc) == 0)
        printf("\nReceived frame is error-free.\n");
    else
        printf("\nReceived frame contains errors.\n");

    return 0;
}
