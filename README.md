

1. Caesar Cipher 
A basic substitution cipher where each letter in the plaintext is shifted by a user-defined number of positions in the alphabet.

2. Atbash Cipher
A monoalphabetic cipher that replaces each letter with its opposite in the alphabet (e.g., 'A' becomes 'Z', 'B' becomes 'Y').

3. August Cipher
A Caesar cipher variant that uses a fixed shift of 8, inspired by August being the 8th month of the year.

4. Affine Cipher
A cipher based on a linear mathematical function:  
E(x) = (a * x + b) mod 26
where `a` and `b` are keys. Decryption uses the modular inverse of `a`.

5. Vigenère Cipher
A polyalphabetic cipher that applies different Caesar shifts based on a keyword. Each character of the key determines the shift for the corresponding letter in the message.

6. Gronsfeld Cipher
Similar to the Vigenère cipher, but uses a numerical key where each digit determines the letter shift.

7. Beaufort Cipher
A cipher that uses the formula:  
C = (K – P + 26) mod 26 
This method is symmetrical, meaning the same formula is used for both encryption and decryption.

8. Autokey / Running Key Cipher
A Vigenère cipher variant that uses a longer key, often a section of meaningful text. If the key is too short, it is repeated to match the message length.

9. N-Gram Analysis
A tool used to count and analyze the frequency of character sequences (n-grams) of a specified length in a given text.

10. Hill Cipher (2x2 Version)*
A cipher that encrypts pairs of letters (digrams) by representing them as vectors and multiplying by a 2x2 key matrix, then taking mod 26.

11. Rail Fence Cipher
A transposition cipher that writes the message in a zigzag pattern across a number of lines (rails), then reads it off row by row.

12. Route Cipher
This transposition cipher arranges the message into a rectangular grid and reads it in a specific route, such as column-wise. Spaces are removed and 'X' characters may be added as padding.

13. Myszkowski Cipher
A variation of the columnar transposition cipher. It uses a keyword, and columns with identical letters in the key are read in the order they appear, preserving the original structure during transposition.

Hi,We are from Shiv Nadar University chennaigit checkout -b update-readme
local change from me 
