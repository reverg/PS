using namespace std;

class Logger
{
public:
    unordered_map<string, int> um;

    Logger()
    {
        // default
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (um.find(message) != um.end())
        {
            if (um[message] + 10 > timestamp)
            {
                return false;
            }
            else
            {
                um[message] = timestamp;
                return true;
            }
        }
        else
        {
            um[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

/*
지금까지 받은 모든 로그를 저장해서 메모리 효율이 좋지 않다.
queue+set으로 풀면 메모리를 덜 사용 가능하다.
*/