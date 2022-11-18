class Solution {
public:
bool isUgly(int num)
{
if (num <= 0 || num > INT32_MAX)
{
return false;
} else
{
while (num % 5 == 0) {
num = num / 5;
}
while (num % 3 == 0)
{
num = num / 3;
}
while (num % 2 == 0)
{
num = num / 2;
}
if (num > 1)
{
return false;
}
else
{
return true;
}
}
}
};
