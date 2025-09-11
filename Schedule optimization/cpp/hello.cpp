void convert(int a[])
{
    for (int i = 0; i < 32; i += 4)
    {
        int hexDigit = 0; // Gộp 4 bit lại thành một số hexa
        for (int j = 0; j < 4; ++j)
        {
            hexDigit = (hexDigit << 1) | a[i + j];
        }
        // In ký tự thập lục phân tương ứng
        if (hexDigit < 10)
            printf("%d", hexDigit);
        else
            printf("%c", 'A' + (hexDigit - 10));
    }
    printf("\n");
}