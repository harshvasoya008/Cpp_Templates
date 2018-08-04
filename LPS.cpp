int computeLPSArray(string str)
{
	int M = str.length();
	int lps[M];
	
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1 
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
        	// backing until match is found
            if (len != 0)
            	len = lps[len-1];
            	
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps[M-1];
}
