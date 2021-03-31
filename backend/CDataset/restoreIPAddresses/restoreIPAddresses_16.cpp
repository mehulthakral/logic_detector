vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string currentAddr;
    if(s.size() < 4 || s.size() > 12)
    {
        return result;
    }
    currentAddr.resize(s.size() + 4); // 4 dots, the last one to be trimmed
    int addrComp = 0;
    restoreIpAddressesRecursive(s, 0, currentAddr, 0, addrComp, result);
    return result;
}

void restoreIpAddressesRecursive(const string& s, int i, string& currentAddr, int t, int addrComp, vector<string>& result)
{
    static const size_t k = 3; // max length of ip address component
    static const string maxComponentValue("255");
    
    if(i < s.size() && addrComp == 4) return;
    if(i == s.size() && addrComp == 4)
    {
        result.push_back(string(currentAddr.begin(), currentAddr.begin() + t - 1));
        return;
    }
    
    if(s[i] == '0') // don't want leading zeros
    {
        currentAddr[t++] = s[i];
        currentAddr[t] = '.';
        restoreIpAddressesRecursive(s, i + 1, currentAddr, t + 1, addrComp + 1, result);
        return;
    }

    // pick up the next possible component
    auto r = min(s.size(), i + k - 1);
    auto j = i;
    for(; j < r; ++j)
    {
        currentAddr[t++] = s[j];
        currentAddr[t] = '.';
        restoreIpAddressesRecursive(s, j + 1, currentAddr, t + 1, addrComp + 1, result);
    }
    if(j - i + 1 == k) // evaluate if the max length component is small enough to be taken into consideration
    {
        if(string(&s[i], &s[i] + k) <= maxComponentValue)
        {
            currentAddr[t++] = s[j];
            currentAddr[t] = '.';
            restoreIpAddressesRecursive(s, j + 1, currentAddr, t + 1, addrComp + 1, result);
        }
    }
}