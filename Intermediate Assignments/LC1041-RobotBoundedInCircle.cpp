class Solution {
/*
(x,y) is the location of chopper.
d[i] is the direction he is facing.
i = (i + 1) % 4 will turn right
i = (i + 3) % 4 will turn left
*/
public:
    bool isRobotBounded(string ins) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        int n = ins.length();
        for(int j=0; j<n; j++)
        {
            if(ins[j] == 'R')
                i = (i+1)%4;
            else if(ins[j] == 'L')
                i = (i+3)%4;
            else
            {
                x += d[i][0];
                y += d[i][1];
            }
        }
        return ((x == 0 && y == 0) || i>0);
    }
};

/*
if chopper return to the origin, he is obvious in an circle.
if chopper finishes with face not towards north,
it will get back to the initial status in another one or three sequences.
*/
