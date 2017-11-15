class Solution
{
    
public:
    
    int calPoints(vector<string>& ops)
    {
        int sum = 0;
        int score = 0;
        vector<int> rounds = vector<int>();
        for (string op : ops)
        {
            if (op == "C")
            {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
            
            switch (op[0])
            {
                case '+':
                    score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
                    break;
                    
                case 'D':
                    score = rounds.back() * 2;
                    break;
                    
                default:
                    score = stoi(op);
                    break;
            }
            
            sum += score;
            rounds.push_back(score);
        }
        
        return sum;
    }
};
