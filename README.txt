Theme: Nuclear Weapons/Terms

Datatypes:
    - Integer:  Tsar
    - Long:     Trinity
    - Float:    LittleBoy
    - Double:   FatMan
    - Boolean:  Fallout
    - Char:     Fission
    - String:   Fusion

Memory:
    Memory is split into many different sub Memory objects inside of a namespace called MyMemory.
    Each sub object has a map that contains an int for a key, and a value based on the datatype.

CPU:

    Register:
        Inherits Memory, but contains an extra variable for flags.
        Instead of being stored in a namespace, the sub objects are inside of the CPU class.

    Operations:
        Move:
            - Loads a value from memory into the register
        Add:
            - Adds two values and stores the result in the register, then computes the operation, and rewrites the value into the first address.
        Subtract:
            - Subtracts two values and stores the result in the register, then computes the operation, and rewrites the value into the first address.
        Multiply:
            - Multiplies two values and stores the result in the register, then computes the operation, and rewrites the value into the first address.
        Divide:
            - Divides two values and stores the result in the register, then computes the operation, and rewrites the value into the first address.
        Compare:
            - Subtracts the second value from the first one, and stores it as a flag in the register.
        Push:
            - Adds data into memory/register
        Pop:
            - Removes data from memory/register 
            
Thoughts:
	
    Minor Problems:
        I ran into an issue where my theme objects couldn't be assigned in the following
        syntax:
            Tsar tsar = 5;
        I had to use the internet to figure out why, and I found out that I only overloaded
        the assignment operator, and this syntax counts as an initializing operator. Therefore
        I had to call the &operator= overloaded function in a constructor that took an integer
        value.

        I also had to use AI to figure out how to properly do separate compilation for a namespace
        using the extern keyword.

    Major Problem:
        My main problem was figuring out how to store different data types in one map...
        At first, I wasn't able to do it, which led me to refactor my system a bit, and although
        I managed to achieve that result... I ran into a problem where I had a lot of issues 
        reading/writing data correctly. I then tried to bugfix some of my code by myself, but 
        I quickly gave up due to time constraints, so I used AI -- My biggest mistake --
        ChatGPT & DeepSeek both spit out such garbage code, that I spent 3 hours trying to 
        fix an issue, only to create 10 more. Thats when I quickly gave up on that idea,
        went back to my 30% submission files, and used what I learned so far into creating
        a system that works(kind of).
        Unfortunately I ran out of time, so I could not finish what I set out to do, and
        although it was stressful, it was still enjoyable(kind of).

    

