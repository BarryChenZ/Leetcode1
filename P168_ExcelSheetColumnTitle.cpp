class Solution {
public:
  string convertToTitle(int n) 
  {
    int num = n, rem = 0;
    string op;
    while (num != 0)
    {
      rem = num % 26;
      num /= 26;
      if (rem == 0)
        num--;
      op += getChar(rem - 1);
    }
    if (num != 0)
      op += getChar(rem);
    reverse(op.begin(), op.end());
    return  op;
  }
  char getChar(int n)
  {
    if (n == -1)
      return 'Z';
    return ('A' + n);
  }
};
