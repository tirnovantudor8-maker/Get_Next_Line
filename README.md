*This project has been created as part of the 42 curriculum by titudor.*

# Get Next Line

## Description
The **Get Next Line** project is a fundamental challenge in the 42 curriculum that requires creating a function capable of reading a file descriptor line by line. The primary goal is to manage memory efficiently while dealing with a `BUFFER_SIZE` that can be modified at compile time. This project introduces the critical concept of **static variables**, which allow a function to "remember" data between successive calls, ensuring no data is lost during the reading process.

## Instructions

### Compilation
The project must be compiled with the flag -D BUFFER_SIZE=x. You can use the following command to compile the source files along with a test main.c:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl

### Execution
Once compiled, run the executable:
./gnl

### Cleaning
To remove the executable:
rm gnl

## Algorithm & Implementation
The algorithm selected for this project follows a "Read-Stash-Extract" pattern to ensure data integrity:

1. Reading and Stashing: The function uses a static char * variable (the "stash") to store any data read from the file descriptor that hasn't been returned yet. We use a loop to call read() until either a newline character (\n) is found in the stash or the end of the file (EOF) is reached.
2. Joining Chunks: During each iteration of the read loop, we use a specialized join function that concatenates the current stash with the newly read buffer. Crucially, this function frees the old stash memory before returning the new pointer to prevent memory leaks.
3. Extraction: Once a newline is detected, we calculate the length from the start of the stash to the \n. We malloc space to copy this line (including the newline and a null terminator) and return it to the user.
4. Trimming: Before the function returns, the static stash is updated. We keep only the characters that appeared after the newline we just returned. The old version of the stash is freed, and the new "remainder" is saved for the next call.

Justification: This algorithm was chosen because it is highly robust against varying BUFFER_SIZE values. By using a static pointer, we ensure that the "overflow" from a read() call is never lost, and by strictly following a "free-before-reassign" pattern, we maintain a 0-leak memory profile.

## Resources
- GNU C Library Documentation (Glibc).
- Unix Manual Pages: man 2 read, man 2 open, man 2 close.
- Standard C Programming Tutorials (C Programming Language - K&R).

### AI Usage Disclosure
I used AI tools during this project for the following tasks:
- Structure & Logic: Assisting in the conceptual organization of the main loop and memory management flow.
- Documentation: Drafting and formatting the project's README file to meet the curriculum's requirements.