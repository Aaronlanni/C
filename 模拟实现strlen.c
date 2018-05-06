字符串函数在我们编程之时，给我们提高了极大的方便，使得我们的代码清晰，明了，
在平常，我们是极少需要编写自字符串函数的，但是，如果自己可以动手实现这些函数，对我们理解这些函数，有极大的帮助。 
下面，我们用三种方式实现strlen函数： 
方式一：计数器方法

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

将其简化，使得程序看起来更加简洁，代码如下：

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

第二种方法：指针减指针

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

将其简化

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

方法三：利用递归的方法

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