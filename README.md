# Huffman-Encoding-Project


Project for CSCI 377 (Computer Algorithms)


Huffman coding is a lossless compression algorithm independent of data types that allows us to reduce the size of a file without losing any data input. For my program, I’ll be using the following built in C++ libraries: vector, iostream, queue, and string. With these libraries, we can create a Huffman coding program utilizing the greedy algorithm. In my code, the user is prompted to enter a sequence of characters to be encoded. Once the user has entered a string sequence we initialize two global vectors that store both the character and the value of the character. Afterward, the function charValFreq() takes the frequency of each character provided including spaces and numerical values. In the code within the charValFreq() there is a bool (true or false) condition that allows us to enable the option for the extra credit assignment where we also include both letters “ntht” in the output. This can be enabled by setting extraCredit to True. Once we’ve calculated both the character and its frequency we then call encode() with 3 parameters them being the characters, frequency, and the size of the vector. With this information, we can successfully generate a node tree. To construct our node tree, We will utilize the queue library and make use of the built-in priority queue template to construct our node tree. We then sort from the list from lowest to greatest frequencies and determine which value has the highest frequency. Finally, our encoded function returns the Huffman coding values along with a formatted list of all the characters and their frequencies.



# Functions | Structures
## struct node

``This structure is meant to represent a node, accepting both the character and the frequency along with two pointers representing left and right nodes.``

## struct cmpr

``use to compare two distinct nodes within the priority queue``

## code( struct node* root, string datastr)

``Recursive function that traverses the node; it takes in the node parameters and stores that information for the current node.``

## encode(char data[], int freq[], int sizedata)

``Accepts two arrays and an integer , to build the Huffman coding tree our encode function takes two nodes with the lowest frequency and creates a new node. This process will continue until there is only one node left in the priority queue.``

## CharValFreq(string str, bool extraCredit)

``The following function accepts a string sequence, with the use of vectors we can utilize dynamic arrays to store both the characters and frequencies in two different arrays with the added functionality of being able to append into both arrays. Our function is also case sensitive allowing us to also calculate values for uppercase letters.``

## main()

``Our main function is the initial start of our program, in this section we utilize our function charValFreq() first to calculate the frequencies of the character then convert the two separate dynamic arrays into vectors. Then, we convert them to usable standard arrays that we can insert into our encode function to perform the Huffman coding operation. Finally, the program returns the output for each character and its respective bit representation.``

# Example 
![image](https://user-images.githubusercontent.com/43622167/232914027-6ee31960-d045-4eb8-b3ab-fafb9f361486.png)

