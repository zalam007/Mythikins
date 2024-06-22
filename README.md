# \<Mythikins: The RPG Adventure\>
 
 > Authors: \<[Zami Alam](https://github.com/zalam007)\>
 > \<[Jesse Nguyen](https://github.com/madjick1)\>
 > \<[Dylan Wong](https://github.com/dylanwong6605)\>
 > \<[Axel Perez](https://github.com/AxelPere)\>
 >
## Project Description
 > Mythikins is a text-based RPG adventure inspired by the classic game Pokemon with our unique take on the genre. Players can capture and train Mythikins of 3 types: aqua, magma, and flora, each with elemental moves. The player can move between areas, such as the starting 
 village, routes (filled with Mythikins & trainers), and cities each with an academy, store, and Mythikin center. The player can battle other 
 trainers, and academy-masters to earn medallions. After receiving three medallions you can fight the Four Myth Masters to become the ultimate 
 master.
 >
 > 
 >  We will be using: 
 > * Programming Language: C++ 
 > * IDE: Visual Studio Code
 > * Version Control: Git
 > * Repository: Github

 > Input: Players will interact with the game using text commands using a menu
 > * Navigating through map areas 
 > * Using items
 > * Checking their stats
 > * Organizing their inventory
 > In battle, the user will be prompted with four options to attack, items, flee, and swap.

 > Output:  The output will be a linear narrative progressing as the user defeats the academy masters. At every step, the user will be prompted with a menu that presents their traveling options.
>
> In battle, the user will be presented with four options to attack, items, swap, and flee.
 > * Attack will output the possible attacks that the user can use, each with different effects.
 > * Items will output a list of possible items that can be used.
 > * Flee will output success or failure.
 > * Swap will prompt for which Mythikin to swap with.

 ## UML
 ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/146038030/200bdec9-e415-45bc-9b85-3dbae2bf84ca)
 > * https://drive.google.com/file/d/16k-MWYpmxMWjBg1lDiRgTIJrvTYjwJw3/view?usp=sharing

 ## Layout + Navigation Diagram
![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/146377680/3b584628-510a-4e18-966a-ce61cabd387f)
 > * https://drive.google.com/file/d/1a7bPom0_qHQpSoHAy5gg0hrQ4rfgjSmB/view?usp=sharing
 >

 
 > ## Phase III (New S.O.L.I.D. UML)
 >
 > https://drive.google.com/file/d/16k-MWYpmxMWjBg1lDiRgTIJrvTYjwJw3/view?usp=sharing
 >
> ![Screenshot 2024-06-07 001955](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/134023272/74e3d6dd-5e62-4fb2-9563-cc4350fda04b)
> ![Screenshot 2024-06-07 002018](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/134023272/69bd20cc-895d-4c10-ade4-000f9b789cb8)
> ![Screenshot 2024-06-07 002036](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/134023272/8d01f76e-de39-4179-8532-b76cc40836a5)

 >     * SOLID principle(s) applied.
 >
 >       (S) We applied the Single Responsibilty Principle with our separation of our menu classes and the classes they depend on.
 >
 >       (O) We appled the Open-closed principle with our Character class where it has items. The items can be added on, and you don't need to modify the class for new items.
 >
 >       (L) We applied the Liskov Subsitution Principle for the Battle class.
 >
 >       (I) We applied the Interface-Segregation Principle through our Battle class.
 >
 >      (D) We applied the Dependency Inversion Principle with our item class that is contained in our character class.
 >      Instead of hard-coding the different items that is included in our game, we instead opted for an abstract class so we can store the different types of items and storing the behavior in the item itself.

 >      * How we applied it.
 >
 >       (S) For the SRP, we created menu classes to handle outputs to the console and act as drivers for the underlying classes that handle the calculations.
 >
 >       (O) We had to character class store a vector of items. The item class is a virtual function that allows for different child classes to be created and added to the vector. Subclasses include Mythicube and Potions. 
 > 
 >        (L) We created the wildBattle subclass that derives from Battle class. It takes all the functions and attributes from Battle class making it perfectly substitute that class.
 >
 >       (I) Before we changed the class, we would have functions inside the battle class that would not work for certain types of battles, with functions that didn't apply to the different types of battles. By implementing a derived class we can have battle be applicable to all battles and add on different functions for battles that require more functions.
 >
 >       (D) We implemented a vector of item pointers such that polymorphism will handle the function calls of the different types of objects that the class stores.

 >      
 >     * How this helped write better code.
 >
 >       (S) By adding menu classes we can have less confusing classes with regards to their function, where the menus always handle output and calls the classes they depend on rather than having a class that handles unclearly handles both.
 >
 >       (O) This helps our code as without it we would have to create multiple vectors in the character class which each different items. 
 > 
 >       (L) By making it so our team does not need to waste time making unnecessary function calls or checks for battle cases that do not need certain functions. In addition, it makes organization easier.
 >
 >       (I) By separating the different functions for battle, we can avoid having to implement a different case within the function depending on whether the battle was with an NPC or not which allows for cleaner less confusing code.
 > 
 >       (D) By implementing the vector of pointers, we can store the functionality of an item inside the item itself which allows for more modular, cleaner, and more extensible code. 

 
 ## Screenshots
 > Screenshots of the input/output after running your application
> ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/157668326/8168753f-7844-4f1c-af10-53190ab75285)
> ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/157668326/5ebf4038-6358-4531-a153-cbfe57aa6a75)
> ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/157668326/6f5804d0-73af-49a2-a5fd-d841c2e8f1b8)
> ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/157668326/1159220e-ae83-4ead-84b4-fdbc2b106627)
> ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/157668326/41659cd2-f393-4637-b38a-5606f7d38811)
> ![image](https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133/assets/157668326/cdbbf053-1e91-4a4e-bcfd-2a65c17861e5)






 ## Installation/Usage
 > Installation: Run "git clone --recursive https://github.com/cs100/final-project-zalam007-apere594-jnguy887-dwong133.git" in a bash terminal
> 
 > In the terminal, run "g++ demoMain.cpp src/*.cpp -o MythikinDemo" to compile the game.
>
 > Run "./MythikinDemo" to run the executable"
> 
 ## Testing
 > Our project was tested initially with small tests within the branch with basic tests in dummy mains, and as we began to integrate our branches, we wrote Unit tests with the google test framework and ran tests in our main branch to ensure that each of classes integrated properly.
 >
 > We each created unit tests in our own branches and upon merging these tests with the main branch, edited the CMakeList.txt file to create separate executables for each of our test suites.
 
