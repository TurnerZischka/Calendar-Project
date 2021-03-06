  
# Scheduler for da Cool Kids
 
  Authors:   \<[Turner Zischka](https://github.com/TurnerZischka)\>  \<[Austin Lee](https://github.com/austinslee)\> \<[Aly Refaat](https://github.com/Sebesky)\>
 

 
## Project Description
  ## Phase I
  Our project is intended to be a task scheduler with GUI. Our hope is to create a tool that each one of use would want to use in our daily life. Obviously we want to get stuff done, this tool should help with that. Important too is the fact that this is a useful project, while the other suggested projects are games. Games are a popular stable for CS projects, but only a portion of the possible jobs for CS are game devs, in fact some of the worst jobs are game dev jobs. This is meant to be a more helpful tool that allows us to have a stronger resume/portfolio for non-gamedev jobs. 
   * In this application, a user can create tasks including a title, description,
classification (e.g. personal, work, study), start time, and end time. Some of these
features can also be optional. Users can also create task lists where each list includes
multiple tasks. Task lists can represent larger tasks that have subtasks within them.
Users can display, edit, and delete tasks and task lists. Users should also be able to
undo these operations.
 
  * Design Patterns Patterns to use
    * Strategy
       * We plan to utilize the Strategy design pattern in order to help implement the display. The program's display is made up of a base class called cell which dictates how the boxes creating the display will look like and based on the tasks scheduled the program will choose a different strategy in order to create different sized boxes. We think this pattern will be a good fit for our program because different sized tasks require different sized boxes and the program has no way of knowing what size to make the box. Through the use of the strategy design pattern, we can create a method that allows the program to choose from different designs to create the correct display.
    * Composite
       * We want to implement a list output of all events a user has entered into their schedule. The user can add events to days, or to weeks, and should be able to output all of them. This pattern is useful because it allows us to nests tasks within tasks, and have them displayed under one command of an interface. Also, this would allow us to create subtasks to tasks, a representation of tasks within a goal. This is a good choice for exactly that nesting puropse. Objects of the same type can be contained with one another, and treated uniformly by an interface. 
    * Command
       * We plan to utilize the Command design pattern in order to implement a menu system to add, remove, and edit tasks. We will create an interface where the user can interact with the menu items which will be tied to a specific command and when that menu item is selected by the user, a command or sequence of commands will be executed. We think this pattern will be a good fit for this feature because the pattern is kind of designed to implement menus and can easily be used for the purpose of our program.
             
  * Programming Languages in use
    * C++
  * Tools in Use
    * [GTest](https://github.com/google/googletest) - used to test functionality of our program before full completion of our program. Useful also for testing first programming. 
    * [Valgrind](https://www.valgrind.org/) - Primarily the Memcheck tool to identify any possible programming errors and memory mismanagements
  * Inputs
    * User data - from menu
    * User data - from textual inputs
  * Outputs
    * Graphical Display
       * Can be changed with menu options which affect terminal display
 


  ## Phase II
## Class Diagram
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Entire.png)
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Composite%20(2).png)
   The diagram above shows how we will be utilizing the composite design pattern to implement the calendar tasks hierarchy. For our program, the Calendar/Timed Moment Hierarchy class would have the properties startTime, EndTime, TotalTime, description, title, and classification to represent the properties in a task and would serve as the base class for the Task and Subtask class. The Calendar/Timed Moment Hierarchy class would also act as the component. The Task class would act as the composite and would store subtasks and have the ability to add and remove subtasks. The subtasks would act as the leaf. The Control class will act as the client and will be able to use the composite design pattern to add and remove tasks.
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Command.png)
   The command pattern is utilized in our project to implement the menu interface in the calendar. Users will be able to select cells in  the calendar which have tasks assigned to them. This will open a menu which allows them to edit the different aspects of the task such as the date, time, title, and classification. The pattern is implemented through the cell object, which contains a vector of menu items. While this will initially be empty, if a menu item is selected, a new menu item object will be appended to a menu items vector. When a menu item object is created, it will be constructed with an object which inherits from the command abstract base class. These concrete commands will execute the functions contained in the task composite hierarchy.

  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Strategy.png)
  The base of this pattern is the Control. The control class will be used for many other purposes. Specific to the strategy pattern is reference to a Display class. Since week special is the only implementation of the Abstract Display, control will have reference to a Week Spatial. Control will be able to call the Display redraw function, which will then decide how to print the events insight of a list of composite classes, and then utilize the strategy itself to ensure that there will be proper printing of the cells as the calendar is printed to the screen. To better understand our use of Cell, imagine a typical weekly calendar. The days are represented as separate rows, and different events occur down each row. A cell will represent a 60 minute interval within a day. There will be 24 total cells for a day and 168 cells for a week. Each cell will be accounted for within the display class. To accommodate the different ways a cell will be one of the different implementations which will have all cells printed with a different look. This is the basis of the strategy pattern. When the redraw function is called. The fixed number of cells will be all assigned a cell type, and some information, and then as it is printed, will be printed according to its own print function drawCell().
  
 



 
 ## Screenshots
  After running the program, you will be presented with two options. Press 'a' to add a task, or press 'c' to display the calendar. Once the calendar is displayed, you are free to add tasks as you wish by pressing a. Shown below is an empty calendar with no added tasks.
  ![image](https://user-images.githubusercontent.com/67076046/111001292-5e64be80-8338-11eb-9d7a-f72ea61e1cb1.png)
  When you add a task, you will be prompted to enter information regarding this task, such as a title, description, start time, and end time. Once the task is added, you will immediately see it reflected in the calendar as a blue cell. 
  ![image](https://user-images.githubusercontent.com/67076046/111001570-e64ac880-8338-11eb-8911-160ad6063897.png)
  You can navigate the calendar's cells using the arrow keys. To edit a task, use the arrow keys to select it, and press enter.
  ![image](https://user-images.githubusercontent.com/67076046/111001649-0b3f3b80-8339-11eb-9258-a6419cab359f.png)
  Once enter is pressed, a sub menu will open which allows you to edit information about the task, or delete the task entirely. You can navigate through these options with arrow keys, and select them with enter. Any changes made to the title, start time, or end time, will immediately reflect in the calendar display. Deleting the task will remove it from the display entirely. If you wish to exit the menu without making changes, press 'b' to navigate back to the calendar.
  ![image](https://user-images.githubusercontent.com/67076046/111001890-6d983c00-8339-11eb-94dd-a491b388ddb2.png)
![image](https://user-images.githubusercontent.com/67076046/111001994-8143a280-8339-11eb-9d01-e8b28d8260aa.png)
If you are done using the program, press 'q' to quit.




 ## Installation/Usage
 This program is intended for use on Linux operating systems. To install it, clone the repository. Once this is done, enter the following command to generate the executable file:
 ``` cmake . && make ```
 To run the program, enter:
 ``` clear && ./calendar ```
 Once this is done, the program will run and it can be used accordingly.
  
 ## Testing
 For testing our program, we used googletests. We created unit tests for most of the functions in each of the major parts to make sure that they were fully functional and worked as intended. In total, we have 91 unit tests. 40 for the cell classes, 25 for the display classes, 5 for the composite hierarchy, 17 for the command classes, and 4 for the control classes.


<details>
  <summary>Click to see tests</summary>
  
  ![cs100 test 1](https://user-images.githubusercontent.com/55814421/110999865-e7c6c180-8335-11eb-94d2-0f9435622b7f.png)
  
![cs100 test2](https://user-images.githubusercontent.com/55814421/110999872-e9908500-8335-11eb-9afe-429277e82aa1.png)

![cs100 test3](https://user-images.githubusercontent.com/55814421/110999875-eac1b200-8335-11eb-8d0e-2f216b42a436.png)

![cs100 test4](https://user-images.githubusercontent.com/55814421/110999878-ebf2df00-8335-11eb-9de3-2cf9275fa07c.png)

![cs100 test5](https://user-images.githubusercontent.com/55814421/110999884-ed240c00-8335-11eb-941d-d320af887577.png)

</details>


We also used Valgrind to make sure there were no memory leaks or errors in the program. Running valgrind --leak-check=full --track-origins=yes ./calendar will give us All heap blocks were freed -- no leaks are possible and ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


![CS100 project valgrind check](https://user-images.githubusercontent.com/55814421/110886687-e5188d80-829d-11eb-9421-93c4e89e75ed.png)


 
