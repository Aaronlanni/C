�ַ������������Ǳ��֮ʱ������������˼���ķ��㣬ʹ�����ǵĴ������������ˣ�
��ƽ���������Ǽ�����Ҫ��д���ַ��������ģ����ǣ�����Լ����Զ���ʵ����Щ�����������������Щ�������м���İ����� 
���棬���������ַ�ʽʵ��strlen������ 
��ʽһ������������

int my_strlen(const char *arr)
{
    assert(arr!=NULL);
    int count = 0;
    while (*arr != '\0')
    {
        count++;
        arr++;
    }

    return count;
}
int main()
{
    char arr[] = "abcdef";
    int ret = 0;
    ret = my_strlen(arr);
    printf("%d\n", ret);
    system("pause");
    return 0;
}

����򻯣�ʹ�ó����������Ӽ�࣬�������£�

int my_strlen(const char *arr)
{
    assert(arr!=NULL);
    int count = 0;
    while (*arr++!= '\0')
    {
        count++;
    }

    return count;
}
int main()
{
    char arr[] = "abcdef";
    int ret = 0;
    ret = my_strlen(arr);
    printf("%d\n", ret);
    system("pause");
    return 0;
}

�ڶ��ַ�����ָ���ָ��

int my_strlen(const char *arr)
{
    assert(arr != NULL);
    const char* end = arr;
    while (*end)
    {
        end++;
    }
    return end-arr;
}
int main()
{
    char arr[] = "abcdef";
    int ret = 0;
    ret = my_strlen(arr);
    printf("%d\n", ret);
    system("pause");
    return 0;
}

�����

int my_strlen(const char *arr)
{
    assert(arr != NULL);
    const char* end = arr;
    while (*end++)
    {
            ;
    }
    return end - arr-1;
}
int main()
{
    char arr[] = "abcdef";
    int ret = 0;
    ret = my_strlen(arr);
    printf("%d\n", ret);
    system("pause");
    return 0;
}

�����������õݹ�ķ���

int my_strlen(const char *arr)
{
    assert(arr != NULL);
    const char* end = arr;
    while (*end)
    {
        end++;
        1 + my_strlen(end);
    }
    return end - arr;
}
int main()
{
    char arr[] = "abcdef";
    int ret = 0;
    ret = my_strlen(arr);
    printf("%d\n", ret);
    system("pause");
    return 0;
}