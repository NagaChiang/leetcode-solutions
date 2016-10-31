using System;

public class Solution
{
    public IList<string> FizzBuzz(int n)
    {
        List<string> list = new List<string>();
        for (int i = 1; i <= n; i++)
        {
            // Convert int to string
            string strNumber = i.ToString();

            // Check for 3
            bool hasFactor3 = false;
            int sum = 0;
            for (int j = 0; j < strNumber.Length; j++)
                sum += Int32.Parse(strNumber[j].ToString());
            if (sum % 3 == 0)
                hasFactor3 = true;

            // Check for 5
            bool hasFactor5 = false;
            int lastDigit = Int32.Parse(strNumber[strNumber.Length - 1].ToString());
            if (lastDigit == 0 || lastDigit == 5)
                hasFactor5 = true;

            // Make the string and push it to list
            string str = "";
            if (hasFactor3)
                str += "Fizz";
            if (hasFactor5)
                str += "Buzz";
            if (!hasFactor3 && !hasFactor5)
                str = i.ToString();
            list.Add(str);
        }

        return list;
    }
}
