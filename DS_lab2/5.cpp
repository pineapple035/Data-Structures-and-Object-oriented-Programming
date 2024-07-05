#include <iostream>
#include <queue>

using namespace std;

int teamBelongTo[1000001]={0};
queue<int> teamQueue[1001];
int main()
{
    int T = 1;
    int numTeams;
    int N;
    cin>>N;
    while (N--)
    {
        cin>>numTeams;
        for (int t = 1; t <= numTeams; t++)
        {
            while (!teamQueue[t].empty())
                teamQueue[t].pop();
            int numElem;
            cin >> numElem;
            while (numElem--)
            {
                int elem;
                cin >> elem;
                teamBelongTo[elem] = t;
            }
        }

        queue<int> combinedQueue;

        cout << "Testcase #" << T++ << '\n';
        string command;
        int M;
        cin>>M;
        while (M--)
        {
            cin>>command;
            if (command=="ENQUEUE")
            {
                int num;
                cin >> num;
                int team = teamBelongTo[num];
                //cout<<team<<" "<<num<<endl;
                /*if (team==0)
                {
                    combinedQueue.push(num);
                    continue;
                }
                else */
                if (teamQueue[team].empty())
                {
                    combinedQueue.push(team);
                }

                teamQueue[team].push(num);
            }
            else if(command=="DEQUEUE")
            {
                int team = combinedQueue.front();
                cout << teamQueue[team].front() << '\n';
                teamQueue[team].pop();
                if (teamQueue[team].empty())
                    combinedQueue.pop();
            }
        }
    }
}
