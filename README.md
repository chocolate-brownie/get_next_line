**Project Overview:**
The Get_Next_Line (GNL) project at École 42 focuses on developing a function that reads a line from a file descriptor, providing students with practical experience in dynamic memory allocation, buffer management, and the use of static variables in C programming.

**Goals:**
The primary objective is to create a convenient function for reading lines from a file descriptor while learning about static variables. The project helps in understanding how to manage memory dynamically and handle various edge cases in file reading.

**Common Instructions:**
The project must be written in C and adhere to the École 42 Norm. Functions should handle errors gracefully, avoiding unexpected crashes such as segmentation faults or double frees. All dynamically allocated memory must be freed properly to prevent leaks. A Makefile is required, which includes specific rules such as `all`, `clean`, `fclean`, `re`, and `bonus`. Testing programs are encouraged to ensure functionality and aid in peer evaluations. The final submission must be made through the assigned Git repository.

**Mandatory Part:**
Students need to implement the `get_next_line` function with the prototype `char *get_next_line(int fd);`. This function reads and returns one line at a time from the file descriptor. It should handle both standard input and file reading, including the newline character in the returned line unless the end of the file is reached. The function relies on `read`, `malloc`, and `free`, and should handle various buffer sizes defined by the `-D BUFFER_SIZE=n` compiler flag. Undefined behavior must be avoided if the file changes between reads or when reading binary files.

**Bonus Part:**
The bonus part extends the function to manage multiple file descriptors simultaneously using a single static variable. This requires careful handling to maintain separate states for each file descriptor. Additional files for the bonus part include `get_next_line_bonus.c`, `get_next_line_bonus.h`, and `get_next_line_utils_bonus.c`. The bonus will only be evaluated if the mandatory part is perfectly implemented.

### Approach to Get_Next_Line with Linked Lists

Using linked lists to implement the Get_Next_Line (GNL) function can be an effective strategy to manage buffers dynamically and handle variable line lengths efficiently. Here's a step-by-step approach to solving this problem using linked lists:

1. **Initialize Data Structures:**
   - Create a node structure for the linked list. Each node will store a portion of the line read from the file and a pointer to the next node.
   - Define a head pointer for the linked list to keep track of the beginning of the line data and a tail pointer to append new data easily.

2. **Reading from the File Descriptor:**
   - Use the `read` function to read data from the file descriptor into a buffer.
   - For each read operation, store the data in a new node and link it to the existing list.

3. **Handling Line Breaks:**
   - As you read data, check for newline characters (`\n`).
   - If a newline is found, it indicates the end of the current line. Store the remaining part of the buffer in the list and prepare to return the line.

4. **Extracting the Line:**
   - Traverse the linked list to concatenate the data into a single string representing the line.
   - Return the constructed line and free the nodes used for this line.

5. **Managing Multiple File Descriptors:**
   - Use a structure to manage multiple linked lists, one for each file descriptor.
   - Ensure each file descriptor maintains its own state, including the head and tail pointers of its linked list.

6. **Memory Management:**
   - Properly allocate and free memory for each node in the linked list to avoid memory leaks.
   - After returning a line, ensure the nodes used for that line are freed, and the list is updated for subsequent reads.

**Resources:**
   - Understanding the subject : https://medium.com/@lannur-s/42-get-next-line-guide-string-approach-chapter-3-understanding-the-subject-5101454806ce
   - All the other resources : https://suspectedoceano.notion.site/get_next_line-b3fa44d60dc24817bfd6a642183a93a0
   - Linked list manipulation : https://www.programiz.com/dsa/linked-list-operations
   - Linked list tutorial : https://www.learn-c.org/en/Linked_lists

**Result:**
![Screenshot from 2024-07-16 15-43-46](https://github.com/user-attachments/assets/922355dd-0c15-49e1-9b37-6611f3855b8c)
