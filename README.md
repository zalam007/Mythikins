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

 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:

 >     * What SOLID principle(s) did you apply?
 > 
 >      We applied the Dependency Inversion Principle with our item class that is contained in our character class.
 >      Instead of hard-coding the different items that is included in our game, we instead opted for an abstract class so we can store the different types of items
 >      and storing the behavior in the item itself.
 >
 >       We applied the Single Responsibilty Principle with our separation of our menu classes and the classes they depend on.
 >
 >       We applied the Interface-Segregation Principle through our Battle class. 
 >
 >      * How did you apply it? i.e. describe the change.
 >       We implemented a vector of item pointers such that polymorphism will handle the function calls of the different types of objects that the class stores.
 >
 >       For the SRP, we created menu classes to handle outputs to the console and act as drivers for the underlying classes that handle the calculations.
 >
 >       Before we changed the class, we would have functions inside the battle class that would not work for certain types of battles, with functions that weren't applicable to the different types of battle.
 >       By implementing a derived class we can have battle be applicable to all battles and add on different functions for battles that require more functions. 
 >       
 >     * How did this change help you write better code?
 >       By implementing the vector of pointers, we can store the functionality of an item inside the item itself which allows for more modular, cleaner, and more extensible code.
 >
 >       By adding menu classes we can have less confusing classes with regards to their function, where the menus always handle output and calls the classes they depend on rather than having a class that handles unclearly handles both.
> 
>       By separating the different functions for battle, we can avoid having to implement a different case within the function depending on whether the battle was with an NPC or not which allows for cleaner less confusing code.
>
>         
>        
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
