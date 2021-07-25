#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Get valid input
    int t;
    do cin >> t; while (t > 1000 || t < 1);
    for (int i = 0; i < t; i++)
    {
        int n;
        do cin >> n; while (n < 1 || n > 50);
        char log[n];
        for (int i = 0; i < n; i++) cin >> log[i];

        // Check positions of each letter in the alphabet, one at a time
        bool suspecious_string  = false;
        for (char t = 'A'; t <= 'Z' && !suspecious_string; t++)
        {
            vector<int> indeces;
            for (int i = 0; i < n; i++)
            {
                if (log[i] == t) indeces.push_back(i);
            }
            int length = indeces.size();
            // If the letter was found in a location not right after the last location, that can cause suspect
            for (int i = 0; i < length - 1; i++) if (indeces[i + 1] - indeces[i] > 1) suspecious_string = true;
        }

        // Output result
        if (suspecious_string) cout << "NO";
        else cout << "YES";
        cout << endl;
    }

    return 0;
}
