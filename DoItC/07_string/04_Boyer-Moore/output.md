## output

**main.c실행결과**

```text
======================================================================
    Boyer-Moore Bad Character Shift Index Regression Verification     
======================================================================

======================================================================
[Test Case 1] User Case: tx Pointer Regression & Redundant Comparison Test
Text   : "aaaaaabaaaaaaaa"
Pattern: "baaaaaa"
======================================================================
Shifts & Matching Progress:
----------------------------------------------------------------------
Idx  Text Pointer & Pattern Alignments
----------------------------------------------------------------------
00 aaaaaabaaaaaaaa
         |
   baaaaaa 

06 aaaaaabaaaaaaaa
               +
         baaaaaa 

06 aaaaaabaaaaaaaa
              +
         baaaaaa 

06 aaaaaabaaaaaaaa
             +
         baaaaaa 

06 aaaaaabaaaaaaaa
            +
         baaaaaa 

06 aaaaaabaaaaaaaa
           +
         baaaaaa 

06 aaaaaabaaaaaaaa
          +
         baaaaaa 

06 aaaaaabaaaaaaaa
         +
         baaaaaa 

----------------------------------------------------------------------
>>> [SUCCESS] Pattern found starting at index [6]
======================================================================

======================================================================
[Test Case 2] Standard Case: Ideal Bad Character Shift (O(N/M))
Text   : "abecdabce"
Pattern: "abcd"
======================================================================
Shifts & Matching Progress:
----------------------------------------------------------------------
Idx  Text Pointer & Pattern Alignments
----------------------------------------------------------------------
00 abecdabce
      |
   abcd 

01 abecdabce
       +
    abcd 

01 abecdabce
      +
    abcd 

01 abecdabce
     |
    abcd 

03 abecdabce
         |
      abcd 

05 abecdabce
           |
        abcd 

----------------------------------------------------------------------
>>> [FAILURE] Pattern NOT found within the text (-1)
======================================================================

======================================================================
[Test Case 3] Edge Case: Worst-case Single Character Repeated
Text   : "aaaaaaaaaaaaaaa"
Pattern: "aaaa"
======================================================================
Shifts & Matching Progress:
----------------------------------------------------------------------
Idx  Text Pointer & Pattern Alignments
----------------------------------------------------------------------
00 aaaaaaaaaaaaaaa
      +
   aaaa 

00 aaaaaaaaaaaaaaa
     +
   aaaa 

00 aaaaaaaaaaaaaaa
    +
   aaaa 

00 aaaaaaaaaaaaaaa
   +
   aaaa 

----------------------------------------------------------------------
>>> [SUCCESS] Pattern found starting at index [0]
======================================================================
```
