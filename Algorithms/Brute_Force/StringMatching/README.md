# String Matching  

This algorithm checks the occurence of a pattern in a text. The brute force approach consists in checking, at all positions in the text between 0 and n-m, whether an occurrence of the pattern starts there or not. Then, after each attempt, it shifts the pattern by exactly one position to the right.  

If length of text is n and length of pattern is m,  
    
Worst Case:   
Compare pattern(of length m) to each substring of text.  
Time Complexity is O( mn ).  
Number of Comparisons is m*(n-m+1).  

Best Case: 
pattern is found at index 0.  
Time Complexity is O( m ).  
Number of Comparisms is m.  
